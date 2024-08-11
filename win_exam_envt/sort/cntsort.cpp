#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void countingSort(vector<int> &vec) {
	int n = vec.size();
    int mxval = *max_element(vec.begin(), vec.end());

	vector<int> count(mxval+1, 0);
	vector<int> tmp(vec);
	for (auto x : vec) ++count[x];
	for (int i = 1; i <= mxval; ++i)
		count[i] += count[i - 1];
	for (int i = n - 1; i >= 0; --i) {
		vec[count[tmp[i]] - 1] = tmp[i];
		--count[tmp[i]];				
	}
}
 
int main()
{
	vector<int> vec = {2, 5, 9, 100, 8, 102, 2, 6, 1, 11, -5};
	
	countingSort(vec);
	for (auto x : vec)
		cout << x << " ";
	cout << endl;
	return 0;
}