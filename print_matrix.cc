
#include <string>
#include <vector>

struct PrintTable
{
    //Base data
    std::string title;
    std::vector<std::string> columnNames;
    std::vector<std::vector<std::string>> rows;
    bool startedAddingRows = false;
    bool alteredState = false;

    //Format data
    std::vector<int> maxColumnWidths;
    std::string fullDividerStr;
    std::string titleStr;
    std::string columnStr;
    std::vector<std::string> rowStrs;

    //Functions
    void SetTitle(const std::string& title);
    void AddColumn(const std::string& columnName);
    void AddRow(const std::vector<std::string>& row);
    void AddRows(const std::vector<std::vector<std::string>>& rows);
    void Print();
    void Reset();
};


void PrintTable::SetTitle(const std::string& title)
{
    this->title = title;
    alteredState = true;
}

void PrintTable::AddColumn(const std::string& columnName)
{
    if (startedAddingRows)
    {
        printf("Table '%s' already has rows added: additional columns cannot be added.\n", title.c_str());
        return;
    }
    columnNames.push_back(columnName);
    alteredState = true;
}

void PrintTable::AddRow(const std::vector<std::string>& row)
{
    if (row.size() != columnNames.size())
    {
        printf("Trying to add row with %lu elements while table '%s' requires %lu elements per row.\n", row.size(), title.c_str(), columnNames.size());
        return;
    }
    rows.push_back(row);
    startedAddingRows = true;
    alteredState = true;
}

void PrintTable::AddRows(const std::vector<std::vector<std::string>>& rows)
{
    for (const std::vector<std::string>& row : rows)
    {
        if (row.size() != columnNames.size())
        {
            printf("Trying to add row with %lu elements while table '%s' requires %lu elements per row.\n", row.size(), title.c_str(), columnNames.size());
        }
        this->rows.push_back(row);
    }
    startedAddingRows = true;
    alteredState = true;
}

void PrintTable::Print()
{
    if (title.empty() || columnNames.empty() || rows.empty())
    {
        printf("Missing some necessary data to print table:\n\tTitle: '%s' (must not be empty)\n\tNumber of columns: %lu (min=1)\n\tNumber of rows: %lu (min=1)\n", title.c_str(), columnNames.size(), rows.size());
        return;
    }
    if (alteredState)
    {
        // Find max width of each column
        maxColumnWidths.resize(columnNames.size());
        for (size_t i = 0; i < columnNames.size(); i++)
        {
            maxColumnWidths[i] = columnNames[i].length();
        }
        for (size_t r = 0; r < rows.size(); r++)
        {
            for (size_t c = 0; c < columnNames.size(); c++)
            {
                if (int(rows[r][c].length()) > maxColumnWidths[c])
                {
                    maxColumnWidths[c] = rows[r][c].length();
                }
            }
        }

        /*
        -------------------------------
        |          Test table         |
        -------------------------------
        | column0 | column1 | column2 |
        -------------------------------
        |  row0   |  row0   |  row0   |
        |-----------------------------|
        |  row1   |  row1   |  row1   |
        |-----------------------------|
        |  row2   |  row2   |  row2   |
        -------------------------------
        */
        int tableWidth = 0;
        for (const int& width : maxColumnWidths)
        {
            // +3 because it includes the space for the first |
            // and a space on each side of the column name (see above example)
            tableWidth += width + 3;
        }
        // Make space for the last |
        tableWidth += 1;
        fullDividerStr = std::string(tableWidth, '-');

        // Create string with title
        titleStr = "";
        {
            // Subtract 4 to ensure that the inital, and last, | and space are ignored
            const int lengthDiff = (tableWidth - 4) - title.length();
            // Divide by 2 to get number of pre spaces
            const int numPreSpace = lengthDiff / 2;
            // Divide by 2, but increment lengthDiff by one to round up.
            // I do this because I want extra spaces after the column name
            const int numPostSpace = (lengthDiff + 1) / 2;
            const std::string preStr(numPreSpace, ' ');
            const std::string postStr(numPostSpace, ' ');
            titleStr += "| " + preStr + title + postStr + " |";
        }

        // Create string with each column name
        columnStr = "";
        for (size_t i = 0; i < columnNames.size(); i++)
        {
            const std::string& columnName = columnNames[i];
            const int lengthDiff = maxColumnWidths[i] - columnName.length();
            if (lengthDiff > 0)
            {
                // Divide by 2 to get number of pre spaces
                const int numPreSpace = lengthDiff / 2;
                // Divide by 2, but increment lengthDiff by one to round up.
                // I do this because I want extra spaces after the column name
                const int numPostSpace = (lengthDiff + 1) / 2;
                const std::string preStr(numPreSpace, ' ');
                const std::string postStr(numPostSpace, ' ');
                columnStr += "| " + preStr + columnName + postStr + " ";
            }
            else
            {
                columnStr += "| " + columnName + " ";
            }
        }
        columnStr += "|";

        // Create string for each row and its elements
        rowStrs = std::vector<std::string>(rows.size());
        for (size_t r = 0; r < rows.size(); r++)
        {
            for (size_t e = 0; e < rows[r].size(); e++)
            {
                const std::string& elementData = rows[r][e];
                const int lengthDiff = maxColumnWidths[e] - elementData.length();
                // Divide by 2 to get number of pre spaces
                const int numPreSpace = lengthDiff / 2;
                // Divide by 2, but increment lengthDiff by one to round up.
                // I do this because I want extra spaces after the column name
                const int numPostSpace = (lengthDiff + 1) / 2;
                const std::string preStr(numPreSpace, ' ');
                const std::string postStr(numPostSpace, ' ');
                rowStrs[r] += "| " + preStr + elementData + postStr + " ";
            }
            rowStrs[r] += "|";
        }
    }

    // Print table
    printf("%s\n", fullDividerStr.c_str());
    printf("%s\n", titleStr.c_str());
    printf("%s\n", fullDividerStr.c_str());
    printf("%s\n", columnStr.c_str());
    printf("%s\n", fullDividerStr.c_str());
    for (const std::string& rowStr : rowStrs)
    {
        printf("%s\n", rowStr.c_str());
    }
    printf("%s\n", fullDividerStr.c_str());

    alteredState = false;
}

void PrintTable::Reset()
{
    title = "";
    columnNames.resize(0);
    rows.resize(0);
    maxColumnWidths.resize(0);
    startedAddingRows = false;
    alteredState = true;
}


int main(int argc, char**argv)
{
    PrintTable pt;
    pt.SetTitle("My Friends' Gaming GPUs");
//    pt.AddColumn("Vendor");
//    pt.AddColumn("GPU Name");
//    pt.AddColumn("Release Year");



    std::vector<std::vector<std::string>> rows = {
        {
            "Nvidia", "GTX 980 Ti", "2015"
        },
        {
            "Nvidia", "GTX 1070", "2016"
        },
        {
            "Nvidia", "GTX 1080", "2016"
        },
        {
            "Nvidia", "RTX 2080", "2018"
        }
    };

    auto itt = rows.begin();
    for(int i = 0; i < itt->size(); ++i) {
        pt.AddColumn(std::to_string(i));
    }

    pt.AddRows(rows);
    pt.Print();
    pt.Reset();
//    pt.Print();

    return 0;
}
