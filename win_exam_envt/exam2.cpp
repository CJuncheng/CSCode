/*#include <iostream>
#include <vector>
#include <map>
#include<queue>
#include <utility> // pair
#include <memory>

using namespace std;

int main(int argc, char **argv)
{
    int n, m, start_x, start_y, end_x, end_y;
    cin >> n >> m;
    cin >> start_x >> start_y >> end_x >> end_y;
    vector<vector<char>> mp(n+1, vector<char>(m+1));
    vector<vector<int>> dist(n+1, vector<int>(m+1, -1)); // -1 表示未访问
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            cin >> mp[i][j];

    queue<pair<int, int>> que;
    que.push(make_pair(start_x, start_y));
    dist[start_x][start_x] = 0;

    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

    while(!que.empty()){
        auto point = que.front(); que.pop();
        for(int i = 0; i < 4; ++i){
            int x_new = point.first + dirs[i][0], y_new = point.second + dirs[i][1];
            if(x_new>=1 && x_new <= n && y_new>=1 && y_new<=m && dist[x_new][y_new] == -1 && mp[x_new][y_new] == '.'){
                dist[x_new][y_new] = dist[point.first][point.second] + 1;
                mp[x_new][y_new] == '*';
                que.push(make_pair(x_new, y_new));
            }
        }
    }
    cout << dist[end_x][end_y] << endl;
    return 0;
}
*/

#include <iostream>
#include <vector>
#include <map>
#include<queue>
#include <utility> // pair
#include <memory>

using namespace std;

int main(int argc, char **argv)
{
    int n, m, start_x, start_y, end_x, end_y;
    cin >> n >> m;
    cin >> start_x >> start_y >> end_x >> end_y;
    --start_x, --start_y, --end_x, --end_y;
    vector<vector<char>> mp(n, vector<char>(m));
    int res = 0;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            cin >> mp[i][j];

    queue<pair<int, int>> que;
    que.push(make_pair(start_x, start_y));
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    while(!que.empty()){
        int size = que.size();
        for(int i = 0; i < size; ++i){
            auto point = que.front(); que.pop();
            if(point.first == end_x && point.second == end_y) { 
                cout << res << endl;
                return 0;
            }
            for(int i = 0; i < 4; ++i){
                int x_new = point.first + dirs[i][0], y_new = point.second + dirs[i][1];
                if(x_new>=0 && x_new < n && y_new>=0 && y_new<m && mp[x_new][y_new] == '.'){
                    mp[x_new][y_new] == '*';
                    que.push(make_pair(x_new, y_new));
                }
            }
        }
        ++res;
    }
    cout << -1 << endl;
    
    return 0;
}

