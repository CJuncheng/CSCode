#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int atmosphereChange(std::vector<int>& happinessValues) {
    std::sort(happinessValues.begin(), happinessValues.end(), greater<int>());
    int totalChange = 0;
    int n = happinessValues.size();
    for (int i = 0; i < n; i++) {
        totalChange += (n - i - 1) * happinessValues[i] - i * happinessValues[i];
    }
    return totalChange;
}

int main() {
    int n;
    cin >> n;
    vector<int> vec;
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        vec.push_back(tmp);
    }

    int total = atmosphereChange(vec);

    /*
    int total = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j)
            total += abs(vec[i] - vec[j]);
    }
    */
    cout << total << endl;

    return 0;
}