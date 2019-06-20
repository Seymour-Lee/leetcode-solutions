class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> g(numCourses, vector<int>());
        vector<int> indegree(numCourses, 0);
        int courses = 0;
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
            courses++;
            for(auto v: g[node]){
                indegree[v]--;
                if(indegree[v] == 0){
                    q.push(v);
                }
            }
        }
        return courses == numCourses;
    }
};

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<unordered_set<int>> a2b(numCourses);
        vector<int> dgr(numCourses);
        for(auto p: prerequisites) a2b[p[1]].insert(p[0]), dgr[p[0]]++;;
        queue<int> q;
        for(int i = 0; i < dgr.size(); i++) if(dgr[i] == 0) q.push(i);
        while(q.empty() == false){
            int node = q.front(); q.pop();
            for(auto nei: a2b[node]){
                if((--dgr[nei]) == 0) q.push(nei);
            }
        }
        return count(dgr.begin(), dgr.end(), 0) == numCourses;
    }
};