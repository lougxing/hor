class Solution {
	private:
		vector<vector<int>> result;
		vector<int> path;
		void backtracking(int n, int k, int startIndex) {
			if (path.size() == k) {
				result.push_back(path);
				return;
			}
			for (int i = startIndex; i <= n - (k - path.size()) + 1; i++) {
				的地⽅
					path.push_back(i);
				backtracking(n, k, i + 1);
				path.pop_back();
			}
		}
	public:
		vector<vector<int>> combine(int n, int k) {
			backtracking(n, k, 1);
			return result;
		}
};

class Solution {
	private:
		vector<vector<int>> result;
		vector<int> path;
		void backtracking(int targetSum, int k, int sum, int startIndex) {
			if (sum > targetSum) { // 剪枝操作
				return;
			}
			if (path.size() == k) {
				if (sum == targetSum) result.push_back(path);
				return;
			}
			for (int i = startIndex; i <= 9 - (k - path.size()) + 1; i++) {
				sum += i;
				path.push_back(i);
				backtracking(targetSum, k, sum, i + 1);
				sum -= i;
				path.pop_back();
			}

		}
	public:
		vector<vector<int>> combinationSum3(int k, int n) {
			result.clear();
			path.clear();
			backtracking(n, k, 0, 1);
			return result;
		}
};

class Solution {
	private:
		const string letterMap[10] = {
			"",
			"",
			"abc",
			"def",
			"ghi",
			"jkl",
			"mno",
			"pqrs",
			"tuv",
			"wxyz",
		};
	public:
		vector<string> result;
		string s;
		void backtracking(const string& digits, int index) {
			if (index == digits.size()) {
				result.push_back(s);
				return;
			}
			int digit = digits[index] - '0';
			string letters = letterMap[digit];
			for (int i = 0; i < letters.size(); i++) {
				s.push_back(letters[i]);
				backtracking(digits, index + 1);
				s.pop_back(); // 回溯
			}
		}
		vector<string> letterCombinations(string digits) {
			s.clear();
			result.clear();
			if (digits.size() == 0) {
				return result;
			}
			backtracking(digits, 0);
			return result;
		}
};

class Solution {
	private:
		vector<int> path;
		vector<vector<int>> result;
		void backtracking(vector<int>& candidates, int target, int sum, int startIndex) {
			if (sum > target) {
				return;
			}
			if (sum == target) {
				result.push_back(path);
				return;
			}
			for (int i = startIndex; i < candidates.size(); i++) {
				sum += candidates[i];
				path.push_back(candidates[i]);
				backtracking(candidates, target, sum, i);
				sum -= candidates[i];
				path.pop_back();
			}
		}
	public:
		vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
			path.clear();
			result.clear();
			backtracking(candidates, target, 0, 0);
			return result;
		}
};

class Solution {
	private:
		vector<int> path;
		vector<vector<int>> result;
		void backtracking(vector<int>& candidates, int target, int sum, int startIndex) {
			if (sum == target) {
				result.push_back(path);
				return;
			}
			for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++) {
				sum += candidates[i];
				path.push_back(candidates[i]);
				backtracking(candidates, target, sum, i);
				sum -= candidates[i];
				path.pop_back();
			}
		}
	public:
		vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
			path.clear();
			result.clear();
			sort(candidates.begin(), candidates.end());
			backtracking(candidates, target, 0, 0);
			return result;
		}
};

class Solution {
	private:
		vector<int> path;
		vector<vector<int>> result;
		void backtracking(vector<int>& candidates, int target, int sum, int startIndex, vector<bool>& used) {
			if (sum == target) {
				result.push_back(path);
				return;
			}

			for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++) {
				if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false) {
					continue;
				}
				sum += candidates[i];
				path.push_back(candidates[i]);
				used[i] = true;
				backtracking(candidates, target, sum, i + 1, used);
				used[i] = false;
				sum -= candidates[i];
				path.pop_back();
			}
		}
	public:
		vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

			vector<bool> used(candidates.size(), false);
			path.clear();
			result.clear();
			sort(candidates.begin(), candidates.end());
			backtracking(candidates, target, 0, 0, used);
			return result;
		}
};

class Solution {
	private:
		vector<string> path;
		vector<vector<string>> result;
		void backtracking (const string& s, int startIndex) {
			if (startIndex >= s.size()) {
				result.push_back(path);
				return;
			}
			for (int i = startIndex; i < s.size(); i++) {
				if (isPalindrome(s, startIndex, i)) {
					string str = s.substr(startIndex, i - startIndex + 1);
					path.push_back(str);
				} else {
					continue;
				}
				backtracking(s, i + 1);
				path.pop_back();
			}
		}
		bool isPalindrome(const string& s, int start, int end) {
			for (int i = start, j = end; i < j; i++, j--) {
				if (s[i] != s[j]) {
					return false;
				}
			}
			return true;
		}
	public:
		vector<vector<string>> partition(string s) {
			path.clear();
			result.clear();
			backtracking(s, 0);
			return result;
		}
};

class Solution {
	private:
		vector<string> result;
		void backtracking(string& s, int startIndex, int pointNum) {
			if (pointNum == 3) {
				if (isValid(s, startIndex, s.size() - 1)) {
					result.push_back(s);
				}
				return;
			}
			for (int i = startIndex; i < s.size(); i++) {
				if (isValid(s, startIndex, i)) {
					s.insert(s.begin() + i + 1 , '.');
					pointNum++;
					backtracking(s, i + 2, pointNum);
					pointNum--;
					s.erase(s.begin() + i + 1);
				} else break;
			}
		}

		bool isValid(const string& s, int start, int end) {
			if (start > end) {
				return false;
			}
			if (s[start] == '0' && start != end) {
				return false;
			}
			int num = 0;
			for (int i = start; i <= end; i++) {
				if (s[i] > '9' || s[i] < '0') {
					return false;
				}
				num = num * 10 + (s[i] - '0');
				if (num > 255) {
					return false;
				}
			}
			return true;
		}
	public:
		vector<string> restoreIpAddresses(string s) {
			result.clear();
			if (s.size() > 12) return result;
			backtracking(s, 0, 0);
			return result;
		}
};

class Solution {
	private:
		vector<vector<int>> result;
		vector<int> path;
		void backtracking(vector<int>& nums, int startIndex) {
			result.push_back(path);
			if (startIndex >= nums.size()) {
				return;
			}
			for (int i = startIndex; i < nums.size(); i++) {
				path.push_back(nums[i]);
				backtracking(nums, i + 1);
				path.pop_back();
			}
		}
	public:
		vector<vector<int>> subsets(vector<int>& nums) {
			result.clear();
			path.clear();
			backtracking(nums, 0);
			return result;
		}
};

class Solution {

	private:
		vector<int> path;
		vector<vector<int>> result;
		void backtracking(vector<int>& nums, int startIndex) {
			if (path.size() > 1) {
				result.push_back(path);
			}
			int used[201] = {0};
			for (int i = startIndex; i < nums.size(); i++) {
				if ((!path.empty() && nums[i] < path.back()) || used[nums[i] + 100] == 1) {
					continue;
				}
				used[nums[i] + 100] = 1;
				path.push_back(nums[i]);
				backtracking(nums, i + 1);
				path.pop_back();
			}
		}
	public:
		vector<vector<int>> findSubsequences(vector<int>& nums) {
			result.clear();
			path.clear();
			backtracking(nums, 0);
			return result;
		}
};

class Solution {
	public:
		vector<int> path;
		vector<vector<int>> result;
		void backtracking (vector<int>& nums, vector<bool>& used) {
			if (path.size() == nums.size()) {
				result.push_back(path);
				return;
			}
			for (int i = 0; i < nums.size(); i++) {
				if (used[i] == true) continue;
				used[i] = true;
				path.push_back(nums[i]);
				backtracking(nums, used);
				path.pop_back();
				used[i] = false;

			}
		}
		vector<vector<int>> permute(vector<int>& nums) {
			result.clear();
			path.clear();
			vector<bool> used(nums.size(), false);
			backtracking(nums, used);
			return result;
		}
};

class Solution {
	private:
		vector<vector<int>> result;
		vector<int> path;
		void backtracking (vector<int>& nums, vector<bool>& used) {
			if (path.size() == nums.size()) {
				result.push_back(path);
				return;
			}
			for (int i = 0; i < nums.size(); i++) {
				if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
					continue;
				}
				if (used[i] == true) continue;

				used[i] = true;
				path.push_back(nums[i]);
				backtracking(nums, used);
				path.pop_back();
				used[i] = false;
			}
		}
	public:
		vector<vector<int>> permuteUnique(vector<int>& nums) {
			result.clear();
			path.clear();
			sort(nums.begin(), nums.end());
			vector<bool> used(nums.size(), false);
			backtracking(nums, vec, used);
			return result;
		}
};

class Solution {
	private:
		unordered_map<string, map<string, int>> targets;
		bool backtracking(int ticketNum, vector<string>& result) {
			if (result.size() == ticketNum + 1) {
				return true;
			}
			for (pair<const string, int>& target : targets[result[result.size() - 1]]) {
				if (target.second > 0 ) {
					result.push_back(target.first);
					target.second--;
					if (backtracking(ticketNum, result)) return true;
					result.pop_back();
					target.second++;
				}
			}
			return false;
		}
	public:
		vector<string> findItinerary(vector<vector<string>>& tickets) {
			targets.clear();
			vector<string> result;
			for (const vector<string>& vec : tickets) {
				targets[vec[0]][vec[1]]++;
			}
			result.push_back("JFK");
			backtracking(tickets.size(), result);
			return result;
		}
};

class Solution {
	private:
		vector<vector<string>> result;
		void backtracking(int n, int row, vector<string>& chessboard) {
			if (row == n) {
				result.push_back(chessboard);
				return;
			}
			for (int col = 0; col < n; col++) {
				if (isValid(row, col, chessboard, n)) {
					chessboard[row][col] = 'Q';
					backtracking(n, row + 1, chessboard);
					chessboard[row][col] = '.';
				}
			}
		}
		bool isValid(int row, int col, vector<string>& chessboard, int n) {
			int count = 0;
			for (int i = 0; i < row; i++) {
				if (chessboard[i][col] == 'Q') {
					return false;
				}
			}
			for (int i = row - 1, j = col - 1; i >=0 && j >= 0; i--, j--) {
				if (chessboard[i][j] == 'Q') {
					return false;
				}
			}
			for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
				if (chessboard[i][j] == 'Q') {
					return false;
				}
			}
			return true;
		}
	public:
		vector<vector<string>> solveNQueens(int n) {
			result.clear();
			std::vector<std::string> chessboard(n, std::string(n, '.'));
			backtracking(n, 0, chessboard);
			return result;
		}
};

class Solution {
	private:
		bool backtracking(vector<vector<char>>& board) {
			for (int i = 0; i < board.size(); i++) {
				for (int j = 0; j < board[0].size(); j++) {
					if (board[i][j] != '.') continue;
					for (char k = '1'; k <= '9'; k++) {
						if (isValid(i, j, k, board)) {
							board[i][j] = k;
							if (backtracking(board)) return true;
							返回
								board[i][j] = '.';
						}
					}
					return false;
					就返回false
				}
			}
			return true;
		}
		bool isValid(int row, int col, char val, vector<vector<char>>& board) {
			for (int i = 0; i < 9; i++) {
				if (board[row][i] == val) {
					return false;
				}
			}
			for (int j = 0; j < 9; j++) {
				if (board[j][col] == val) {
					return false;
				}
			}
			int startRow = (row / 3) * 3;
			int startCol = (col / 3) * 3;
			for (int i = startRow; i < startRow + 3; i++) {

				for (int j = startCol; j < startCol + 3; j++) {
					if (board[i][j] == val ) {
						return false;
					}
				}
			}
			return true;
		}
	public:
		void solveSudoku(vector<vector<char>>& board) {
			backtracking(board);
		}
};
