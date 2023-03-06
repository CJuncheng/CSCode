
#include <vector>
#include <iostream>

/******************************************************************************************
 * 有向图的邻接矩阵表示
 ******************************************************************************************/
struct Edge
{
    int begin; //对应顶点索引
    int end;
    int weight = 1;
};
struct AdjMatGraph
{
    std::vector<std::vector<int>> adjMat;
    int numEdges;

    AdjMatGraph(const std::vector<int>& vexs, const std::vector<Edge>& edges)
        : numEdges(edges.size())
    {
        const int len = vexs.size();
        adjMat.resize(len, std::vector<int>(len, INT_MAX));
        for(int i = 0; i < len; ++i) adjMat[i][i] = 0;
        for(int k = 0; k < numEdges; ++k){
            int i = edges[k].begin, j = edges[k].end;
            adjMat[i][j] = edges[k].weight;
        }
    }
    int numVex(void) const {return adjMat.size();}
};


void printMatrix(std::vector<std::vector<int>> matrix)
{
    std::cout << "printfMatrix: " << std::endl;
    for(auto& vec : matrix){
        for(auto& val : vec)
            std::cout << val <<" ";
        std::cout << std::endl;
    }
}

void printPath(int u, int v, const std::vector<std::vector<int>>& Path) // 打印任意两点之间的最短路径
{
   
    if(Path[u][v]==-1) {
        std::cout << "<" << u << "," << v << ">" << std::endl; 
        return;
    }
    int mid = Path[u][v];
    printPath(u, mid, Path);
    printPath(mid, v, Path);
}

void floyd(const std::vector<std::vector<int>>& adjMat)
{
    const int n = adjMat.size();
    std::vector<std::vector<int>> A(adjMat);  // 最短距离矩阵
    std::vector<std::vector<int>> Path(n, std::vector<int>(n, -1)); // 路径矩阵
    for(int v = 0; v < n; ++v) // 依次访问对角线元素对应的坐标
        for(int i = 0; i < n; ++i){ // v所在的行和列不需要访问，v行和列中的 INF 对应的行与列也不需要访问
            if(i==v) continue;
            for(int j = 0; j < n; ++j){
                if(j==v) continue;
                if(A[i][v] < INT_MAX && A[v][j] < INT_MAX && A[i][j] > A[i][v]+A[v][j]){
                    A[i][j] = A[i][v]+A[v][j];
                    Path[i][j] = v;
                }
            }
        }

    //printMatrix(A);
    //printMatrix(Path);
    printPath(1, 0, Path);
}

int main(int argc, char* argv[])
{
    std::vector<int> vexs = {0, 1, 2, 3};
    AdjMatGraph amGraph(vexs,
    {
        {0, 1, 5}, {0, 3, 7}, {1, 3, 2}, {1, 2, 4}, {3, 2, 1},
        {2, 0, 3}, {2, 1, 3}, {2, 3, 2}
    });
    floyd(amGraph.adjMat);

    return 0;
}