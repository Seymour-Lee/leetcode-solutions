class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        vector<string> ans; 
        vector<string> ans1 = {"0", "1", "8"};
        vector<string> ans2 = {"11", "69", "88", "96"};
        if(n == 1) return ans1;
        if(n == 2) return ans2;
        vector<string> even = {"00", "11", "69", "88", "96"};
        vector<string> odd = {"0", "1", "8"};
        for(int i = 3; i <= n; i++){
            int m = (i-1)/2;
            if(i%2) {
                for (auto s : ans2)
                      for (auto o : odd)
                          ans.push_back(s.substr(0, m) + o + s.substr(m));
            } else {
                for (auto s : ans1)
                    for (auto e : even)
                        ans.push_back(s.substr(0, m) + e + s.substr(m));              
            }
            ans1 = ans2;
            ans2 = ans;
            ans.clear();
        }
        return ans2;
    }
};