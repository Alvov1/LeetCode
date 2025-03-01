#include <iostream>
#include <list>

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
	void traverse(ListNode* list, std::queue<int>& forward, std::queue<int>& backward) {
		forward.push(list->val);
		if (list->next != nullptr)
			traverse(list->next, forward, backward);
		backward.push(list->val);
	}
public:
	bool isPalindrome(ListNode* head) {
		std::queue<int> forward {}, backward {};
		traverse(head, forward, backward);

		for (; forward.empty() == false; forward.pop(), backward.pop())
			if (forward.front() != backward.front()) return false;
		return true;
	}
};

int main() {
	std::cout << std::boolalpha;

	{
		ListNode* head = new ListNode(1);
		head->next = new ListNode(2);
		head->next->next = new ListNode(2);
		head->next->next->next = new ListNode(1);
		std::cout << Solution().isPalindrome(head) << std::endl << true << std::endl << std::endl;
	}

	{
		ListNode* head = new ListNode(1);
		head->next = new ListNode(2);
		head->next->next = new ListNode(3);
		head->next->next->next = new ListNode(4);
		std::cout << Solution().isPalindrome(head) << std::endl << false << std::endl << std::endl;
	}

	{
		ListNode* head = new ListNode(1);
		head->next = new ListNode(2);
		std::cout << Solution().isPalindrome(head) << std::endl << false << std::endl << std::endl;
	}
}
