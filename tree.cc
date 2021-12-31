class Solution {
	public:
		vector<int> preorderTraversal(TreeNode* root) {
			stack<TreeNode*> st;
			vector<int> result;
			if (root == NULL) return result;
			st.push(root);
			while (!st.empty()) {
				TreeNode* node = st.top();
				st.pop();
				result.push_back(node->val);
				if (node->right) st.push(node->right);
				if (node->left) st.push(node->left);
			}
			return result;
		}
};

class Solution {
	public:
		vector<int> inorderTraversal(TreeNode* root) {
			vector<int> result;
			stack<TreeNode*> st;
			TreeNode* cur = root;
			while (cur != NULL || !st.empty()) {
				if (cur != NULL) {
					st.push(cur);
					cur = cur->left;
				} else {
					cur = st.top();
					st.pop();
					result.push_back(cur->val);
					cur = cur->right;
				}
			}
			return result;
		}
};

class Solution {
	public:
		vector<int> postorderTraversal(TreeNode* root) {
			stack<TreeNode*> st;
			vector<int> result;
			if (root == NULL) return result;
			st.push(root);
			while (!st.empty()) {
				TreeNode* node = st.top();
				st.pop();
				result.push_back(node->val);
				if (node->left) st.push(node->left);
				if (node->right) st.push(node->right);
			}
			reverse(result.begin(), result.end());
			return result;
		}
};

class Solution {
	public:
		vector<int> inorderTraversal(TreeNode* root) {
			vector<int> result;
			stack<TreeNode*> st;
			if (root != NULL) st.push(root);
			while (!st.empty()) {
				TreeNode* node = st.top();
				if (node != NULL) {
					st.pop();
					if (node->right) st.push(node->right);
					st.push(node);
					st.push(NULL);
					if (node->left) st.push(node->left);
				} else {
					st.pop();
					node = st.top();
					st.pop();
					result.push_back(node->val);
				}
			}
			return result;
		}
};

class Solution {
	public:
		vector<int> preorderTraversal(TreeNode* root) {
			vector<int> result;
			stack<TreeNode*> st;
			if (root != NULL) st.push(root);
			while (!st.empty()) {
				TreeNode* node = st.top();
				if (node != NULL) {
					st.pop();
					if (node->right) st.push(node->right);
					if (node->left) st.push(node->left);
					st.push(node);
					st.push(NULL);
				} else {
					st.pop();
					node = st.top();
					st.pop();
					result.push_back(node->val);
				}
			}
			return result;
		}
};

class Solution {
	public:
		vector<int> postorderTraversal(TreeNode* root) {
			vector<int> result;
			stack<TreeNode*> st;
			if (root != NULL) st.push(root);
			while (!st.empty()) {
				TreeNode* node = st.top();
				if (node != NULL) {
					st.pop();
					st.push(node);
					st.push(NULL);
					if (node->right) st.push(node->right);
					if (node->left) st.push(node->left);
				} else {
					st.pop();
					node = st.top();
					st.pop();
					result.push_back(node->val);
				}
			}
			return result;
		}
};

class Solution {
	public:
		vector<vector<int>> levelOrder(TreeNode* root) {
			queue<TreeNode*> que;
			if (root != NULL) que.push(root);
			vector<vector<int>> result;
			while (!que.empty()) {
				int size = que.size();
				vector<int> vec;
				for (int i = 0; i < size; i++) {
					TreeNode* node = que.front();
					que.pop();
					vec.push_back(node->val);
					if (node->left) que.push(node->left);
					if (node->right) que.push(node->right);
				}
				result.push_back(vec);
			}
			return result;
		}
};

class Solution {
	public:
		TreeNode* invertTree(TreeNode* root) {
			stack<TreeNode*> st;
			if (root != NULL) st.push(root);
			while (!st.empty()) {
				TreeNode* node = st.top();
				if (node != NULL) {
					st.pop();
					if (node->right) st.push(node->right);
					if (node->left) st.push(node->left);
					st.push(node);
					st.push(NULL);
				} else {
					st.pop();
					node = st.top();
					st.pop();
					swap(node->left, node->right);
				}
			}
			return root;
		}
};

class Solution {
	public:
		TreeNode* invertTree(TreeNode* root) {
			queue<TreeNode*> que;
			if (root != NULL) que.push(root);
			while (!que.empty()) {
				int size = que.size();
				for (int i = 0; i < size; i++) {
					TreeNode* node = que.front();
					que.pop();
					swap(node->left, node->right);
					if (node->left) que.push(node->left);
					if (node->right) que.push(node->right);
				}
			}
			return root;
		}
};
class Solution {
	public:
		int result;
		void getDepth(TreeNode* node, int depth) {
			result = depth > result ? depth : result; // 中
			if (node->left == NULL && node->right == NULL) return ;
			if (node->left) { // 左
				getDepth(node->left, depth + 1);
			}
			if (node->right) { // 右
				getDepth(node->right, depth + 1);
			}
			return ;
		}
		int maxDepth(TreeNode* root) {
			result = 0;
			if (root == 0) return result;
			getDepth(root, 1);
			return result;
		}
};
class Solution {
	private:
		void traversal(TreeNode* cur, string path, vector<string>& result) {
			path += to_string(cur->val); // 中
			if (cur->left == NULL && cur->right == NULL) {
				result.push_back(path);
				return;
			}
			if (cur->left) traversal(cur->left, path + "->", result); // 左
			if (cur->right) traversal(cur->right, path + "->", result); // 右
		}
	public:
		vector<string> binaryTreePaths(TreeNode* root) {
			vector<string> result;
			string path;
			if (root == NULL) return result;
			traversal(root, path, result);
			return result;
		}
};
class Solution {
	public:
		vector<string> binaryTreePaths(TreeNode* root) {
			stack<TreeNode*> treeSt;
			stack<string> pathSt;
			vector<string> result;
			if (root == NULL) return result;
			treeSt.push(root);
			pathSt.push(to_string(root->val));
			while (!treeSt.empty()) {
				TreeNode* node = treeSt.top(); treeSt.pop();
				string path = pathSt.top();pathSt.pop();
				if (node->left == NULL && node->right == NULL) {
					result.push_back(path);
				}
				if (node->right) {
					treeSt.push(node->right);
					pathSt.push(path + "->" + to_string(node->right->val));
				}
				if (node->left) { 
					treeSt.push(node->left);
					pathSt.push(path + "->" + to_string(node->left->val));
				}
			}
			return result;
		}
};
class Solution {
	public:
		bool hasPathSum(TreeNode* root, int sum) {
			if (root == NULL) return false;
			stack<pair<TreeNode*, int>> st;
			st.push(pair<TreeNode*, int>(root, root->val));
			while (!st.empty()) {
				pair<TreeNode*, int> node = st.top();
				st.pop();
				if (!node.first->left && !node.first->right && sum == node.second) return true;
				if (node.first->right) {
					st.push(pair<TreeNode*, int>(node.first->right, node.second + node.first->right->val));
				}
				if (node.first->left) {
					st.push(pair<TreeNode*, int>(node.first->left, node.second + node.first->left->val));
				}
			}
			return false;
		}
};
class Solution {
	public:
		TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
			if (t1 == NULL) return t2;
			if (t2 == NULL) return t1;
			TreeNode* root = new TreeNode(0);
			root->val = t1->val + t2->val;
			root->left = mergeTrees(t1->left, t2->left);
			root->right = mergeTrees(t1->right, t2->right);
			return root;
		}
};
class Solution {
	public:
		TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
			if (t1 == NULL) return t2;
			if (t2 == NULL) return t1;
			queue<TreeNode*> que;
			que.push(t1);
			que.push(t2);
			while(!que.empty()) {
				TreeNode* node1 = que.front(); que.pop();
				TreeNode* node2 = que.front(); que.pop();
				node1->val += node2->val;
				if (node1->left != NULL && node2->left != NULL) {
					que.push(node1->left);
					que.push(node2->left);
				}
				if (node1->right != NULL && node2->right != NULL) {
					que.push(node1->right);
					que.push(node2->right);
				}
				if (node1->left == NULL && node2->left != NULL) {
					node1->left = node2->left;
				}
				if (node1->right == NULL && node2->right != NULL) {
					node1->right = node2->right;
				}
			}
			return t1;
		}
};
class Solution {
	public:
		TreeNode* pre = NULL;
		bool isValidBST(TreeNode* root) {
			if (root == NULL) return true;
			bool left = isValidBST(root->left);
			if (pre != NULL && pre->val >= root->val) return false;
			pre = root;
			bool right = isValidBST(root->right);
			return left && right;
		}
};
class Solution {
	public:
		bool isValidBST(TreeNode* root) {
			stack<TreeNode*> st;
			TreeNode* cur = root;
			TreeNode* pre = NULL;
			while (cur != NULL || !st.empty()) {
				if (cur != NULL) {
					st.push(cur);
					cur = cur->left;
				} else {
					cur = st.top();
					st.pop();
					if (pre != NULL && cur->val <= pre->val)
						return false;
					pre = cur;
					cur = cur->right;
				}
			}
			return true;
		}
};
class Solution {
	private:
		int result = INT_MAX;
		TreeNode* pre;
		void traversal(TreeNode* cur) {
			if (cur == NULL) return;
			traversal(cur->left);
			if (pre != NULL){
				result = min(result, cur->val - pre->val);
			}
			pre = cur;
			traversal(cur->right);
		}
	public:
		int getMinimumDifference(TreeNode* root) {
			traversal(root);
			return result;
		}
};
class Solution {
	private:
		TreeNode* traversal(TreeNode* cur, TreeNode* p, TreeNode* q) {
			if (cur == NULL) return cur;
			if (cur->val > p->val && cur->val > q->val) {
				TreeNode* left = traversal(cur->left, p, q);
				if (left != NULL) {
					return left;
				}
			}
			if (cur->val < p->val && cur->val < q->val) {
				TreeNode* right = traversal(cur->right, p, q);
				if (right != NULL) {
					return right;
				}
			}
			return cur;
		}
	public:
		TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
			return traversal(root, p, q);
		}
};
class Solution {
	public:
		TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
			while(root) {
				if (root->val > p->val && root->val > q->val) {
					root = root->left;
				} else if (root->val < p->val && root->val < q->val) {
					root = root->right;
				} else return root;
			}
			return NULL;
		}
};
class Solution {
	public:
		TreeNode* insertIntoBST(TreeNode* root, int val) {
			if (root == NULL) {
				TreeNode* node = new TreeNode(val);
				return node;
			}
			if (root->val > val) root->left = insertIntoBST(root->left, val);
			if (root->val < val) root->right = insertIntoBST(root->right, val);
			return root;
		}
};
class Solution {
	public:
		TreeNode* deleteNode(TreeNode* root, int key) {
			if (root == nullptr) return root;
			if (root->val == key) {
				if (root->left == nullptr) return root->right;
				else if (root->right == nullptr) return root->left;
				else {
					TreeNode* cur = root->right;
					while(cur->left != nullptr) {
						cur = cur->left;
					}
					cur->left = root->left;
					TreeNode* tmp = root;
					root = root->right;
					delete tmp;
					return root;
				}
			}
			if (root->val > key) root->left = deleteNode(root->left, key);
			if (root->val < key) root->right = deleteNode(root->right, key);
			return root;
		}
};

class Solution {
	private:
		TreeNode* deleteOneNode(TreeNode* target) {
			if (target == nullptr) return target;
			if (target->right == nullptr) return target->left;
			TreeNode* cur = target->right;

			while (cur->left) {
				cur = cur->left;
			}
			cur->left = target->left;
			return target->right;
		}
	public:
		TreeNode* deleteNode(TreeNode* root, int key) {
			if (root == nullptr) return root;
			TreeNode* cur = root;
			TreeNode* pre = nullptr;
			while (cur) {
				if (cur->val == key) break;
				pre = cur;
				if (cur->val > key) cur = cur->left;
				else cur = cur->right;
			}
			if (pre == nullptr) {
				return deleteOneNode(cur);
			}
			if (pre->left && pre->left->val == key) {
				pre->left = deleteOneNode(cur);
			}
			if (pre->right && pre->right->val == key) {
				pre->right = deleteOneNode(cur);
			}
			return root;
		}
};
class Solution {
	public:
		TreeNode* trimBST(TreeNode* root, int low, int high) {
			if (root == nullptr) return nullptr;
			if (root->val < low) return trimBST(root->right, low, high);
			if (root->val > high) return trimBST(root->left, low, high);
			root->left = trimBST(root->left, low, high);
			root->right = trimBST(root->right, low, high);
			return root;
		}
};

class Solution {
	public:
		TreeNode* trimBST(TreeNode* root, int L, int R) {
			if (!root) return nullptr;
			while (root->val < L || root->val > R) {
				if (root->val < L) root = root->right;
				else root = root->left;
			}
			TreeNode *cur = root;
			while (cur != nullptr) {
				while (cur->left && cur->left->val < L) {
					cur->left = cur->left->right;
				}
				cur = cur->left;
			}
			cur = root;
			while (cur != nullptr) {
				while (cur->right && cur->right->val > R) {
					cur->right = cur->right->left;
				}
				cur = cur->right;
			}
			return root;
		}
};
class Solution {
	private:
		TreeNode* traversal(vector<int>& nums, int left, int right) {
			if (left > right) return nullptr;
			int mid = left + ((right - left) / 2);
			TreeNode* root = new TreeNode(nums[mid]);
			root->left = traversal(nums, left, mid - 1);
			root->right = traversal(nums, mid + 1, right);
			return root;
		}
	public:
		TreeNode* sortedArrayToBST(vector<int>& nums) {
			TreeNode* root = traversal(nums, 0, nums.size() - 1);
			return root;
		}
};
class Solution {
	public:
		TreeNode* sortedArrayToBST(vector<int>& nums) {
			if (nums.size() == 0) return nullptr;
			TreeNode* root = new TreeNode(0);
			queue<TreeNode*> nodeQue;
			queue<int> leftQue;
			queue<int> rightQue;
			nodeQue.push(root);
			leftQue.push(0);
			rightQue.push(nums.size() - 1);
			while (!nodeQue.empty()) {
				TreeNode* curNode = nodeQue.front();
				nodeQue.pop();
				int left = leftQue.front(); leftQue.pop();
				int right = rightQue.front(); rightQue.pop();
				int mid = left + ((right - left) / 2);
				curNode->val = nums[mid];
				if (left <= mid - 1) {
					curNode->left = new TreeNode(0);
					nodeQue.push(curNode->left);
					leftQue.push(left);
					rightQue.push(mid - 1);
				}
				if (right >= mid + 1) {
					curNode->right = new TreeNode(0);
					nodeQue.push(curNode->right);
					leftQue.push(mid + 1);
					rightQue.push(right);
				}
			}
			return root;
		}
};
