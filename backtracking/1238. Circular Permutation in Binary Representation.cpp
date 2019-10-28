class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> ans = grayCode(n);
        int i = 0;
        while(ans[i] != start) ans.push_back(ans[i++]);
        return vector<int>(ans.begin()+i, ans.end());
    }
    
private:
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