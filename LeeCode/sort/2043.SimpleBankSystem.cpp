#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
class Bank {
private:
    bool isLegalAccount(const int& account){
        return account>0 && account <= (int)balance.size();
    }
public:
    vector<long long> balance;
    Bank(vector<long long>& _balance) : balance(_balance){}
    
    bool transfer(int account1, int account2, long long money) {
        if(isLegalAccount(account2)&&withdraw(account1, money))
            return deposit(account2, money);
        return false;
    }
    
    bool deposit(int account, long long money) {
        if(!isLegalAccount(account)) return false;
        balance[account-1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(!isLegalAccount(account) || balance[account-1] < money)
            return false;
        balance[account-1] -= money;
        return true;
    }
};