#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool lemonadeChange(vector<int>& bills) {
    int five = 0, ten = 0, twenty = 0;
    for(int & bill : bills) {
        switch(bill) {
            case 5: ++five; break;
            case 10: 
                if(five <= 0) return false;
                ++ten; --five; break;
            case 20: 
                if(five > 0&& ten > 0) {
                    --five; --ten; ++twenty;
                } else if (five >= 3) {
                    five -= 3;
                    ++twenty;
                } else return false;
            //default: break;
        }
    }
    return true;

}
