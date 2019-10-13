class Solution {
public:
    int balancedStringSplit(string s) {
        int ans = 0;
        int counter = 0;
        for(auto c: s){
            if(c == 'L') counter++;
            else counter--;
            if(counter == 0) ans++;
        }
        return ans;
    }
};