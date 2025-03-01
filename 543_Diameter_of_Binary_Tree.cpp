#include <iostream>
#include <ostream>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
	int dfs(TreeNode* root, int& maxDiameter) {
		if (root == nullptr)
			return 0;

		int left = dfs(root->left, maxDiameter);
		int right = dfs(root->right, maxDiameter);

		maxDiameter = std::max(maxDiameter, left + right);

		return 1 + std::max(left, right);
	}
public:
	int diameterOfBinaryTree(TreeNode* root) {
		int maxDiameter = 0;
		dfs(root, maxDiameter);
		return maxDiameter;
	}
};

int main() {
	{
		TreeNode* root = new TreeNode(1);
		root->left = new TreeNode(2);
		root->right = new TreeNode(3);
		root->left->left = new TreeNode(4);
		root->left->right = new TreeNode(5);
		std::cout << Solution().diameterOfBinaryTree(root) << std::endl << 3 << std::endl << std::endl;
	}
	{
		TreeNode* root = new TreeNode(1);
		root->left = new TreeNode(2);
		std::cout << Solution().diameterOfBinaryTree(root) << std::endl << 1 << std::endl << std::endl;
	}
}
