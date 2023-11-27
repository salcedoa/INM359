#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s;
    vector<string> words;
    map<string, int> occurences;

    // Add the words to the map and vector
    while (cin >> s) {
        occurences[s]++;

        // a word that exists in the input will only be incremented to 1 once.
        if (occurences[s] == 1) {
            words.push_back(s);
        }
    }

    // Print out the words and their occurences
    for (auto i = 0; i != words.size(); i++) {
        cout << words[i] << ": " << occurences[words[i]] << endl;
    }

    return 0;
}
