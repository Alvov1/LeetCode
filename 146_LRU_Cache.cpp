#include <iostream>
#include <unordered_map>

class LRUCache final {
	struct ListEntry final {
		int key {}, value {};
		ListEntry* nextEntry = nullptr;
		ListEntry* previousEntry = nullptr;
		explicit ListEntry(int key, int value) : key(key), value(value) {}
	};
	ListEntry* enter = nullptr;
	std::unordered_map<int, ListEntry*> data {};
	std::size_t maxCapacity {};

	void rotateForward() { enter = enter->nextEntry; }

	void rotateBackward() { enter = enter->previousEntry; }

	void moveToFront(ListEntry* entry) {
		if (maxCapacity > 2) {
			ListEntry* ourPreviousEntry = entry->previousEntry,
			   * ourNextEntry = entry->nextEntry;

			ourNextEntry->previousEntry = ourPreviousEntry;
			ourPreviousEntry->nextEntry = ourNextEntry;

			ListEntry* top = enter,
				* back = top->previousEntry;
			entry->nextEntry = top;
			top->previousEntry = entry;

			entry->previousEntry = back;
			back->nextEntry = entry;

			enter = entry;
		} else
			if (maxCapacity == 2) rotateForward();
	}
public:
	LRUCache(const std::size_t withSize) : data(withSize), maxCapacity(withSize) {
		enter = new ListEntry(-1, -1);
		ListEntry* cursor = enter;

		for (std::size_t i = 0; i < withSize - 1; ++i) {
			/* 1. Create new list entry. */
			auto* newEntry = new ListEntry(-1, -1);
			/* 2. Connect new entry with previous, bidirectionally. */
			cursor->nextEntry = newEntry;
			newEntry->previousEntry = cursor;
			/* 3. Rotate cursor. */
			cursor = newEntry;
		}

		/* 4. Connect last element with the first */
		cursor->nextEntry = enter;
		enter->previousEntry = cursor;
	}

	void put(int key, int value) {
		const auto it = data.find(key);
		if (it == data.end()) {
			if (data.size() < maxCapacity) {
				/* Не найден и есть место -> добавляем в начало */

				/* Adding new element to the list.
				 * It automatically becomes the least */
				/* 1. Spinn buffer forward. */
				rotateBackward();
				/* 2. Add value to the list. */
				enter->key = key;
				enter->value = value;
				/* 3. Save data in table. */
				data[key] = enter;
			} else {
				/* Не найден и нет места. -> выпихиваем. */

				/* Remove the least element. */
				/* 1. Spinn buffer forward. */
				rotateBackward();
				/* 2. Remove the key with the least element from table. */
				data.erase(enter->key);
				/* 3. Change the value for the least element in the list.  */
				enter->key = key;
				enter->value = value;
				/* 4. Save data in table. */
				data[key] = enter;
			}
		} else {
			/* Найден -> обновляем, двигаем вперед. */

			/* Updating the value in the list
			 * + moving it to the front. */
			/* 1. Update value in the record. */
			ListEntry* cursor = it->second;
			cursor->value = value;
			/* 2. Move element to the front. */
			if (enter != cursor)
				moveToFront(cursor);
		}
	}

	int get(const int key) {
		if (const auto it = data.find(key); it != data.end()) {
			/* Taking the value from the list
			 * + moving it to the front. */
			/* 1. Update value in the record. */
			ListEntry* cursor = it->second;
			const auto value = cursor->value;
			/* 2. Move element to the front. */
			if (enter != cursor)
				moveToFront(cursor);
			/* 3. Return the value. */
			return value;
		}
		return -1;
	}
};

int main() {
	{
		auto* lRUCache = new LRUCache(2);
		lRUCache->put(1, 111);
		lRUCache->put(2, 222);
		std::cout << lRUCache->get(1) << ',';
		lRUCache->put(3, 333);
		std::cout << lRUCache->get(2) << ',';
		lRUCache->put(4, 444);
		std::cout << lRUCache->get(1) << ',';
		std::cout << lRUCache->get(3) << ',';
		std::cout << lRUCache->get(4) << ',';
		delete lRUCache;

		std::cout << std::endl << "111,-1,-1,333,444" << std::endl << std::endl;
	}

	{
		auto* lRUCache = new LRUCache(2);
		lRUCache->put(2, 1);
		lRUCache->put(3, 2);
		std::cout << lRUCache->get(3) << ',';
		std::cout << lRUCache->get(2) << ',';
		lRUCache->put(4, 3);
		std::cout << lRUCache->get(2) << ',';
		std::cout << lRUCache->get(3) << ',';
		std::cout << lRUCache->get(4) << ',';
		delete lRUCache;

		std::cout << std::endl << "2,1,1,-1,3" << std::endl << std::endl;
	}


	{
		auto* lRUCache = new LRUCache(3);
		lRUCache->put(1, 1);
		lRUCache->put(2, 2);
		lRUCache->put(3, 3);
		lRUCache->put(4, 4);
		std::cout << lRUCache->get(4) << ',';
		std::cout << lRUCache->get(3) << ',';
		std::cout << lRUCache->get(2) << ',';
		std::cout << lRUCache->get(1) << ',';
		lRUCache->put(5, 5);
		std::cout << lRUCache->get(1) << ',';
		std::cout << lRUCache->get(2) << ',';
		std::cout << lRUCache->get(3) << ',';
		std::cout << lRUCache->get(4) << ',';
		std::cout << lRUCache->get(5) << ',';
		delete lRUCache;

		std::cout << std::endl << "4,3,2,-1,-1,2,3,-1,5" << std::endl << std::endl;
	}
		
	{
		auto* lRUCache = new LRUCache(10);
		lRUCache->put(10, 13);
		lRUCache->put(3, 17);
		lRUCache->put(6, 11);
		lRUCache->put(10, 5);
		lRUCache->put(9, 10);
		std::cout << lRUCache->get(13) << ',';
		lRUCache->put(2, 19);
		std::cout << lRUCache->get(2) << ',';
		std::cout << lRUCache->get(3) << ',';
		lRUCache->put(5, 25);
		std::cout << lRUCache->get(8) << ',';
		lRUCache->put(9, 22);
		lRUCache->put(5, 5);
		lRUCache->put(1, 30);
		std::cout << lRUCache->get(11) << ',';
		lRUCache->put(9, 12);
		std::cout << lRUCache->get(7) << ',';
		std::cout << lRUCache->get(5) << ',';
		std::cout << lRUCache->get(8) << ',';
		std::cout << lRUCache->get(9) << ',';
		lRUCache->put(4, 30);
		lRUCache->put(9, 3);
		std::cout << lRUCache->get(9) << ',';
		std::cout << lRUCache->get(10) << ',';
		std::cout << lRUCache->get(10) << ',';
		lRUCache->put(6, 14);
		lRUCache->put(3, 1);
		std::cout << lRUCache->get(3) << ',';
		lRUCache->put(10, 11);
		std::cout << lRUCache->get(8) << ',';
		lRUCache->put(2, 14);
		std::cout << lRUCache->get(1) << ',';
		std::cout << lRUCache->get(5) << ',';
		std::cout << lRUCache->get(4) << ',';
		lRUCache->put(11, 4);
		lRUCache->put(12, 24);
		lRUCache->put(5, 18);
		std::cout << lRUCache->get(13) << ',';
		lRUCache->put(7, 23);
		std::cout << lRUCache->get(8) << ',';
		std::cout << lRUCache->get(12) << ',';
		lRUCache->put(3, 27);
		lRUCache->put(2, 12);
		std::cout << lRUCache->get(5) << ',';
		lRUCache->put(2, 9);
		lRUCache->put(13, 4);
		lRUCache->put(8, 18);
		lRUCache->put(1, 7);
		std::cout << lRUCache->get(6) << ',';
		lRUCache->put(9, 29);
		lRUCache->put(8, 21);
		std::cout << lRUCache->get(5) << ',';
		lRUCache->put(6, 30);
		lRUCache->put(1, 12);
		std::cout << lRUCache->get(10) << ',';
		lRUCache->put(4, 15);
		lRUCache->put(7, 22);
		lRUCache->put(11, 26);
		lRUCache->put(8, 17);
		lRUCache->put(9, 29);
		std::cout << lRUCache->get(5) << ',';
		lRUCache->put(3, 4);
		lRUCache->put(11, 30);
		std::cout << lRUCache->get(12) << ',';
		lRUCache->put(4, 29);
		std::cout << lRUCache->get(3) << ',';
		std::cout << lRUCache->get(9) << ',';
		std::cout << lRUCache->get(6) << ',';
		lRUCache->put(3, 4);
		std::cout << lRUCache->get(1) << ',';
		std::cout << lRUCache->get(10) << ',';
		lRUCache->put(3, 29);
		lRUCache->put(10, 28);
		lRUCache->put(1, 20);
		lRUCache->put(11, 13);
		std::cout << lRUCache->get(3) << ','; 
		lRUCache->put(3, 12); 
		lRUCache->put(3, 8);
		lRUCache->put(10, 9);
		lRUCache->put(3, 26);
		std::cout << lRUCache->get(8) << ',';
		std::cout << lRUCache->get(7) << ',';
		std::cout << lRUCache->get(5) << ',';
		lRUCache->put(13, 17);
		lRUCache->put(2, 27);
		lRUCache->put(11, 15);
		std::cout << lRUCache->get(12) << ',';
		lRUCache->put(9, 19);
		lRUCache->put(2, 15);
		lRUCache->put(3, 16);
		std::cout << lRUCache->get(1) << ',';
		lRUCache->put(12, 17);
		lRUCache->put(9, 1);
		lRUCache->put(6, 19);
		std::cout << lRUCache->get(4) << ',';
		std::cout << lRUCache->get(5) << ',';
		std::cout << lRUCache->get(5) << ',';
		lRUCache->put(8, 1);
		lRUCache->put(11, 7);
		lRUCache->put(5, 2);
		lRUCache->put(9, 28);
		std::cout << lRUCache->get(1) << ',';
		delete lRUCache;

		std::cout << std::endl << "-1,19,17,-1,-1,-1,5,-1,12,3,5,5,1,-1,30,5,30,-1,-1,24,18,-1,18,-1,18,-1,4,29,30,12,-1,29,17,22,18,-1,20,-1,18,18,20" << std::endl << std::endl;
	}
}

