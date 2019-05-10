class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> result;
        for(int i = 1; i < n-k; i++) result.push_back(i);
        for(int i = 0; i <= k; i++){
            result.push_back(i % 2? n-i/2: n-k+i/2);
        }
        return result;
    }
};