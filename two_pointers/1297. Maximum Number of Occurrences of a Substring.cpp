class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int ans = 0;
        for(int size = minSize; size <= maxSize; size++){
            // cout<<size<<endl;
            run(s, maxLetters, size);
        }
        for(auto &p: s2c) ans = max(ans, p.second);
        return ans;
    }
    
private:
    unordered_map<string, int> s2c;
    
    void run(string &str, int maxletters, int k){
        vector<int> counter(26, 0);
        int letters = 0;
        int l = 0, r = 0;
        while(r < k) counter[str[r]-'a']++, r++;
        for(auto num: counter) if(num != 0) letters++;
        if(letters <= maxletters){
            string s = str.substr(l, r-l);
            // cout<<s<<endl;
            s2c[s]++;
        }
        while(l <= r && r < str.size()){
            // cout<<l<<" "<<r<<endl;
            counter[str[l]-'a']--;
            if(counter[str[l]-'a'] == 0) letters--;
            counter[str[r]-'a']++;
            if(counter[str[r]-'a'] == 1) letters++;
            l++, r++;
            if(letters <= maxletters){
                string s = str.substr(l, r-l);
                // cout<<s<<endl;
                s2c[s]++;
            }
        }
        // cout<<endl;
    }
};