class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        auto f = [](int a, int b){
            int aa = 0, bb = 0;
            for(int i = 0; i < 32; i++){
                if((a >> i) & 1) aa++;
                if((b >> i) & 1) bb++;
            }
            if(aa == bb) return a < b;
            return aa < bb;
        };
        sort(arr.begin(), arr.end(), f);
        return arr;
    }
};