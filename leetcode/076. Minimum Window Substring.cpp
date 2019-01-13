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

class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() == 0 || t.size() == 0) return "";
        int pos = 0;
        int len = INT_MAX;
        int i = 0, j = 0;
        unordered_map<char, int> ch2num;
        int cnt = t.size();
        for(auto c: t) ch2num[c]++;
        while(i <= j && j < s.size()){
            char a = s[j++];
            if(ch2num[a] > 0) cnt--;
            ch2num[a]--;
            while(cnt == 0){
                if(j-i < len) len = j-i, pos = i;
                char b = s[i++];
                if(ch2num[b] == 0) cnt++;
                ch2num[b]++;
            }
        }
        return len == INT_MAX? "": s.substr(pos, len);
    }
};