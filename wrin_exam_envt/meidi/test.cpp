#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> ivec(5,1);

    int i=1;
    for(vector<int>::const_iterator iter=ivec.begin();iter!=ivec.end(); iter++){
        cout << *it << endl;
    }
    
    return 0;
}