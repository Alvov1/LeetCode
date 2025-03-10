#include <iostream>
#include <unordered_map>
#include <__ranges/elements_view.h>


class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node(int _val) {
		val = _val;
		next = nullptr;
		random = nullptr;
	}
};

class Solution {
public:
	Node* copyRandomList(Node* head) {
		if(head == nullptr) return nullptr;

		const auto randoms = [] (Node* iter) {
			/* Node -> (It's IDX; Val; Random Node*) */
			std::unordered_map<Node*, std::tuple<std::size_t, int, Node*>> nodes {};

			for (std::size_t i = 0; iter != nullptr; i++) {
				nodes[iter] = { i, iter->val, iter->random };
				iter = iter->next;
			}

			/* Node's IDX -> (val, random IDX). */
			std::unordered_map<std::size_t, std::pair<int, long long>> table {};

			for (auto& [_, params] : nodes) {
				auto [idx, val, node] = params;
				if (node != nullptr)
					table[idx] = { val,
						static_cast<long long>(std::get<0>(nodes[node])) };
				else table[idx] = { val, -1 };
			}

			return table;
		} (head);
		std::unordered_map<std::size_t, Node*> newNodes {};

		Node* copy = new Node(std::get<0>(randoms.at(0)));
		newNodes[0] = copy;

		Node* iter = copy;
		for (std::size_t i = 1; i < randoms.size(); i++) {
			const auto [value, _] = randoms.at(i);
			iter->next = new Node(value);
			newNodes[i] = iter->next;
			iter = iter->next;
		}

		iter = copy;
		for (std::size_t i = 0; i < randoms.size(); i++) {
			const auto [_, randIdx] = randoms.at(i);
			iter->random = newNodes[randIdx];
			iter = iter->next;
		}

		return copy;
	}
};

int main() {
	/* [ 0[7,null], 1[13,0], 2[11,4], 3[10,2], 4[1,0]] */

	/* (0; -1), (1, 0), (2, 4), (3, 2), (4, 0) */

	Node* root = new Node(7);

	root->next = new Node(13);
	root->next->next = new Node(11);
	root->next->next->next = new Node(10);
	root->next->next->next->next = new Node(1);

	root->next->random = root;
	root->next->next->random = root->next->next->next->next;
	root->next->next->next->random = root->next->next;
	root->next->next->next->next->random = root;

	Node* copy = Solution().copyRandomList(root);

	std::cout << copy->val << std::endl;

	return 0;
}