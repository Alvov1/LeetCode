#include <iostream>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
	void search(const TreeNode* const root, std::vector<int>& values, const std::size_t depth) {
		if (depth == values.size()) // Adding value on the required depth
			values.push_back(root->val);

		if (root->right != nullptr)
			search(root->right, values, depth + 1); // Searching in the right subtree
		// We're first searching in the right-tree, that's why we're
		// guaranteed to get elements from the right in the first place

		if (root->left != nullptr)
			search(root->left, values, depth + 1); // Searching in the left subtree
	}

public:
	std::vector<int> rightSideView(TreeNode* root) {
		std::vector<int> values{};
		if (root != nullptr)
			search(root, values, 0);
		return values;
	}
};
