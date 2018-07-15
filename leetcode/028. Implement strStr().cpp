class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        
        int m = haystack.size();
        int n = needle.size();
        
        for(int i = 0; i < m-n+1; i++){
            string cur = haystack.substr(i, n);
            if(cur == needle) return i;
        }
        
        return -1;
    }
};