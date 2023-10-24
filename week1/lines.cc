#include <string>
#include <iostream>
using namespace std;

// Week 1: Counts the number of lines in the input
int main() {
	string s;
	int lineCount = 0;
	while (getline(cin, s)) {
		lineCount++;
		cout << lineCount << '\n';
	}
	return 0;
}
