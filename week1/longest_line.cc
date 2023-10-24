#include <string>
#include <iostream>
using namespace std;

// Week 1: Print out the longest line of the input.
int main() {
	string s;
	string longest = "";

	while (getline(cin, s)) {
		if (s.length() > longest.length()) {
			longest = s;
		}
	}
	cout << longest << '\n';
	return 0;
}
