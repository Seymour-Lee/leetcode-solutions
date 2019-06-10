class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<unordered_set<int>> tot(N+1, unordered_set<int>{});
        vector<unordered_set<int>>toed(N+1, unordered_set<int>{});
        for(auto t: trust){
            int a = t[0];
            int b = t[1];
            tot[a].insert(b);
            toed[b].insert(a);
        }
        for(int i = 1; i <= N; i++) {
            cout<<tot[i].size()<<" "<<toed[i].size()<<endl;
            if(tot[i].size() == 0 && toed[i].size() == (N-1)) return i;
        }
        return -1;
    }
};

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> t(N+1, 0);
        vector<int> e(N+1, 0);
        for(auto p: trust) t[p[0]]++, e[p[1]]++;
        for(int i = 1; i <= N; i++) if(t[i] == 0 && e[i] == N-1) return i;
        return -1;
    }
};