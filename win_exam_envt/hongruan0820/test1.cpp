#include <iostream>
#include <vector>
using namespace std;
/*
int main(int argc, char* argv[]){
    int n = 5; //cin >> n;
    vector<int> vec(n);
    for(int i = 0; i < n; ++i) 
        vec[i] = i+1;
    int cnt = 1, idx = 0;
    
    while(vec.size() > 1){
        //++cnt;
        if(cnt == 2)
            vec.erase(vec.begin() + idx);
        if(cnt == 4) cnt = 1;
        idx = (idx+1)%vec.size();
        ++cnt;
    }


    cout << vec[0] << endl;
    return 0;
}
*/

#include <iostream>
#include <list>

int main() {
    int n;
    std::cin >> n;

    std::list<int> team;
    for (int i = 1; i <= n; i++) {
        team.push_back(i);
    }

    std::list<int>::iterator curr = team.begin();
    int count = 1;

    while (team.size() > 1) {
        if (count % 4 == 2) {
            curr = team.erase(curr);
            if (curr == team.end()) {
                curr = team.begin();
            }
        } else {
            curr++;
            if (curr == team.end()) {
                curr = team.begin();
            }
        }
        count++;
    }

    std::cout  << team.front() << std::endl;

    return 0;
}
