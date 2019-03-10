class Solution {
public:
    int clumsy(int N) {
        if(N == 3) return 6;
        if(N == 2) return 2;
        if(N == 1) return 1;
        vector<int> ns;
        while(N >= 4) ns.push_back(N-3), N -= 4;
        // for(auto n: ns) cout<<n<<" "; cout<<endl;
        long long ans = 0.0;
        if(N == 3) ans = -6;
        if(N == 2) ans = -2;
        if(N == 1) ans = -1;
        if(ns.size() > 0) ans += 2*ns[0] + 4 + 2/(ns[0]+1);
        for(int i = 1; i < ns.size(); i++){
            // cout<<ans<<endl;
            ans = ans - (ns[i]+3)*(ns[i]+2)/(ns[i]+1) + ns[i];
        }
        
        return ans;
    }
};