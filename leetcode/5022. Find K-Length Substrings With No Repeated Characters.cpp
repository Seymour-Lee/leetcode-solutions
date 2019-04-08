class Solution {
public:
    int numKLenSubstrNoRepeats(string S, int K) {
        if(S.size() < K) return 0;
        vector<int> counter(26, 0);
        int ans = 0;
        int i = 0;
        while(i < K) counter[S[i++]-'a']++;
        // if(count(counter.begin(), counter.end(), 1) == K) {
        //     ans++;
        //     cout<<S.substr(0, K)<<endl;
        // }
        while(i < S.size()){
            if(count(counter.begin(), counter.end(), 1) == K) {
                ans++;
                // cout<<S.substr(i-K, K)<<endl;
            }
            counter[S[i-K]-'a']--;
            counter[S[i]-'a']++;
            i++;
        }
        if(count(counter.begin(), counter.end(), 1) == K) {
            ans++;
            // cout<<S.substr(i-K, K)<<endl;
        }
        return ans;
    }
};