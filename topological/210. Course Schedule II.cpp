class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> ans;
        vector<vector<int>> g(numCourses, vector<int>());
        vector<int> indegree(numCourses, 0);
        for(auto pre: prerequisites){
            g[pre.second].push_back(pre.first);
            indegree[pre.first]++;
        }
        queue<int> q;
        for(int i = 0; i < indegree.size(); i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(q.empty() == false){
            int node = q.front(); q.pop();
            ans.push_back(node);
            for(auto v: g[node]){
                indegree[v]--;
                if(indegree[v] == 0){
                    q.push(v);
                }
            }
        }
        return ans.size() == numCourses? ans: vector<int>();
    }
};

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<unordered_set<int>> a2b(numCourses);
        vector<int> dgr(numCourses);
        for(auto p: prerequisites) a2b[p[1]].insert(p[0]), dgr[p[0]]++;;
        queue<int> q;
        for(int i = 0; i < dgr.size(); i++) if(dgr[i] == 0) q.push(i);
        while(q.empty() == false){
            int node = q.front(); q.pop();
            ans.push_back(node);
            for(auto nei: a2b[node]){
                if((--dgr[nei]) == 0) q.push(nei);
            }
        }
        return count(dgr.begin(), dgr.end(), 0) == numCourses? ans: vector<int>{};
    }
};

class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>> a2b(n);
        vector<int> in(n, 0);
        for(auto p: pre) a2b[p[1]].push_back(p[0]), in[p[0]]++;
        queue<int> q;
        for(int i = 0; i < in.size(); i++) if(in[i] == 0) q.push(i);
        vector<int> ans;
        while(q.empty() == false){
            int size = q.size();
            while(size--){
                auto a = q.front(); q.pop();
                ans.push_back(a);
                for(auto nei: a2b[a]) if(--in[nei] == 0) q.push(nei);
            }
        }
        return accumulate(in.begin(), in.end(), 0) == 0? ans: vector<int>{};
    }
};