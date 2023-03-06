#include <iostream>
#include <vector>
using namespace std;
 

/* vec[] ---> Input Array
 * data[] ---> Temporary array to store current combination
 * start & end ---> Starting and Ending indexes in vec[]
 * idx ---> Current index in data[]
 * r ---> Size of a combination 
 */
void combination(const vector<int>& vec, vector<int>& data, int start, int end, int idx, int r)
{
    if (idx == r)
    {
        for (int j = 0; j < r; j++)
            cout << data[j] << " ";
        cout << endl;
        return;
    }
 
    for (int i = start; i <= end && end - i + 1 >= r - idx; i++)
    {
        data[idx] = vec[i];
        combination(vec, data, i+1, end, idx+1, r);
    }
}

int main (int argc, char* argv[])
{
    vector<int> vec = {1, 2, 3, 4, 5};
    const int r = 4;
    vector<int> data(r);
    combination(vec, data, 0, vec.size()-1, 0, r);
}
 