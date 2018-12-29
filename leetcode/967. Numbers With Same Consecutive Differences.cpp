class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        if(N == 1) return {0,1,2,3,4,5,6,7,8,9};
        queue<string> q;
        q.push("");
        while(N--){
            int size = q.size();
            while(size--){
                string str = q.front(); q.pop();
                for(char i = '0'; i <= '9'; i++){
                    string next = str + i;
                    if(next.size() == 1){q.push(next); continue;}
                    char a = next.back();
                    char b = next[next.size()-2];
                    if(a-b == K || b-a == K) q.push(next);
                }
            }
        }
        vector<int> ans;
        while(q.empty() == false){
            string str = q.front(); q.pop();
            if(N == 1 || str[0] != '0') ans.push_back(stoi(str));
        }
        return ans;
    }
};