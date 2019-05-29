class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        if(oldColor != newColor) dfs(image, sr, sc, oldColor, newColor);
        return image;
    }
    
private:
    void dfs(vector<vector<int>>& image, int i, int j, int oldColor, int newColor){
        if(image[i][j] == oldColor) image[i][j] = newColor;
        else return;
        if(i-1 >= 0) dfs(image, i-1, j, oldColor, newColor);
        if(j-1 >= 0) dfs(image, i, j-1, oldColor, newColor);
        if(i+1 < image.size()) dfs(image, i+1, j, oldColor, newColor);
        if(j+1 < image[0].size()) dfs(image, i, j+1, oldColor, newColor);
    }
};

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        dfs(image, sr, sc, newColor, image[sr][sc]);
        return image;
    }
    
private:
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    void dfs(vector<vector<int>>& g, int x, int y, int c, int o){
        if(x < 0 || x >= g.size() || y < 0 || y >= g[0].size() || c == o || g[x][y] != o) return;
        g[x][y] = c;
        for(auto dir: dirs) dfs(g, x+dir[0], y+dir[1], c, o);
    }
};