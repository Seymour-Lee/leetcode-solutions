class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        set<int> s;
        for(auto candy: candies) s.insert(candy);
        return min(s.size(), candies.size() / 2);
    }
};