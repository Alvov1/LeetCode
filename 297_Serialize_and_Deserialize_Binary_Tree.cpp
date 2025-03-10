#include <iostream>
#include <sstream>
#include <map>


std::map<int, std::string> required = {
	{0, "7, 2"}, {10, "0, 0"}, {20, "0, 6"},
	{30, "8, 9"}, {40, "3, 0"}, {50, "0, 0"},
	{60, "1, 0"}, {70, "5, 4"}, {80, "0, 0"},
	{90, "0, 0"}
};

template <typename Contained = int>
struct TreeNode {
	int value;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : value(x), left(NULL), right(NULL) {}

	TreeNode(const std::vector<std::tuple<Contained, Contained, Contained>>& vertexes, long long position): left {}, right {} {
		auto [key, leftV, rightV] = vertexes[position];
		value = key;
		if(leftV != 0)
			left = new TreeNode (vertexes, leftV);
		if(rightV != 0)
			right = new TreeNode (vertexes, rightV);
	}

	void postorderTraversal(std::stringstream& ss, std::string code) const {
		if(left)
			left->postorderTraversal(ss, code);
		if(right)
			right->postorderTraversal(ss, code);
		std::cout << code << " - " << value << ", ";
	}

	void preorderTraversal() const {
		std::cout << value << ' ';
		if(left)
			left->preorderTraversal();
		if(right)
			right->preorderTraversal();
	}

	void inorderTraversal() const {
		if(left)
			left->inorderTraversal();
		std::cout << value << ' ';
		if(right)
			right->inorderTraversal();
	}
};


class Codec {
	static int traverse(TreeNode<int>* root, std::stringstream& out, std::size_t level) {
		auto leftLevel = root->left != nullptr ?
			traverse(root->left, out, level + 1) : 0;
		auto rightLevel = root->right != nullptr ?
			traverse(root->right, out, level + 2) : 0;

		std::cout << "(" << root->value << ' ' << leftLevel << ' ' << rightLevel << ") - ("
			<< root->value << ' ' << required[root->value] << ')' << std::endl;

		return level;
	}
public:

	static void serialize(TreeNode<int>* root) {
		std::stringstream ss {};
		traverse(root, ss, 0);
	}

	static TreeNode<int>* load_trash(std::string& data) {
		std::stringstream ss(data);

		std::size_t total = 0;
		ss >> total;
		std::vector<std::tuple<int, int, int>> vertexes {};
		vertexes.reserve(total);

		for (int a {}, b {}, c {}; ss >> a >> b >> c; )
			vertexes.emplace_back(a, b, c);

		return new TreeNode<int>(vertexes, 0);
	}

	static TreeNode<int>* deserialize(std::string& data);
};

int main() {
	{
		std::string ss = "10 0 7 2 10 0 0 20 0 6 30 8 9 40 3 0 50 0 0 60 1 0 70 5 4 80 0 0 90 0 0";
		auto root = Codec::load_trash(ss);
		std::stringstream sss {};
		root->postorderTraversal(sss, "0");
	}

	// {
	// 	std::vector<std::tuple<int, int, int>> vertexes = {
	// 		{0, 7, 2}, {10, -1, -1}, {20, -1, 6},
	// 		{30, 8, 9}, {40, 3, -1}, {50, -1, -1},
	// 		{60, 1, -1}, {70, 5, 4}, {80, -1, -1},
	// 		{90, -1, -1} };
	// 	auto root = TreeNode(vertexes, 0);
	// 	std::cout << std::endl;
	// }
	// {
	// 	TreeNode<int>* root = new TreeNode(1);
	//
	// 	root->left = new TreeNode(2);
	// 	root->right = new TreeNode(3);
	//
	// 	root->left->left = new TreeNode(4);
	// 	root->left->right = new TreeNode(5);
	//
	// 	root->right->left = new TreeNode(6);
	// 	root->right->right = new TreeNode(7);
	//
	// 	root->left->left->left = new TreeNode(8);
	// 	root->left->left->right = new TreeNode(9);
	//
	// 	root->left->right->left = new TreeNode(10);
	// 	root->left->right->right = new TreeNode(11);
	//
	// 	Codec().serialize(root);
	// 	std::cout << std::endl << std::endl;
	// }
	// {
	// 	TreeNode* root = new TreeNode(1);
	// 	root->left = new TreeNode(2);
	//
	// 	Codec().serialize(root);
	// 	std::cout << std::endl << std::endl;
	// }
}
