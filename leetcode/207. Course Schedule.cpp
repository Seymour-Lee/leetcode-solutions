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