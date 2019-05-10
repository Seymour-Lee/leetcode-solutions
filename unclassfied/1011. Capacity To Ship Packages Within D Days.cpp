class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int l = 0, r = 0;
        for(auto w: weights) l = max(w, l), r += w;
        while(l < r){
            int m = l + (r - l) / 2;
            int days = 1;
            int curweight = 0;
            for(int i = 0; i < weights.size() && days <= D; curweight += weights[i++]){
                if(curweight + weights[i] > m) curweight = 0, days++;
            }
            if(days > D) l = m + 1;
            else r = m;
        }
        return l;
    }
};

