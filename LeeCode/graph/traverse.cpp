/******************************************************************************************
 * Graph in C++
 * Juncheng Chen, j.c.chen.cn9@gmail.com
 * December 7, 2022
 ******************************************************************************************/

#include <limits.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

struct Edge
{
    int begin; //对应顶点索引
    int end;
    int weight = 1;
};

/******************************************************************************************
 * 无向简单图的邻接矩阵表示
 ******************************************************************************************/
template<class VertexType>
struct AdjMatGraph
{
    //std::vector<VertexType> vexs;
    std::vector<std::vector<int>> adjMat;
    int numEdges;

    AdjMatGraph(const std::vector<VertexType>& vexs, const std::vector<Edge>& edges)
        : numEdges(edges.size())
    {
        const int len = vexs.size();
        adjMat.resize(len, std::vector<int>(len, INT_MAX));
        for(int i = 0; i < len; ++i) adjMat[i][i] = 0;
        for(int k = 0; k < numEdges; ++k){
            int i = edges[k].begin, j = edges[k].end;
            adjMat[i][j] = adjMat[j][i] = edges[k].weight;
        }
    }
    int numVex(void) const {return adjMat.size();}
};

/******************************************************************************************
 * 无向图的邻接表表示
 ******************************************************************************************/
struct EdgeNode //边表结点
{
    int adjvex; //邻接点域，存储邻接顶点对应的下标
    int weight = 1;
    EdgeNode* next;
};

template <class VertexType>
struct VertexNode //顶点表结点
{
    VertexType data; //对应顶点索引
    EdgeNode* firstEdge;
    VertexNode(const VertexType& data_)
        : data(data_), firstEdge(nullptr) {}
    VertexNode(VertexType&& data_)
        : data(std::move(data_)), firstEdge(nullptr) {}
};

template<class VertexType>
struct AdjListGraph
{
    
    std::vector<VertexNode<VertexType>> adjList;
    int numEdges;

    AdjListGraph(const std::vector<VertexType>& vexs, const std::vector<Edge>& edges)
        : numEdges(edges.size())
    {
        const int len = vexs.size();
        adjList.reserve(len);
        for (const auto& vex : vexs)
            adjList.emplace_back(vex);
        for (int k = 0; k < numEdges; ++k)
        {
            int i = edges[k].begin;
            int j = edges[k].end;
            int weight = edges[k].weight;

            EdgeNode* edgeNode = new EdgeNode();
            edgeNode->adjvex = j;
            edgeNode->weight = weight;
            edgeNode->next = adjList[i].firstEdge;
            adjList[i].firstEdge = edgeNode;

            edgeNode = new EdgeNode();
            edgeNode->adjvex = i;
            edgeNode->weight = weight;
            edgeNode->next = adjList[j].firstEdge;
            adjList[j].firstEdge = edgeNode;
        }
    }

    ~AdjListGraph()
    {
        for (int i = 0; i < (int)adjList.size(); ++i)
        {
            EdgeNode* cur = adjList[i].firstEdge;
            while (cur)
            {
                EdgeNode* next = cur->next;
                delete cur;
                cur = next;
            }
        }
    }

    int numVex(void) const {return adjList.size();}
};

/******************************************************************************************
 * 无向图的遍历
 ******************************************************************************************/
static std::vector<bool> visited;

template <class T>
void DFS(const AdjMatGraph<T>& graph, int i)
{
    visited[i] = true;
    //std::cout << graph.vexs[i] << " ";
    for (int j = 0; j < graph.numVex(); ++j)
        if (graph.adjMat[i][j] == 1 && !visited[j]) DFS(graph, j);
}

template <class T>
void BFS(const AdjMatGraph<T>& graph, int i)
{
    std::queue<int> vexQue;
    visited[i] = true;
    //std::cout << graph.vexs[i] << " ";
    vexQue.push(i);
    while (!vexQue.empty())
    {
        i = vexQue.front(); vexQue.pop();
        for (int j = 0; j < graph.numVex(); ++j)
        {
            if (graph.adjMat[i][j] == 1 && !visited[j])
            {
                visited[j] = true;
                //std::cout << graph.vexs[j] << " ";
                vexQue.push(j);
            }
        }
    }
}


template <class T>
void DFS(const AdjListGraph<T>& graph, int i)
{
    visited[i] = true;
    std::cout << graph.adjList[i].data << " ";
    const auto* cur = graph.adjList[i].firstEdge;
    while (cur)
    {
        if (!visited[cur->adjvex])
        {
            DFS(graph, cur->adjvex);
        }
        cur = cur->next;
    }
}

template <class T>
void BFS(const AdjListGraph<T>& graph, int i)
{
    std::queue<int> vexQue;
    visited[i] = true;
    std::cout << graph.adjList[i].data << " ";
    vexQue.push(i);
    while (!vexQue.empty())
    {
        i = vexQue.front(); vexQue.pop();
        const auto* cur = graph.adjList[i].firstEdge;
        while (cur)
        {
            int j = cur->adjvex;
            if (!visited[j])
            {
                visited[j] = true;
                std::cout << graph.adjList[j].data << " ";
                vexQue.push(j);
            }
            cur = cur->next;
        }
    }
}

template <class Graph>
void DFSTraverse(const Graph& graph)
{
    visited.resize(graph.numVex());
    std::fill(visited.begin(), visited.end(), false);
    for (int i = 0; i < graph.numVex(); ++i)
        if (!visited[i]) DFS(graph, i); // 可能存在多个连通分支   
}

template <class Graph>
void BFSTraverse(const Graph& graph)
{
    visited.resize(graph.numVex());
    std::fill(visited.begin(), visited.end(), false);
    for (int i = 0; i < graph.numVex(); ++i)
        if (!visited[i]) BFS(graph, i); //可能存在多个连通分支  
}

int main(int argc, char* argv[])
{
    
    AdjMatGraph<char> amGraph({'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'},
    {
        {0, 1}, {0, 5}, {1, 2}, {1, 8}, {1, 6},
        {2, 3}, {2, 8}, {3, 4}, {3, 6}, {3, 7},
        {3, 8}, {4, 5}, {4, 7}, {5, 6}, {6, 7}
    });
    
    DFSTraverse(amGraph);
    //std::cout << std::endl;
    BFSTraverse(amGraph);
    //std::cout << std::endl;
    
    AdjListGraph<char> alGraph({'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'},
    {
        {0, 1}, {0, 5}, {1, 2}, {1, 8}, {1, 6},
        {2, 3}, {2, 8}, {3, 4}, {3, 6}, {3, 7},
        {3, 8}, {4, 5}, {4, 7}, {5, 6}, {6, 7}
    });
    DFSTraverse(alGraph);
    std::cout << std::endl;
    BFSTraverse(alGraph);
    std::cout << std::endl;

    return 0;
}
