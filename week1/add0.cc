// To run this:
// Type two integers separated by a space and press return.
// To stop the program type two zeros: 0 0
//
#include <iostream>
#include <climits>
using namespace std;

auto add_by_1 = []( int a, int b ) {
	// Keep adding 1 to a until b becomes 0.
	while (b != 0) {
		a++;
		--b;
	}
	return a;
};

// We don't need to change x so it's passed by reference
auto mult = [](int x, int y) {
	// Multiplies x and y by calling add_by_1()
	int temp = x;
	for (int i = 0; i < (y-1); i++) {
		// Spent a lot of time not realising that I just needed an assignment not +=
		temp = add_by_1(temp, x);
	}

	return temp;
};

int main() {
	int i, j;

	while (cin >> i >> j && (i != 0 || j != 0)) {
		cout << i << " + " << j << " = " << add_by_1(i, j) << endl;
		cout << i << " * " << j << " = " << mult(i, j) << endl;
	}

	i = 0; j = 0;
	cout << i << " + " << j << " = " << add_by_1(i, j) << endl;

	return 0;
}
