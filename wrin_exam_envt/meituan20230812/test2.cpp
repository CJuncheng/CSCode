#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> dists(n);
    long sum = 0;
    for(int i = 0; i < n; ++i) {
        cin >> dists[i];
        sum += dists[i];
    }
    int x, y; cin >> x >> y;
    if(x > y) swap(x, y);
    long xy_sum = 0;
    for(int i = x-1; i < y-1; ++i)  xy_sum += dists[i];

    long demain = sum-xy_sum;
    if(demain > xy_sum) cout << xy_sum << endl;
    else cout << demain << endl;

    return 0;

}