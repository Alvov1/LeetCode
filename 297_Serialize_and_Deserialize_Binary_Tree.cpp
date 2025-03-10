#include <iostream>
#include <sstream>
#include <map>
#include <regex>

/*
 * Solution is terrible in timing, for several reasons:
 * 1. Regex could be removed for more simple decoding.
 * 2. STD::STOI then would also be removed
 * 3. Algorithm could benefit from current pointer position
 *
 * I focused here to more on encoding/decoding algorithm rather than on speed and timing
 */

struct TreeNode {
	int val = -1;
	TreeNode* left = nullptr;
	TreeNode* right = nullptr;

	TreeNode() = default;
	explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Codec {
	static void postorderTraversal(TreeNode* ptr, std::stringstream& ss, const std::string& code) {
		if (ptr->left)
			postorderTraversal(ptr->left, ss, code + '0');
		if (ptr->right)
			postorderTraversal(ptr->right, ss, code + '1');
		ss << "{\"" << code << "\"," << ptr->val << "}";
	}

	static TreeNode* generate(const std::vector<std::pair<std::string, int>>& values) {
		TreeNode* root = new TreeNode(0);
		for (auto& [code, value] : values) {
			TreeNode* ptr = root;
			for (char bit : code) {
				if (bit == '0') {
					if (ptr->left == nullptr)
						ptr->left = new TreeNode ();
					ptr = ptr->left;
				} else if (bit == '1') {
					if (ptr->right == nullptr)
						ptr->right = new TreeNode ();
					ptr = ptr->right;
				} else throw std::invalid_argument("Invalid bit code");
			}
			ptr->val = value;
		}
		return root;
	}

	static std::vector<std::pair<std::string, int>> getValues(const std::string& data) {
		std::vector<std::pair<std::string, int>> values {};

		const std::regex pattern(R"(\{\"(\d*)\",(-*\d+)\})");
		for(auto i = std::sregex_iterator(data.begin(), data.end(), pattern);
							i != std::sregex_iterator();
							++i )
		{
			const std::smatch& m = *i;
			values.emplace_back(m[1].str(), std::stoi(m[2].str()));
		}

		return values;
	}
public:
	static std::string serialize(TreeNode* root) {
		if (root == nullptr)
			return "";

		std::stringstream ss {};
		postorderTraversal(root, ss, "");
		return ss.str();
	};
	static TreeNode* deserialize(const std::string& data) {
		if (data.empty())
			return nullptr;
		const auto values = getValues(data);
		return generate(values);
	}
};

int main() {
	{
		const auto str = R"({"00",50}{"0100",80}{"0101",90}{"010",30}{"01",40}{"0",70}{"110",10}{"11",60}{"1",20}{"",0})";
		auto root = Codec::deserialize(str);

		const auto str2 = Codec::serialize(root);
		if (str != str2) {
			std::cout << str << std::endl << str2 << std::endl;
			throw std::runtime_error("Serialization Error");
		}
	}

	{
		TreeNode* root = new TreeNode(1);

		root->left = new TreeNode(2);
		root->right = new TreeNode(3);

		root->left->left = new TreeNode(4);
		root->left->right = new TreeNode(5);

		root->right->left = new TreeNode(6);
		root->right->right = new TreeNode(7);

		root->left->left->left = new TreeNode(8);
		root->left->left->right = new TreeNode(9);

		root->left->right->left = new TreeNode(10);
		root->left->right->right = new TreeNode(11);

		const auto str = Codec::serialize(root);
		auto root2 = Codec::deserialize(str);

		const auto str2 = Codec::serialize(root2);
		if (str != str2) {
			std::cout << str << std::endl << str2 << std::endl;
			throw std::runtime_error("Serialization Error");
		}
	}

	{
		TreeNode* root = nullptr;
		const auto str = Codec::serialize(root);

		auto root2 = Codec::deserialize(str);
		if (root2 != nullptr)
			throw std::runtime_error("Serialization Error");

		const auto str2 = Codec::serialize(root2);

		if (str != str2) {
			std::cout << str << std::endl << str2 << std::endl;
			throw std::runtime_error("Serialization Error");
		}
	}

	{
		TreeNode* root = new TreeNode(4);
		root->left = new TreeNode(-7);
		root->right = new TreeNode(-3);

		root->right->left = new TreeNode(-9);
		root->right->right = new TreeNode(-3);

		root->right->left->left = new TreeNode(9);
		root->right->left->right = new TreeNode(-7);
		root->right->right->left = new TreeNode(-4);

		root->right->left->left->left = new TreeNode(6);
		root->right->left->right->left = new TreeNode(-6);
		root->right->left->right->right = new TreeNode(-6);

		root->right->left->left->left->left = new TreeNode( 0);
		root->right->left->left->left->right = new TreeNode( 6);
		root->right->left->right->left->left = new TreeNode( 5);
		root->right->left->right->right->left = new TreeNode( 9);

		root->right->left->left->left->left->right = new TreeNode( -1);
		root->right->left->left->left->right->left = new TreeNode( -4);
		root->right->left->right->right->left->left = new TreeNode( -2);

		const auto str = Codec::serialize(root);
		std::cout << str << std::endl;

		const auto root2 = Codec::deserialize(str);
		const auto str2 = Codec::serialize(root2);
		std::cout << str2 << std::endl;

		if (str != str2)
			throw std::runtime_error("Serialization Error");
	}

	return 0;
}
