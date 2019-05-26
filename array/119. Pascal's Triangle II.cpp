class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        result.push_back(1);
        if(rowIndex == 0) return result;
        vector<int> last;
        for(int i = 1; i <= rowIndex; i++){
            last = result;
            result.clear();
            result.push_back(1);
            for(int j = 1; j < last.size(); j++){
                result.push_back(last[j-1] + last[j]);
            }
            result.push_back(1);
        }
        return result;
    }
};

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0) return {1};
        if(rowIndex == 1) return {1, 1};
        vector<int> ans = {1, 1};
        for(int i = 2; i <= rowIndex; i++){
            vector<int> last = ans;
            ans = {1};
            for(int i = 0; i < last.size()-1; i++) ans.push_back(last[i]+last[i+1]);
            ans.push_back(1);
        }
        return ans;
    }
};