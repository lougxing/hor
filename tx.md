```c++
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int index = s.size() - 1;
        int result = 0;
        for (int i = g.size() - 1; i >= 0; i--) {
            if (index >= 0 && s[index] >= g[i]) {
                result++;
                index--;
            }
        }
        return result;
    }
};
````

```c++
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        int curDiff = 0;  
        int preDiff = 0;  
        int result = 1;
        for (int i = 0; i < nums.size() - 1; i++) {
            curDiff = nums[i + 1] - nums[i];
            if ((curDiff > 0 && preDiff <= 0) || (preDiff >= 0 && curDiff < 0))
            {
                result++;
                preDiff = curDiff;
            }
        }
        return result;
    }
};
````

```c++
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = INT32_MIN;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            count += nums[i];
            if (count > result) result = count; 
            if (count <= 0) count = 0;
        }
        return result;
    }
};
````

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        for (int i = 1; i < prices.size(); i++) {
            result += max(prices[i] - prices[i - 1], 0);
        }
        return result;
    }
};
````









```c++
class Solution {
    bool canJump(vector<int>& nums) {
        int cover = 0;
        if (nums.size() == 1) return true;
        for (int i = 0; i <= cover; i++) {
            cover = max(i + nums[i], cover);
            if (cover >= nums.size() - 1) return true;
        }
        return false;
    }
};
````

```c++
class Solution {
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int curDistance = 0, nextDistance = 0, ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            nextDistance = max(nums[i] + i, nextDistance);
            if (i == curDistance) {
                if (curDistance != nums.size() - 1) {
                    ans++; 
                    curDistance = nextDistance;
                    if (nextDistance >= nums.size() - 1) break;
                } else break; 
            }
        }
        return ans;
    }
};
````

```c++
class Solution {
    int jump(vector<int>& nums) {
        int curDistance = 0, nextDistance = 0, ans = 0;
        for (int i = 0; i < nums.size() - 1; i++) { 
            nextDistance = max(nums[i] + i, nextDistance);
            if (i == curDistance) {
                curDistance = nextDistance;
                ans++;
            }
        }
        return ans;
    }
};
````

```c++
class Solution {
    static bool cmp(int a, int b) { return abs(a) > abs(b); }
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(), A.end(), cmp);
        for (int i = 0; i < A.size(); i++) {
            if (A[i] < 0 && K > 0) {
                A[i] *= -1;
                K--;
            }
        }
        if (K % 2 == 1) A[A.size() - 1] *= -1;
        int result = 0;
        for (int a : A) result += a;
        return result;
    }
};
````







```c++
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curSum = 0;
        int min = INT_MAX;
        for (int i = 0; i < gas.size(); i++) {
            int rest = gas[i] - cost[i];
            curSum += rest;
            if (curSum < min) {
                min = curSum;
            }
        }
        if (curSum < 0) return -1;
        if (min >= 0) return 0;
        for (int i = gas.size() - 1; i >= 0; i--) {
            int rest = gas[i] - cost[i];
            min += rest;
            if (min >= 0) {
                return i;
            }
        }
        return -1;
    }
};
````

```c++
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curSum = 0;
        int totalSum = 0;
        int start = 0;
        for (int i = 0; i < gas.size(); i++) {
            curSum += gas[i] - cost[i];
            totalSum += gas[i] - cost[i];
            if (curSum < 0) { 
                start = i + 1;
                curSum = 0;
            }
        }
        if (totalSum < 0) return -1; 
        return start;
    }
};
````

```c++
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candyVec(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1]) candyVec[i] = candyVec[i - 1] + 1;
        }
        for (int i = ratings.size() - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1] ) {
                candyVec[i] = max(candyVec[i], candyVec[i + 1] + 1);
            }
        }
        int result = 0;
        for (int i = 0; i < candyVec.size(); i++) result += candyVec[i];
        return result;
    }
};
````







```c++
class Solution {
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0, twenty = 0;
        for (int bill : bills) {
            if (bill == 5) five++;
            if (bill == 10) {
                if (five <= 0) return false;
                ten++;
                five--;
            }
            if (bill == 20) {
                if (five > 0 && ten > 0) {
                    five--;
                    ten--;
                    twenty++; 
                } else if (five >= 3) {
                    five -= 3;
                    twenty++; 
                } else return false;
            }
        }
        return true;
    }
};
````

```c++
class Solution {
    static bool cmp(const vector<int> a, const vector<int> b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort (people.begin(), people.end(), cmp);
        list<vector<int>> que;
        for (int i = 0; i < people.size(); i++) {
            int position = people[i][1];
            std::list<vector<int>>::iterator it = que.begin();
            while (position--) {
                it++;
            }
            que.insert(it, people[i]);
        }
        return vector<vector<int>>(que.begin(), que.end());
    }
};
````

```c++
class Solution {
    static bool cmp(const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; }
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0) return 0;
        sort(points.begin(), points.end(), cmp);
        int result = 1;
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] > points[i - 1][1]) {
                result++;
            } else {
                points[i][1] = min(points[i - 1][1], points[i][1]);
            }
        }
        return result;
    }
};
````







```c++

class Solution {
public:
    static bool cmp (const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return 0;
        sort(intervals.begin(), intervals.end(), cmp);
        int count = 1;
        int end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (end <= intervals[i][0]) {
                end = intervals[i][1];
                count++;
            }
        }
        return intervals.size() - count;
    }
};
````

```c++
class Solution {
public:
    vector<int> partitionLabels(string S) {
        int hash[27] = {0};
        for (int i = 0; i < S.size(); i++) {
            hash[S[i] - 'a'] = i;
        }
        vector<int> result;
        int left = 0;
        int right = 0;
        for (int i = 0; i < S.size(); i++) {
            right = max(right, hash[S[i] - 'a']);
            if (i == right) {
                result.push_back(right - left + 1);
                left = i + 1;
            }
        }
        return result;
    }
};
````

```c++
class Solution {
public:
    bool cmp(const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; };
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        if (intervals.size() == 0) return result;
        sort(intervals.begin(), intervals.end(), cmp);
        result.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if (result.back()[1] >= intervals[i][0]) {
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            } else {
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};
````











```c++
class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string strNum = to_string(N);
        int flag = strNum.size();
        for (int i = strNum.size() - 1; i > 0; i--) {
            if (strNum[i - 1] > strNum[i] ) {
                flag = i;
                strNum[i - 1]--;
            }
        }
        for (int i = flag; i < strNum.size(); i++) {
            strNum[i] = '9';
        }
        return stoi(strNum);
    }
};
````

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int result = 0;
        int minPrice = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < minPrice) minPrice = prices[i];
            if (prices[i] >= minPrice && prices[i] <= minPrice + fee) {
                continue;
            }
            if (prices[i] > minPrice + fee) {
                result += prices[i] - minPrice - fee;
                minPrice = prices[i] - fee;
            }
        }
        return result;
    }
};
````

```c++
class Solution {
public:
    int result;
    int traversal(TreeNode* cur) {
        if (cur == NULL) return 2; // monitor
        int left = traversal(cur->left); 
        int right = traversal(cur->right); 
        if (left == 2 && right == 2) return 0; //null
        else if (left == 0 || right == 0) {
            result++;
            return 1; // have
        } else return 2;
    }
    int minCameraCover(TreeNode* root) {
        result = 0;
        if (traversal(root) == 0) {
            result++;
        }
        return result;
    }
};
```
