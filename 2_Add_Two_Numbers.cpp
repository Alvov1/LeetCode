#include <iostream>
#include <stack>

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
	void makeSum(ListNode* l1, ListNode* l2, std::queue<int>& queue) {
		if (l1 != nullptr && l2 != nullptr) {
			queue.push(l1->val + l2->val);
			makeSum(l1->next, l2->next, queue);
		} else if (l1 != nullptr) {
			queue.push(l1->val);
			makeSum(l1->next, nullptr, queue);
		} else if (l2 != nullptr) {
			queue.push(l2->val);
			makeSum(nullptr, l2->next, queue);
		}
	}
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		std::queue<int> queue {};
		makeSum(l1, l2, queue);

		if (!queue.empty()) {
			auto tVal = queue.front();
			ListNode* result = new ListNode(tVal % 10);
			int add = tVal / 10;
			queue.pop();
			ListNode* iter = result;

			while (!queue.empty()) {
				tVal = queue.front() + add;
				iter->next = new ListNode(tVal % 10);
				iter = iter->next;
				add = tVal / 10;
				queue.pop();
			}

			if (add != 0)
				iter->next = new ListNode(add);

			return result;
		} else return new ListNode(0);
	}
};


int main() {
	{
		auto* l1 = new ListNode(2);
		l1->next = new ListNode(4);
		l1->next->next = new ListNode(3);

		auto* l2 = new ListNode(5);
		l2->next = new ListNode(6);
		l2->next->next = new ListNode(4);

		auto* total = Solution().addTwoNumbers(l1, l2);
		std::cout << std::endl;
	}

	{
		auto* l1 = new ListNode(9), * c1 = l1;
		for (std::size_t i = 0; i < 6; ++i) {
			c1->next = new ListNode(9);
			c1 = c1->next;
		}

		auto* l2 = new ListNode(9), * c2 = l2;
		for (std::size_t i = 0; i < 3; ++i) {
			c2->next = new ListNode(9);
			c2 = c2->next;
		}

		auto* total = Solution().addTwoNumbers(l1, l2);
		std::cout << std::endl;
	}
}