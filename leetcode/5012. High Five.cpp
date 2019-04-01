class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        vector<vector<int>> ans;
        map<int, multiset<int>> id2scores;
        for(auto item: items){
            id2scores[item[0]].insert(item[1]);
        }
        for(auto p: id2scores){
            auto id = p.first;
            auto scores = p.second;
            int counter = 0;
            int s = 0;
            for(auto itor = scores.rbegin(); itor != scores.rend(); itor++){
                int score = *itor;
                if(counter == 5) break;
                s += score;
                counter++;
            }
            ans.push_back({id, s/counter});
        }
        return ans;
    }
};