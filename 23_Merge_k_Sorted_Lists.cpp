#include <iostream>

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* mergeKLists(std::vector<ListNode*>& lists) {
		ListNode* head = nullptr;
		ListNode* cur = head;

		while (!lists.empty()) {
			auto tracker = std::pair{
			std::numeric_limits<int>::max(),
			std::numeric_limits<std::size_t>::max()
			};
			auto& [minValue, listIdx] = tracker;


			std::vector<ListNode*>::iterator iter{};
			for (iter = lists.begin(); iter != lists.end();) {
				if (*iter != nullptr) {
					if (const auto value = (*iter)->val; value < tracker.first)
						tracker = {(*iter)->val, std::distance(lists.begin(), iter)};
					++iter;
				} else
					iter = lists.erase(iter);
			}
			if (lists.empty())
				return head;


			if (head == nullptr) {
				head = new ListNode(minValue);
				cur = head;
			} else {
				cur->next = new ListNode(minValue);
				cur = cur->next;
			}


			lists[listIdx] = lists[listIdx]->next;
			if (lists[listIdx] == nullptr)
				lists.erase(lists.begin() + listIdx);
		}

		return head;
	}
};
