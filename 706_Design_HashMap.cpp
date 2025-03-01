#include <iostream>

class MyHashMap {
	static constexpr int capacity = 100'010;

	int hash(int key) { return key % capacity; }
	std::array<int, capacity> table {};

public:
	MyHashMap() {
		for (int & i : table)
			i = -1;
	};

	void put(int key, int value) {
		table[hash(key)] = value;
	}

	int get(int key) {
		return table[hash(key)];
	}

	void remove(int key) {
		table[hash(key)] = -1;
	}
};

int main() {
	auto* myHashMap = new MyHashMap();
	myHashMap->put(1, 1); // The map is now [[1,1]]
	myHashMap->put(2, 2); // The map is now [[1,1], [2,2]]
	std::cout << myHashMap->get(1) << ' ';    // return 1, The map is now [[1,1], [2,2]]
	std::cout << myHashMap->get(3) << ' ';    // return -1 (i.e., not found), The map is now [[1,1], [2,2]]
	myHashMap->put(2, 1); // The map is now [[1,1], [2,1]] (i.e., update the existing value)
	std::cout << myHashMap->get(2) << ' ';     // return 1, The map is now [[1,1], [2,1]]
	myHashMap->remove(2); // remove the mapping for 2, The map is now [[1,1]]
	std::cout << myHashMap->get(2) << ' ';    // return -1 (i.e., not found), The map is now [[1,1]]
	delete myHashMap;
}