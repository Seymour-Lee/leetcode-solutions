/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        Node *result;
        result = dfs(grid, 0, 0, grid.size());
        return result;
    }
    
private:
    Node* dfs(vector<vector<int>>& grid, int i, int j, int m){
        if(m == 0) return nullptr;
        Node *root = new Node();
        if(isLeaf(grid, i, j, m) == false){
            root->isLeaf = false;
            root->val = true;
            root->topLeft = dfs(grid, i, j, m/2);
            root->topRight = dfs(grid, i, j+m/2, m/2);
            root->bottomLeft = dfs(grid, i+m/2, j, m/2);
            root->bottomRight = dfs(grid, i+m/2, j+m/2, m/2);
        }
        else{
            root->isLeaf = true;
            root->val = grid[i][j];
            root->topLeft = nullptr;
            root->topRight = nullptr;
            root->bottomLeft = nullptr;
            root->bottomRight = nullptr;
        }
        return root;
    }
    
    bool isLeaf(vector<vector<int>>& grid, int i, int j, int m){
        bool val = grid[i][j];
        for(int row = i; row < i + m; row++){
            for(int col = j; col < j + m; col++){
                if(grid[row][col] != val){
                    return false;
                }
            }
        }
        return true;
    }
};