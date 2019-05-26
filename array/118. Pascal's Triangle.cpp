class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if(numRows == 0) return result;
        vector<int> cur = {1};
        vector<int> last;
        result.push_back(cur);
        for(int i = 1; i < numRows; i++){
            cur.clear();
            cur.push_back(1);
            last = result[i-1];
            for(int j = 1; j < last.size(); j++){
                cur.push_back(last[j-1] + last[j]);
            }
            cur.push_back(1);
            result.push_back(cur);
        }
        return result;
    }
};

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 0) return {};
        if(numRows == 1) return {{1}};
        if(numRows == 2) return {{1}, {1, 1}};
        vector<vector<int>> ans = {{1}, {1, 1}};
        for(int i = 3; i <= numRows; i++){
            vector<int> cur = {1};
            vector<int> last = ans.back();
            for(int i = 0; i < last.size()-1; i++) cur.push_back(last[i]+last[i+1]);
            cur.push_back(1);
            ans.push_back(cur);
        }
        return ans;
    }
};