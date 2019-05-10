class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if(n == 0) return 0;
        int l = 0, r = n-1;
        while(l+1 < r){
            int m = l + (r - l) / 2;
            if(citations[m] == n-m) return n-m;
            else if(citations[m] > n-m) r = m;
            else l = m;
        }
        if(citations[l] >= n-l) return n-l;
        if(citations[r] >= n-r) return n-r;
        return 0;
    }
};