#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int n;
    std::cin >> n;
    
    std::unordered_map<int, std::unordered_map<int, int>> points;
    std::vector<int> centerPoints;
    
    for (int i = 0; i < n; i++) {
        int x, y;
        std::cin >> x >> y;
        
        points[x][y]++;
    }
    
    for (const auto& it1 : points) {
        for (const auto& it2 : it1.second) {
            int x = it1.first;
            int y = it2.first;

            int flag1 = false, flag2 = false, flag3 = false, flag4 = false;

            for(auto& tmp : points[x]){
                if(tmp.first < x) flag1 = true;
                if(tmp.first > x) flag2 = true;
            }

            for(auto& tmp : points[y]){
                if(tmp.first < x) flag3 = true;
                if(tmp.first > x) flag4 = true;
            }


            
            if (points[x-1][y] > 0 && points[x+1][y] > 0 && points[x][y-1] > 0 && points[x][y+1] > 0) {
                centerPoints.push_back(it2.second);
            }
        }
    }
    
    int centerCount = centerPoints.size();
    std::cout << centerCount << std::endl;
    
    return 0;
}