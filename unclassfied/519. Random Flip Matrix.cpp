class Solution {
public:
    Solution(int n_rows, int n_cols) {
        rows = n_rows;
        cols = n_cols;
        total = rows * cols;
        srand(time(0));
    }
    
    vector<int> flip() {
        vector<int> ans;
        int id = rand() % total;
        if(id2pos.find(id) != id2pos.end()){
            int pos = id2pos[id];
            ans = {pos / cols, pos % cols};
        }
        else{
            ans = {id / cols, id % cols};
        }        
        if(id2pos.find(total-1) != id2pos.end()){
            id2pos[id] = id2pos[total-1];
        }
        else{
            id2pos[id] = total-1;
        }
        total--;
        return ans;
    }
    
    void reset() {
        id2pos.clear();
        total = rows * cols;
    }
    
private:
    int rows, cols;
    int total;
    map<int, int> id2pos;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj.flip();
 * obj.reset();
 */

class Solution {
public:
    Solution(int n_rows, int n_cols) {
        rows = n_rows;
        cols = n_cols;
        total = rows * cols;
        srand(time(0));
    }
    
    vector<int> flip() {
        vector<int> ans;
        int id = rand() % total;
        if(id2pos.find(id) != id2pos.end()){
            int pos = id2pos[id];
            ans = {pos / cols, pos % cols};
        }
        else{
            ans = {id / cols, id % cols};
        }        
        if(id2pos.find(total-1) != id2pos.end()){
            id2pos[id] = id2pos[total-1];
        }
        else{
            id2pos[id] = total-1;
        }
        total--;
        return ans;
    }
    
    void reset() {
        id2pos.clear();
        total = rows * cols;
    }
    
private:
    int rows, cols;
    int total;
    unordered_map<int, int> id2pos;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj.flip();
 * obj.reset();
 */