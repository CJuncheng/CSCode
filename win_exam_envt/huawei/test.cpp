
// we have defined the necessary header files here for this problem.
// If additional header files are needed in your program, please import here
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char* argv[])
{
    int M, N; cin >> M >> N;
    int X; cin >> X;
    vector<int> requests(X);
    int total = 0;
    for(int i = 0; i < X;++i){
        cin >> requests[i];
        total += requests[i];
    }
    
    if(X<=M){
        int sum = total - N;
        if(sum > 0) cout << sum << endl;
        else cout << 0 << endl;
        return 0;
    }
    int l = 0, r = 0, sum = 0;
    int lost = 0;
  
    while(r<X){
        sum += requests[r];
        while(r-l+1 > M)
            sum -= requests[l++];
        if(sum > N){
            requests[r] -= sum - N;
            lost += sum - N;
            sum = N;
        }
        ++r;
    }
    cout << lost << endl;
    return 0;
}
