class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> a2p;
        for(int i = 0; i < arr.size(); i++) a2p[arr[i]].push_back(i);
        int ans = 0;
        int target = arr.size()-1;
        queue<int> q;
        q.push(0);
        vector<bool> v(arr.size(), false);
        v[0] = true;
        while(q.empty() == false){
            int size = q.size();
            while(size--){
                int i = q.front(); q.pop();
                if(i == target) return ans;
                if(i-1 >= 0 && v[i-1] == false){
                    q.push(i-1);
                    v[i-1] = true;
                }
                if(i+1 < arr.size() && v[i+1] == false){
                    q.push(i+1);
                    v[i+1] = true;
                }
                for(auto p: a2p[arr[i]]) if(v[p] == false){
                    q.push(p);
                    v[p] = true;
                }
                a2p.erase(arr[i]);
            }
            ans++;
        }
        return -1;
    }
};