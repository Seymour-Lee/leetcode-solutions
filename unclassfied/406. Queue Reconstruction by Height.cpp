class Solution {
    static bool cmp(pair<int, int> p1, pair<int, int> p2){
        if(p1.first == p2.first) return p1.second < p2.second;
        return p1.first > p2.first;
    }
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(), people.end(), cmp);
        vector<pair<int,int>> result;
        for(int i = 0; i < people.size(); i++){
            result.insert(result.begin() + people[i].second, people[i]);
        }
        return result;
    }
};