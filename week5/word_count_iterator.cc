#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s;
    map<string, int> occurences;

    // Add the words to the map and vector
    while (cin >> s) {
        occurences[s]++;
    }

    // Exercise 5
    // Word list no longer needed; occurences is iterated.
    // Print out the words and their occurences
    for (auto i = occurences.begin(); i != occurences.end(); ++i) {
        cout << i->first << ": " << i->second << endl;
    }

    return 0;
}
