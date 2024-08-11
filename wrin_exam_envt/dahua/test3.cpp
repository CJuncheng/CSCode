#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

void findMostFrequentSubstr(const string& str) {
    const int n = str.size();
    unordered_map<string, int> substrFreq;

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= n - i; j++) {
            string substr = str.substr(i, j);
            substrFreq[substr]++;
        }
    }

    string mostFreqSubstr;
    int maxFreq = 0;

    for (auto& pair : substrFreq) {
        if (pair.second > maxFreq) {
            maxFreq = pair.second;
            mostFreqSubstr = pair.first;
        }
    }
    cout << mostFreqSubstr << " " << maxFreq << endl;
}

int main() {
    string str; cin >> str;
    findMostFrequentSubstr(str);
    return 0;
}