class Solution {
public:
    vector<int> grayCode(int n) {
        if(n == 0) return vector<int>{0};
        vector<int> result = grayCode(n-1);
        int size = result.size();
        for(int i = 0; i < size; i++){
            result.push_back(result[size-i-1] + pow(2, n-1));
        }
        return result;
    }
};