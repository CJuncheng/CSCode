#include <iostream>
#include <vector>
#include <map>
#include<queue>
#include <utility> // pair
#include <memory>

using namespace std;

int main(int argc, char **argv)
{
    vector<int> arr = {4,9,0,5,1};
    int tmp = 0;
    for(int i = 0; i < 5; ++i){
        tmp = (tmp*10 + arr[i]);
    }
    cout << tmp << endl;
    return 0;
}

