class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> cur;
        int result = 0;
        
        int n = s.size();
        int i = 0, j = 0;
        while(i < n && j < n){
            if(cur.find(s.at(j)) == cur.end()){
                cur.insert(s.at(j));
                j++;
                result = max(result, j - i);
            }
            else{
                cur.erase(s.at(i));
                i++;
            }
        }
        
        return result;
    }
};