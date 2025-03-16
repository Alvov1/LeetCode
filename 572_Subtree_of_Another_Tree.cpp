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
	bool checkSub(TreeNode* root, TreeNode* subRoot) {
		if (root->val != subRoot->val)
			return false;

		if (root->left != nullptr) {
			if (subRoot->left == nullptr)
				return false;
			if (!checkSub(root->left, subRoot->left))
				return false;
		} else
			if (subRoot->left != nullptr) return false;

		if (root->right != nullptr) {
			if (subRoot->right == nullptr)
				return false;
			if (!checkSub(root->right, subRoot->right))
				return false;
		} else
			if (subRoot->right != nullptr) return false;

		return true;
	}
public:
	bool isSubtree(TreeNode* root, TreeNode* subRoot) {
		if(root->val == subRoot->val)
			if (checkSub(root, subRoot)) return true;
		if (root->left != nullptr)
			if (isSubtree(root->left, subRoot)) return true;
		if (root->right != nullptr)
			if (isSubtree(root->right, subRoot)) return true;
		return false;
	}
};


int main() {
	std::cout << std::boolalpha;
	{
		// root = [3,4,5,1,2], subRoot = [4,1,2]
		// Output: true
		TreeNode* root = new TreeNode(3);
		root->left = new TreeNode(4);
		root->right = new TreeNode(5);
		root->left->left = new TreeNode(1);
		root->left->right = new TreeNode(2);

		TreeNode* subTree = new TreeNode(4);
		subTree->left = new TreeNode(1);
		subTree->right = new TreeNode(2);

		std::cout << Solution().isSubtree(root, subTree) << std::endl << true << std::endl << std::endl;
	}

	{
		TreeNode* root = new TreeNode(3);
		root->left = new TreeNode(4);
		root->right = new TreeNode(5);
		root->left->left = new TreeNode(1);
		root->left->right = new TreeNode(2);
		root->left->right->left = new TreeNode(0);

		TreeNode* subTree = new TreeNode(4);
		subTree->left = new TreeNode(1);
		subTree->right = new TreeNode(2);

		std::cout << Solution().isSubtree(root, subTree) << std::endl << false << std::endl << std::endl;
	}
}