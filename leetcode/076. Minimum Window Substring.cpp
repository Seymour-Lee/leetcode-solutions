class Solution {
public:
    string minWindow(string s, string t) {
        if(s == "" || t == "") return "";
        unordered_map<char, int> ch2freq;
        for(auto c: t) ch2freq[c]++;
        int counter = t.size(), i = 0, j = 0, len = INT_MAX, pos = 0;
        while(j < s.size()){
            char a = s[j++];
            if(ch2freq[a] > 0) counter--;
            ch2freq[a]--;
            while(counter == 0){
                if(j-i < len) pos = i, len = j-i;
                char b = s[i++];
                if(ch2freq[b] == 0) counter++;
                ch2freq[b]++;
            }
        }
        return len == INT_MAX? "": s.substr(pos, len);
    }
};