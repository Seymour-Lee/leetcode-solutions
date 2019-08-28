class Solution {
public:
    string alienOrder(vector<string>& words) {
        map<char, set<char>> suc, pre;
        set<char> chars;
        string s;
        for (string t : words) {
            chars.insert(t.begin(), t.end());
            for (int i=0; i<min(s.size(), t.size()); ++i) {
                char a = s[i], b = t[i];
                if (a != b) {
                    suc[a].insert(b);
                    pre[b].insert(a);
                    break;
                }
            }
            s = t;
        }
        set<char> free = chars;
        for (auto p : pre)
            free.erase(p.first);
        string order;
        while (free.size()) {
            char a = *begin(free);
            free.erase(a);
            order += a;
            for (char b : suc[a]) {
                pre[b].erase(a);
                if (pre[b].empty())
                    free.insert(b);
            }
        }
        return order.size() == chars.size() ? order : "";
    }
};

class Solution {
public:
    string alienOrder(vector<string>& words) {
        string ans = "";
        unordered_map<char, unordered_set<char>> a2b;
        unordered_map<char, unordered_set<char>> b2a;
        unordered_set<char> chars(words[0].begin(), words[0].end());
        string prev = words[0];
        for(int i = 1; i < words.size(); i++){
            string str = words[i];
            chars.insert(str.begin(), str.end());
            int a = 0, b = 0;
            while(a < prev.size() && b < str.size() && prev[a] == str[b]) a++, b++;
            if(a < prev.size() && b < str.size()){
                a2b[prev[a]].insert(str[b]);
                b2a[str[b]].insert(prev[a]);
            }
            prev = str;
        }
        int s = chars.size();
        for(auto p: b2a) chars.erase(p.first);
        queue<char> q;
        while(chars.size()){
            char c = *chars.begin();
            q.push(c);
            chars.erase(c);
        }
        while(q.empty() == false){
            int size = q.size();
            while(size--){
                char c = q.front(); q.pop();
                ans.push_back(c);
                for(auto next: a2b[c]){
                    b2a[next].erase(c);
                    if(b2a[next].size() == 0){
                        q.push(next);
                        b2a.erase(next);
                    }
                }
            }
        }
        return ans.size() == s? ans: "";
    }
};