#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;   

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
private:
    Node* quadTree(vector<vector<int>>& grid, int x, int y, int offset){
        if(offset<=0) return nullptr;
        for(int i = x; i < x+offset; ++i)
            for(int j = y; j < y+offset; ++j)
                if(grid[i][j]!=grid[x][y]) // !isLeaf
                    return new Node(false, false,
                        quadTree(grid, x, y, offset/2),
                        quadTree(grid, x, y+offset/2, offset/2),
                        quadTree(grid, x+offset/2, y, offset/2),
                        quadTree(grid, x+offset/2, y+offset/2, offset/2)
                    );
        return new Node(grid[x][y], true, nullptr, nullptr, nullptr, nullptr); // isLeaf
    }

public:
    Node* construct(vector<vector<int>>& grid) {
       return quadTree(grid, 0, 0, grid.size());
    }
};