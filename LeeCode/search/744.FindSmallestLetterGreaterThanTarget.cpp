#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;

char nextGreatestLetter(vector<char>& letters, char target) {
    if(target=='z'||target>=letters[letters.size()-1]) return letters[0];
    auto it = lower_bound(letters.begin(), letters.end(), target);
    while(*it==target) ++it;
    return *it;
}