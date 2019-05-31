class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        set<int> s;
        for(auto candy: candies) s.insert(candy);
        return min(s.size(), candies.size() / 2);
    }
};

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> c;
        for(auto e: candies) c.insert(e);
        return min(c.size(), candies.size()/2);
    }
};