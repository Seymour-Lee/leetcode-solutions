class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int ans = 0;
        int n = row.size();
        vector<int> ptn(n, 0);
        vector<int> pos(n, 0);
        for(int i = 0; i < n; i++){
            ptn[i] = (i%2 == 0? i+1: i-1);
            pos[row[i]] = i;
        }
        for(int i = 0; i < n; i++){
            for(int j = ptn[pos[ptn[row[i]]]]; i != j; j = ptn[pos[ptn[row[i]]]]){
                swap(row[i], row[j]);
                swap(pos[row[i]], pos[row[j]]);
                ans++;
            }
        }
        return ans;
    }
};