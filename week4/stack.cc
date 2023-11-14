#include <iostream>
#include <vector>
using namespace std;

template <typename Item>
class stack {
	vector<Item> v;
public:
	bool empty() const { return v.size() == 0; }
	void push(const Item & x) { v.push_back(x); }
	void pop() { v.pop_back(); }
	// It takes two...
	      Item & top()       { return v.back(); }
	const Item & top() const { return v.back(); }
};

int main() {
	stack<int> si;

	si.push(1);
	si.push(2);
	si.push(3);

	while (! si.empty()) {
		cout << si.top() << endl;
		si.pop();
	}

	return 0;
}
