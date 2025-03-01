#include <iostream>
#include <stack>

class MyQueue {
	std::stack<int> out;
	std::stack<int> in;
	static constexpr auto border = 10;

	void inToOut() {
		while(out.size() < border && !in.empty()) {
			int top = in.top();
			out.push(top);
			in.pop();
		}
	}
public:
	MyQueue() = default;

	void push(int x) {
		in.push(x);
		if(out.empty()) inToOut();
	}

	int pop() {
		int top = out.top();
		out.pop();
		if(out.empty()) inToOut();
		return top;
	}

	int peek() {
		return out.top();
	}

	bool empty() {
		return out.empty() && in.empty();
	}
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */