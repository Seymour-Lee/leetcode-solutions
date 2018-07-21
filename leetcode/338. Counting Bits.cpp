class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result = {0};
        int mask = 1;
        for(int i = 1; i <= num; i++){
            if(mask * 2 == i) mask = mask * 2;
            result.push_back(result[i % mask] + 1);
        }
        return result;
    }
};