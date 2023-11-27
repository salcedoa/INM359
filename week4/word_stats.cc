// Exercise 3
#include <iostream>
#include <map>
#include <utility>
#include <string>

using namespace std;

// Keeps track of the statistics of a word.
class Stats {
    double total;
    int count;
    
    public:
        Stats() : total(0), count(0) {}

        virtual void add_value(double v) {
            count++;
            total += v;
        }

        double get_total() { return total; }
        int get_count() { return count; }
        double get_mean() { return total/count; }
};

int main() {
    map<string, Stats> word_stats;
    vector<string> words;
    string s;
    double n;

    // Expected input is a series of lines each with a word and a number.
    while (cin >> s >> n) {
        // Check if the word is new.
        if (word_stats.count(s) == 0) {
            words.push_back(s);
        }
        // Update the statistics via the class.
        word_stats[s].add_value(n);
    }

    // Print the stats.
    for (auto i = 0; i < word_stats.size(); i++) {
        Stats &stat = word_stats[words[i]];
        cout << words[i] << " total=" << stat.get_total() << " mean=" << stat.get_mean() << endl;
    }

    return 0;
}