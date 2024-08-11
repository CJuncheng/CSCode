#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> vecs(N, 0), left(N, INT_MAX), right(N, INT_MAX);
    for(int i = 0; i < N; ++i) cin >> vecs[i];
    for(int i = 1; i < N-1; ++i) left[i] = min(vecs[i-1], left[i-1]);
    for(int i = N-2; i > 0; --i) right[i] = min(vecs[i+1], right[i+1]);
    for(int i = 1; i < N - 1; ++i)
        if(vecs[i] == -1) {
            int res = left[i] + right[i];
            cout << res << endl;
        }
    return 0;
}
// 64 位输出请用 printf("%lld")