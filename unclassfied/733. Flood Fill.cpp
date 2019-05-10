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