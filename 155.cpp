class MinStack {
private:
	stack<int> s1;
	stack<int> s2;
public:
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		// only need to store the one which is smaller than or equal to the top. 
		//If x is bigger than the top, since it will pop before the top, it will not the be the min value in the stack.
		if (s2.empty() || s2.top() >= x) s2.push(x);
		s1.push(x);
	}

	void pop() {
		if (s1.top() == s2.top()) s2.pop();
		s1.pop();
	}

	int top() {
		return s1.top();
	}

	int getMin() {
		return s2.top();
	}
};