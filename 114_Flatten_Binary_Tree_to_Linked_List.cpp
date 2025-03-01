struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
	TreeNode** process(const TreeNode* const root, TreeNode** answer) {
		if (root == nullptr)
			return answer;

		*answer = new TreeNode(root->val);

		if (root->left != nullptr) {
			const auto t = process(root->left, &(*answer)->right);
			answer = &*t;
		}

		if (root->right != nullptr) {
			const auto t = process(root->right, &(*answer)->right);
			answer = &*t;
		}

		return answer;
	}

public:
	void flatten(TreeNode* root) {
		if (root == nullptr)
			return;

		TreeNode* p = nullptr;
		*process(root, &p);
		*root = *p;
	}
};
