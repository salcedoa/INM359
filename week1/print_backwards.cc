#include <string>
#include <iostream>
#include <vector>
using namespace std;

// Week 1: Store lines in a vector and print them out backwards.
int main() {
	string s;
	vector<string> lines;

	while (getline(cin, s)) {
		lines.push_back(s);
	}

	// Print out the lines stored in the vector
	for (auto i = lines.crbegin(); i != lines.crend(); ++i) {
		cout << *i << '\n';
	}

	return 0;
}
