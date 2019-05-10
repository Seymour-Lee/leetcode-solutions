class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> ans;
        vector<pair<int, int>> heights;
        for(auto b: buildings){
            heights.push_back({b[0], -b[2]});
            heights.push_back({b[1], b[2]});
        }
        sort(heights.begin(), heights.end());
        multiset<int> pq;
        pq.insert(0);
        int prev = 0;
        for(auto h: heights){
            if(h.second < 0) pq.insert(-h.second);
            else pq.erase(pq.find(h.second));
            int cur = *pq.rbegin();
            if(prev != cur){
                ans.push_back({h.first, cur});
                prev = cur;
            }
        }
        return ans;
    }
};