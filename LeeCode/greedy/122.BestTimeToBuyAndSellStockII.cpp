#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int maxProfit(vector<int>& prices) {
    int profit = 0;
    for(int i = 1; i < (int)prices.size(); ++i) 
        profit += max(prices[i]-prices[i-1], 0);
    return profit;
}

int main (int argc, char* argv[])
{
   
    vector<int> iVec = {1,2};
    int ret = maxProfit(iVec);
    cout << "Result: " << ret << endl;
    
    return 0;
}