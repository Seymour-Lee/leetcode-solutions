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