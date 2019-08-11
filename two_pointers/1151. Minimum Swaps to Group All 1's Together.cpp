class Solution {
public:
    int minSwaps(vector<int>& data) {
        int counter = 0;
        for(auto a: data) if(a == 1) counter++;
        int l = 0, r = counter;
        int maxval = 0;
        int cur = 0;
        for(int i = 0; i < r; i++) if(data[i] == 1) cur++, maxval++;
        while(r < data.size()){
            cur = cur + data[r] - data[l];
            maxval = max(maxval, cur);
            l++, r++;
        }
        return counter - maxval;
    }
};