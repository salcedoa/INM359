#include <iostream>
#include <list>
using namespace std;

template <typename Item>
class queue {
	list<Item> l;
public:
	bool empty() const { return l.size() == 0; }
	void enqueue(const Item & x) { l.push_back(x); }
    void dequeue() { l.pop_front(); }
	// It takes two...
	      Item & head()       { return l.front(); }
	const Item & head() const { return l.front(); }

          Item & tail()       { return l.back(); }
    const Item & tail() const { return l.back(); }

};

int main() {
	queue<int> qi;

	qi.enqueue(1);
	qi.enqueue(2);
	qi.enqueue(3);

	while (! qi.empty()) {
		cout << qi.head() << endl;
		qi.dequeue();
	}

	return 0;
}