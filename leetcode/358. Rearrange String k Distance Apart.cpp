class Solution {
public:
    string rearrangeString(string s, int k) {
        if(s.size() == 0 || k <= 0) return s; 
        string ans = "";
        vector<int> count(26, 0);
        vector<int> pos(26, 0);
        for(auto ch: s) count[ch-'a']++;
        for(int i = 0; i < s.size(); i++){
            int next = getNextLetter(count, pos, i);
            if(next == -1) return "";
            ans += ((char)next + 'a');
            count[next]--;
            pos[next] = i + k;
        }
        return ans;
    }
    
private:
    int getNextLetter(vector<int> count, vector<int> pos, int idx){
        int maxv = 0, next = -1;
        for(int i = 0; i < 26; i++){
            if(count[i] > maxv && pos[i]<= idx){
                maxv = count[i];
                next = i;
            }
        }
        return next;
    }
};