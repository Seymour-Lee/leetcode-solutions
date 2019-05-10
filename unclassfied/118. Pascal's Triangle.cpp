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