class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int K) {
        double l = 0, r = 1e8;
        while(r-l > 1e-6){
            double m = l + (r - l) / 2.0;
            if(p(m, stations, K)) r = m;
            else l = m;
        }
        return l;
    }
    
private:
    bool p(double d, vector<int> s, int k){
        int used = 0;
        for(int i = 0; i < s.size()-1; i++){
            used += (int)(s[i+1] - s[i])/d;
        }
        return used <= k;
    }
};