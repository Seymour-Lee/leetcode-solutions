class Solution {
public:
    int numJewelsInStones(string J, string S) {
        if(J.empty() || S.empty()) return 0;
        set<char> jewels;
        for(auto c: J) jewels.insert(c);
        int result = 0;
        for(auto c: S){
            if(jewels.find(c) != jewels.end()){
                result++;
            }
        }
        return result;
    }
};