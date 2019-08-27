class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> ans;
        vector<int> q, w;
        for(auto &str: queries) q.push_back(f(str));
        for(auto &str: words) w.push_back(f(str));
        // for(auto a: q) cout<<a<<" "; cout<<endl;
        // for(auto a: w) cout<<a<<" "; cout<<endl;
        // sort(w.begin(), w.end());
        for(auto a: q){
            // auto itor = prev(upper_bound(w.begin(), w.end(), a));
            // ans.push_back(distance(w.end(), itor));
            int counter = 0;
            for(auto b: w) if(a < b) counter++;
            ans.push_back(counter);
        }
        return ans;
    }
    
private:
    int f(string &str){
        char cc = *min_element(str.begin(), str.end());
        int ans = 0;
        for(auto c: str) if(c == cc) ans++;
        return ans;
    }
};