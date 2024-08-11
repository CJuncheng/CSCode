
// we have defined the necessary header files here FOR this problem.
// IF additional header files are needed IN your program, please IMPORT here.
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;
int main()
{
    string strBooks; cin >> strBooks;
    stringstream ss(strBooks);
    string tmp;
    vector<int> books;
    while(getline(ss, tmp, ','))
        books.push_back(stoi(tmp));   
    const int n = books.size();
    int time = 1;
    sort(books.begin(), books.end());
    int happyTime = 0, sum = 0;
  
    for(int i=books.size()-1;i>=0;i--){
        if(sum+books[i]<0)  break;
        sum+=books[i];
        happyTime+=sum;
    }
    cout << happyTime << endl;
    return 0;
}