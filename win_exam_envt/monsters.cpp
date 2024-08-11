#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n; // 怪物数量
    cin >> n;
    
    vector<int> monsters(n); // 怪物的血量
    for (int i = 0; i < n; i++) {
        cin >> monsters[i];
    }
    
    int totalAttacks = 0; // 总攻击次数
    
    while (!monsters.empty()) {
        int minHealth = monsters[0];
        int minIndex = 0;
        
        // 找到血量最少的怪物
        for (int i = 1; i < monsters.size(); i++) {
            if (monsters[i] < minHealth) {
                minHealth = monsters[i];
                minIndex = i;
            }
        }
        
        totalAttacks += minHealth; // 普通攻击对最少血量的怪物造成伤害
        monsters.erase(monsters.begin() + minIndex); // 击杀血量最少的怪物
        
        // 触发“转圈圈”
        for (int i = 0; i < monsters.size(); i++) {
            if (monsters[i] <= minHealth) {
                monsters[i]--; // 怪物的血量减1
            }
        }
    }
    
    cout << totalAttacks << endl;
    
    return 0;
}