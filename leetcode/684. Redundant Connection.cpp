class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> result;
        vector<int> parent(edges.size()+1, 0);
        for(int i = 0; i < parent.size(); i++) parent[i] = i;
        for(auto v: edges){
            int n1 = v[0], n2 = v[1];
            while(n1 != parent[n1]) n1 = parent[n1];
            while(n2 != parent[n2]) n2 = parent[n2];
            if(n1 == n2) result = v;
            else parent[n1] = n2;
        }
        return result;
    }
};