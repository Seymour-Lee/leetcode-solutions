class Solution {
public:
    int kSimilarity(string A, string B) {
        queue<pair<string, int>> q;
        q.push({A, 0});
        unordered_set<string> seen;
        int ans = 0;
        while(q.empty() == false){
            int size = q.size();
            while(size--){
                auto p = q.front(); q.pop();
                string str = p.first;
                int i = p.second;
                if(str == B) return ans;
                while(str[i] == B[i]) i++;
                for(int j = i+1; j < str.size(); j++){
                    if(str[j] == B[i] && str[j] != B[j]){
                        swap(str[i], str[j]);
                        if(seen.find(str) == seen.end()){
                            q.push({str, i+1});
                            seen.insert(str);
                        }
                        swap(str[i], str[j]);
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};