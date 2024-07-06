#include <vector>
#include <algorithm>
using namespace std;

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() : val(false), isLeaf(false), topLeft(nullptr), topRight(nullptr), bottomLeft(nullptr), bottomRight(nullptr) {}

    Node(bool _val, bool _isLeaf) : val(_val), isLeaf(_isLeaf), topLeft(nullptr), topRight(nullptr), bottomLeft(nullptr), bottomRight(nullptr) {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) 
        : val(_val), isLeaf(_isLeaf), topLeft(_topLeft), topRight(_topRight), bottomLeft(_bottomLeft), bottomRight(_bottomRight) {}
};

class Solution {
private:
    template<typename T>
    bool allEqual(const T&) {
        return true;
    }

    template<typename T, typename ...Args>
    bool allEqual(const T& first, const Args&... args) {
        return ((first == args) && ...);
    }

    Node* construct(vector<vector<int>>& grid, int startRow, int startCol, int length) {
        if (length == 1) {
            return new Node(grid[startRow][startCol], true);
        }

        int newLength = length / 2;
        Node* topLeft = construct(grid, startRow, startCol, newLength);
        Node* topRight = construct(grid, startRow, startCol + newLength, newLength);
        Node* bottomLeft = construct(grid, startRow + newLength, startCol, newLength);
        Node* bottomRight = construct(grid, startRow + newLength, startCol + newLength, newLength);

        if (topLeft && topRight && bottomLeft && bottomRight &&
            allEqual(topLeft->val, topRight->val, bottomLeft->val, bottomRight->val) &&
            allEqual(topLeft->isLeaf, topRight->isLeaf, bottomLeft->isLeaf, bottomRight->isLeaf) &&
            topLeft->isLeaf) {
            return new Node(topLeft->val, true);
        }
        return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
    }

public:
    Node* construct(vector<vector<int>>& grid) {
        int length = grid.size();
        return construct(grid, 0, 0, length);
    }
};

/*----------------- ANOTHER APPROACH -------------------------*/
class Solution {
public:

    bool isAllSame(vector<vector<int>>& grid, int x, int y, int n) {
        int val = grid[x][y];
        
        for(int i = x; i < x + n; i++) {
            for(int j = y; j< y + n; j++) {
                if(grid[i][j] != val)
                    return false;
            }
        }
        return true;
    }

    Node* solve(vector<vector<int>>& grid, int x, int y, int n) {
        if (isAllSame(grid, x, y, n)) {
            return new Node(grid[x][y], true);
        } else {
            Node * root = new Node(1, false);

            root->topLeft = solve(grid, x, y, n/2);
            root->topRight = solve(grid, x, y+n/2, n/2);
            root->bottomLeft = solve(grid, x+n/2, y, n/2);
            root->bottomRight = solve(grid, x+n/2, y+n/2, n/2);
            
            return root;
        }
    }
    

    Node* construct(vector<vector<int>>& grid) {
       return solve(grid, 0, 0, grid.size());
    }
};
