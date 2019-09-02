class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int l = 1;
        int r = pow(10, 9);
        while(l < r){
            int m = l + (r - l) / 2;
            if(valid(piles, H, m) == false) l = m + 1;
            else r = m;
        }
        return l;
    }
    
private:
    bool valid(vector<int> piles, int H, int k){
        int time = 0;
        for(auto p: piles){
            time += (p - 1) / k + 1;
        }
        return time <= H;
    }
};

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        while(l < r){
            int k = l + (r - l) / 2;
            int h = hours(piles, k);
            if(h > H) l = k+1;
            else r = k;
        }
        return l;
    }
    
private:
    int hours(vector<int> &p, double k){
        int ans = 0;
        for(auto a: p) ans += ceil(a/k);
        return ans;
    }
};