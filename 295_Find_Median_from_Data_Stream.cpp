#include <iostream>
#include <ostream>

// I would not lie, I took the solution from algo.monster this time.

class MedianFinder {
	std::priority_queue<int, std::vector<int>, std::greater<>> minHeap {};
	std::priority_queue<int> maxHeap {};

public:
	MedianFinder() {}

	void addNum(int num) {
		maxHeap.push(num);

		minHeap.push(maxHeap.top());
		maxHeap.pop();

		if (minHeap.size() > maxHeap.size()) {
			maxHeap.push(minHeap.top());
			minHeap.pop();
		}
	}

	double findMedian() const {
		if (maxHeap.size() > minHeap.size()) {
			return maxHeap.top();
		}
		return (static_cast<double>(maxHeap.top()) + static_cast<double>(minHeap.top())) / 2;
	}
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main() {
	{
		MedianFinder myFinder {};
		myFinder.addNum(2);
		myFinder.addNum(3);
		myFinder.addNum(4);
		std::cout << myFinder.findMedian() << std::endl << 3.0 << std::endl << std::endl;
	}
	{
		MedianFinder myFinder {};
		myFinder.addNum(2);
		myFinder.addNum(3);
		std::cout << myFinder.findMedian() << std::endl << 2.5 << std::endl << std::endl;
	}
	{
		MedianFinder myFinder {};
		myFinder.addNum(1);
		myFinder.addNum(2);
		std::cout << myFinder.findMedian() << std::endl << 1.5 << std::endl << std::endl;
		myFinder.addNum(3);
		std::cout << myFinder.findMedian() << std::endl << 2.0 << std::endl << std::endl;
	}
}