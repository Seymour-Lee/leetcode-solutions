class Solution {
public:
    int countSegments(string s) {
        if(s.size() == 0) return 0;
        int result = 0;
        for(int i = 0, j = 0; i < s.size() && j < s.size(); j++, i = j){
            while(j < s.size() && s[j] == ' ') j++;
            if(j == s.size()) break;
            i = j;
            while(j < s.size() && s[j] != ' ') j++;
            result++;
        }
        return result;
    }
};

class Solution {
public:
    int countSegments(string s) {
        istringstream is(s);
        string str;
        int ans = 0;
        while(getline(is, str, ' ')) if(str.size()) ans++;
        return ans;
    }
};