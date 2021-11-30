
class Solution {
	int CompletePack(std::vector<int> weight, std::vector<int> value, int bagweight) {
		vector<int> dp(bagWeight + 1, 0);
		for(int i = 0; i < weight.size(); i++) {
			for(int j = weight[i]; j <= bagWeight; j++) {
				dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
			}
		}
		return dp[bagWeight];
	}

};

class Solution {
	public:
		int change(int amount, vector<int>& coins) {
			vector<int> dp(amount + 1, 0);
			dp[0] = 1;
			for (int i = 0; i < coins.size(); i++) {
				for (int j = coins[i]; j <= amount; j++) {
					dp[j] += dp[j - coins[i]];
				}
			}
			return dp[amount];
		}
};


class Solution {
	public:
		int combinationSum4(vector<int>& nums, int target) {

			vector<int> dp(target + 1, 0);
			dp[0] = 1;
			for (int i = 0; i <= target; i++) { // 遍历背包
				for (int j = 0; j < nums.size(); j++) { // 遍历物品
					if (i - nums[j] >= 0 && dp[i] < INT_MAX - dp[i - nums[j]]) {
						dp[i] += dp[i - nums[j]];
					}
				}
			}
			return dp[target];
		}
};

class Solution {
	public:
		int climbStairs(int n) {
			vector<int> dp(n + 1, 0);
			dp[0] = 1;
			for (int i = 1; i <= n; i++) { // 遍历背包
				for (int j = 1; j <= m; j++) { // 遍历物品
					if (i - j >= 0) dp[i] += dp[i - j];
				}
			}
			return dp[n];
		}
};


class Solution {
	public:
		int numSquares(int n) {
			vector<int> dp(n + 1, INT_MAX);
			dp[0] = 0;
			for (int i = 1; i * i <= n; i++) { // 遍历物品
				for (int j = 1; j <= n; j++) { // 遍历背包
					if (j - i * i >= 0) {
						dp[j] = min(dp[j - i * i] + 1, dp[j]);
					}
				}
			}
			return dp[n];
		}
};


class Solution {
	public:
		int coinChange(vector<int>& coins, int amount) {
			vector<int> dp(amount + 1, INT_MAX);
			dp[0] = 0;

			for (int i = 0; i < coins.size(); i++) { // 遍历物品
				for (int j = coins[i]; j <= amount; j++) { // 遍历背包
					if (dp[j - coins[i]] != INT_MAX) { // 如果dp[j - coins[i]]是初始
						值则跳过
							dp[j] = min(dp[j - coins[i]] + 1, dp[j]);
					}
				}
			}
			if (dp[amount] == INT_MAX) return -1;
			return dp[amount];
		}
};

class Solution {
	public:
		int coinChange(vector<int>& coins, int amount) {
			vector<int> dp(amount + 1, INT_MAX);
			dp[0] = 0;
			for (int i = 1; i <= amount; i++) { // 遍历背包
				for (int j = 0; j < coins.size(); j++) { // 遍历物品
					if (i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX ) {
						dp[i] = min(dp[i - coins[j]] + 1, dp[i]);
					}
				}
			}
			if (dp[amount] == INT_MAX) return -1;
			return dp[amount];
		}
};

class Solution {
	public:
		int numSquares(int n) {
			vector<int> dp(n + 1, INT_MAX);
			dp[0] = 0;
			for (int i = 0; i <= n; i++) { // 遍历背包
				for (int j = 1; j * j <= i; j++) { // 遍历物品
					dp[i] = min(dp[i - j * j] + 1, dp[i]);
				}
			}
			return dp[n];
		}
};

class Solution {
	public:
		bool wordBreak(string s, vector<string>& wordDict) {
			unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
			vector<bool> dp(s.size() + 1, false);
			dp[0] = true;
			for (int i = 1; i <= s.size(); i++) { // 遍历背包
				for (int j = 0; j < i; j++) { // 遍历物品
					string word = s.substr(j, i - j); //substr(起始位置，截取的个数)
					if (wordSet.find(word) != wordSet.end() && dp[j]) {
						dp[i] = true;
					}
				}
			}
			return dp[s.size()];
		}
}

class Solution {
	int MultiPack(std::vector<int> weight, std::vector<int> value, std::vector<int> nums, int bagweight) {
		std::vector<int> dp(bagWeight + 1, 0);
		for(int i = 0; i < weight.size(); i++) { // 遍历物品
			for(int j = bagWeight; j >= weight[i]; j--) { // 遍历背包容量
				// 以上为01背包，然后加⼀个遍历个数
				for (int k = 1; k <= nums[i] && (j - k * weight[i]) >= 0; k++) { // 遍历个数
					dp[j] = max(dp[j], dp[j - k * weight[i]] + k * value[i]);
				}
			}
		}
		return dp[bagWeight];
	}

	class Solution {
		public:
			int rob(vector<int>& nums) {
				if (nums.size() == 0) return 0;
				if (nums.size() == 1) return nums[0];
				vector<int> dp(nums.size());
				dp[0] = nums[0];
				dp[1] = max(nums[0], nums[1]);

				for (int i = 2; i < nums.size(); i++) {
					dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
				}
				return dp[nums.size() - 1];
			}
	};


	class Solution {
		public:
			int rob(vector<int>& nums) {
				if (nums.size() == 0) return 0;
				if (nums.size() == 1) return nums[0];
				int result1 = robRange(nums, 0, nums.size() - 2); // rob first 
				int result2 = robRange(nums, 1, nums.size() - 1); // rob last
				return max(result1, result2);
			}

			int robRange(vector<int>& nums, int start, int end) {
				if (end == start) return nums[start];
				vector<int> dp(nums.size());
				dp[start] = nums[start];
				dp[start + 1] = max(nums[start], nums[start + 1]);
				for (int i = start + 2; i <= end; i++) {
					dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
				}
				return dp[end];
			}
	};

	class Solution {
		public:
			int rob(TreeNode* root) {
				if (root == NULL) return 0;
				if (root->left == NULL && root->right == NULL) return root->val;
				int val1 = root->val;
				if (root->left) val1 += rob(root->left->left) + rob(root->left->right);
				if (root->right) val1 += rob(root->right->left) + rob(root->right->right); 
				int val2 = rob(root->left) + rob(root->right);
				return max(val1, val2);
			}
	};

	class Solution {
		public:
			unordered_map<TreeNode* , int> umap;
			int rob(TreeNode* root) {
				if (root == NULL) return 0;
				if (root->left == NULL && root->right == NULL) return root->val;
				if (umap[root]) return umap[root]; 
				int val1 = root->val;
				if (root->left) val1 += rob(root->left->left) + rob(root->left->right);

				if (root->right) val1 += rob(root->right->left) + rob(root->right- >right);
				int val2 = rob(root->left) + rob(root->right);
				umap[root] = max(val1, val2);
				return max(val1, val2);
			}
	};

	class Solution {
		public:
			int rob(TreeNode* root) {
				vector<int> result = robTree(root);
				return max(result[0], result[1]);
			}
			vector<int> robTree(TreeNode* cur) {
				if (cur == NULL) return vector<int>{0, 0};
				vector<int> left = robTree(cur->left);
				vector<int> right = robTree(cur->right);
				int val1 = cur->val + left[0] + right[0];
				int val2 = max(left[0], left[1]) + max(right[0], right[1]);
				return {val2, val1};
			}
	};

	class Solution {
		public:
			int maxProfit(vector<int>& prices) {
				int low = INT_MAX;
				int result = 0;
				for (int i = 0; i < prices.size(); i++) {
					low = min(low, prices[i]);
					result = max(result, prices[i] - low);
				}
				return result;
			}
	};

	class Solution {
		public:
			int maxProfit(vector<int>& prices) {
				int len = prices.size();
				vector<vector<int>> dp(len, vector<int>(2, 0));
				dp[0][0] -= prices[0];
				dp[0][1] = 0;
				for (int i = 1; i < len; i++) {
					dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
					dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
				}
				return dp[len - 1][1];
			}

	};

	class Solution {
		public:
			int maxProfit(vector<int>& prices) {
				int len = prices.size();
				if (len == 0) return 0;
				vector<vector<int>> dp(len, vector<int>(2));
				dp[0][0] -= prices[0];
				dp[0][1] = 0;
				for (int i = 1; i < len; i++) {
					dp[i][0] = max(dp[i - 1][0], -prices[i]);
					dp[i][1] = max(dp[i - 1][1], prices[i] + dp[i - 1][0]);
				}
				return dp[len - 1][1];
			}
	};

	class Solution {
		public:
			int maxProfit(vector<int>& prices) {
				int len = prices.size();
				vector<vector<int>> dp(len, vector<int>(2, 0));
				dp[0][0] -= prices[0];
				dp[0][1] = 0;
				for (int i = 1; i < len; i++) {
					dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
					dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
				}
				return dp[len - 1][1];
			}
	};

	class Solution {
		public:
			int maxProfit(vector<int>& prices, int fee) {
				int n = prices.size();
				vector<vector<int>> dp(n, vector<int>(2, 0));
				dp[0][0] -= prices[0];
				for (int i = 1; i < n; i++) {
					dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
					dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee);
				}
				return max(dp[n - 1][0], dp[n - 1][1]);
			}
	};

	class Solution {
		public:
			int maxProfit(vector<int>& prices) {
				int len = prices.size();
				vector<vector<int>> dp(2, vector<int>(2));
				dp[0][0] -= prices[0];
				dp[0][1] = 0;
				for (int i = 1; i < len; i++) {
					dp[i % 2][0] = max(dp[(i - 1) % 2][0], -prices[i]);
					dp[i % 2][1] = max(dp[(i - 1) % 2][1], prices[i] + dp[(i - 1) % 2]
							[0]);
				}
				return dp[(len - 1) % 2][1];
			}
	};


	class Solution {
		public:
			int maxProfit(vector<int>& prices) {
				int len = prices.size();
				vector<vector<int>> dp(2, vector<int>(2));
				dp[0][0] -= prices[0];
				dp[0][1] = 0;
				for (int i = 1; i < len; i++) {
					dp[i % 2][0] = max(dp[(i - 1) % 2][0], dp[(i - 1) % 2][1] - prices[i]);
					dp[i % 2][1] = max(dp[(i - 1) % 2][1], prices[i] + dp[(i - 1) % 2]
							[0]);
				}
				return dp[(len - 1) % 2][1];
			}
	};

	class Solution {
		public:
			int maxProfit(vector<int>& prices) {
				if (prices.size() == 0) return 0;
				vector<vector<int>> dp(prices.size(), vector<int>(5, 0));
				dp[0][1] = -prices[0];
				dp[0][3] = -prices[0];

				for (int i = 1; i < prices.size(); i++) {
					dp[i][0] = dp[i - 1][0]; // do nothing
					dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);  // in 
					dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);  // out
					dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);  // in
					dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);  // out
				}
				return dp[prices.size() - 1][4];
			}
	};

	class Solution {
		public:
			int maxProfit(int k, vector<int>& prices) {
				if (prices.size() == 0) return 0;
				vector<vector<int>> dp(prices.size(), vector<int>(2 * k + 1, 0));
				for (int j = 1; j < 2 * k; j += 2) {
					dp[0][j] = -prices[0];
				}
				for (int i = 1;i < prices.size(); i++) {
					for (int j = 0; j < 2 * k - 1; j += 2) {
						dp[i][j + 1] = max(dp[i - 1][j + 1], dp[i - 1][j] - prices[i]);
						dp[i][j + 2] = max(dp[i - 1][j + 2], dp[i - 1][j + 1] + prices[i]);
					}
				}
				return dp[prices.size() - 1][2 * k];
			}
	};

	class Solution {
		public:
			int maxProfit(vector<int>& prices) {
				int n = prices.size();
				if (n == 0) return 0;
				vector<vector<int>> dp(n, vector<int>(4, 0));
				dp[0][0] -= prices[0];
				for (int i = 1; i < n; i++) {
					dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][3], dp[i - 1][1]) - prices[i]);
					dp[i][1] = max(dp[i - 1][1], dp[i - 1][3]);
					dp[i][2] = dp[i - 1][0] + prices[i];
					dp[i][3] = dp[i - 1][2];
				}
				return max(dp[n - 1][3],max(dp[n - 1][1], dp[n - 1][2]));
			}
	};


	class Solution {
		public:
			int lengthOfLIS(vector<int>& nums) {
				if (nums.size() <= 1) return nums.size();
				vector<int> dp(nums.size(), 1);
				int result = 0;
				for (int i = 1; i < nums.size(); i++) {
					for (int j = 0; j < i; j++) {
						if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
					}
					if (dp[i] > result) result = dp[i];
				}
				return result;
			}
	};

	class Solution {
		public:
			int findLengthOfLCIS(vector<int>& nums) {
				if (nums.size() == 0) return 0;
				int result = 1;
				vector<int> dp(nums.size() ,1);
				for (int i = 0; i < nums.size() - 1; i++) {
					if (nums[i + 1] > nums[i]) {
						dp[i + 1] = dp[i] + 1;
					}
					if (dp[i + 1] > result) result = dp[i + 1];
				}
				return result;
			}
	};

	class Solution {
		public:
			int findLength(vector<int>& A, vector<int>& B) {
				vector<vector<int>> dp (A.size() + 1, vector<int>(B.size() + 1, 0));
				int result = 0;
				for (int i = 1; i <= A.size(); i++) {
					for (int j = 1; j <= B.size(); j++) {
						if (A[i - 1] == B[j - 1]) {
							dp[i][j] = dp[i - 1][j - 1] + 1;
						}
						if (dp[i][j] > result) result = dp[i][j];
					}
				}
				return result;
			}
	};


	class Solution {
		public:
			int findLength(vector<int>& A, vector<int>& B) {
				vector<int> dp(vector<int>(B.size() + 1, 0));
				int result = 0;
				for (int i = 1; i <= A.size(); i++) {
					for (int j = B.size(); j > 0; j--) {
						if (A[i - 1] == B[j - 1]) {
							dp[j] = dp[j - 1] + 1;
						} else dp[j] = 0;
						if (dp[j] > result) result = dp[j];
					}
				}
				return result;
			}
	};

	class Solution {
		public:
			int longestCommonSubsequence(string text1, string text2) {
				vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
				for (int i = 1; i <= text1.size(); i++) {
					for (int j = 1; j <= text2.size(); j++) {
						if (text1[i - 1] == text2[j - 1]) {
							dp[i][j] = dp[i - 1][j - 1] + 1;
						} else {
							dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
						}
					}
				}
				return dp[text1.size()][text2.size()];
			}
	};

	class Solution {
		public:
			bool isSubsequence(string s, string t) {
				vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
				for (int i = 1; i <= s.size(); i++) {
					for (int j = 1; j <= t.size(); j++) {
						if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
						else dp[i][j] = dp[i][j - 1];
					}
				}
				if (dp[s.size()][t.size()] == s.size()) return true;
				return false;
			}
	};



	class Solution {
		public:
			int maxUncrossedLines(vector<int>& A, vector<int>& B) {
				vector<vector<int>> dp(A.size() + 1, vector<int>(B.size() + 1, 0));
				for (int i = 1; i <= A.size(); i++) {
					for (int j = 1; j <= B.size(); j++) {
						if (A[i - 1] == B[j - 1]) {
							dp[i][j] = dp[i - 1][j - 1] + 1;
						} else {
							dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
						}
					}
				}
				return dp[A.size()][B.size()];
			}
	}

	class Solution {
		public:
			int maxSubArray(vector<int>& nums) {

				if (nums.size() == 0) return 0;
				vector<int> dp(nums.size());
				dp[0] = nums[0];
				int result = dp[0];
				for (int i = 1; i < nums.size(); i++) {
					dp[i] = max(dp[i - 1] + nums[i], nums[i]); // 状态转移公式
					if (dp[i] > result) result = dp[i]; // result 保存dp[i]的最⼤值
				}
				return result;
			}
	};

	class Solution {
		public:
			int numDistinct(string s, string t) {
				vector<vector<uint64_t>> dp(s.size() + 1, vector<uint64_t>(t.size() + 1));
				for (int i = 0; i < s.size(); i++) dp[i][0] = 1;
				for (int j = 1; j < t.size(); j++) dp[0][j] = 0;

				for (int i = 1; i <= s.size(); i++) {
					for (int j = 1; j <= t.size(); j++) {
						if (s[i - 1] == t[j - 1]) {
							dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
						} else {
							dp[i][j] = dp[i - 1][j];
						}
					}
				}
				return dp[s.size()][t.size()];
			}
	};

	class Solution {
		public:
			int minDistance(string word1, string word2) { 

				vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1));
				for (int i = 0; i <= word1.size(); i++) dp[i][0] = i;
				for (int j = 0; j <= word2.size(); j++) dp[0][j] = j;
				for (int i = 1; i <= word1.size(); i++) {
					for (int j = 1; j <= word2.size(); j++) {
						if (word1[i - 1] == word2[j - 1]) {
							dp[i][j] = dp[i - 1][j - 1];
						} else {
							dp[i][j] = min({dp[i - 1][j - 1] + 2, dp[i - 1][j] + 1,
									dp[i][j - 1] + 1});
						}
					}
				}
				return dp[word1.size()][word2.size()];
			}
	};

	class Solution {
		public:
			int minDistance(string word1, string word2) {
				vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1,
							0));
				for (int i = 0; i <= word1.size(); i++) dp[i][0] = i;
				for (int j = 0; j <= word2.size(); j++) dp[0][j] = j;

				for (int i = 1; i <= word1.size(); i++) {
					for (int j = 1; j <= word2.size(); j++) {
						if (word1[i - 1] == word2[j - 1]) {
							dp[i][j] = dp[i - 1][j - 1];
						} else {
							dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
						}
					}
				}
				return dp[word1.size()][word2.size()];
			}
	};


	class Solution {
		public:
			int countSubstrings(string s) {
				vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
				int result = 0;
				int start = 0;
				int max_len = 1;

				for (int i = s.size() - 1; i >= 0; i--) {
					for (int j = i; j < s.size(); j++) {
						if (s[i] == s[j]) {
							if (j - i <= 1) {
								result++;
								dp[i][j] = true;
								if(j-i > max_len) start = i;

							} else if (dp[i + 1][j - 1]) {
								result++;
								dp[i][j] = true;
								if(j-i > max_len) start = i;

							}
						}
					}
				}
				return result;
			}
	};

	class Solution {
		public:
			int longestPalindromeSubseq(string s) {
				vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
				for (int i = 0; i < s.size(); i++) dp[i][i] = 1;
				for (int i = s.size() - 1; i >= 0; i--) {
					for (int j = i + 1; j < s.size(); j++) {
						if (s[i] == s[j]) {
							dp[i][j] = dp[i + 1][j - 1] + 2;
						} else {
							dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
						}
					}
				}
				return dp[0][s.size() - 1];
			}
	};
