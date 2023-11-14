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
        if (occurences[s] == 1) {
            words.push_back(s);
        }
    }

    // Print out the words and their occurences
    for (int i = 0; i != words.size(); i++) {
        cout << words[i] << ": " << occurences[words[i]] << endl;
    }

    return 0;
}
