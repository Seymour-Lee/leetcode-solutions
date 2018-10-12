class Solution {
public:
    string splitLoopedString(vector<string>& strs) {
        if(strs.size() == 0) return "";
        getMaxString(strs);
        string ans = "";
        for(int i = 0; i < strs.size(); i++){
            cuti(ans, strs, i, true);
            cuti(ans, strs, i, false);
        }
        return ans;
    }
    
private:
    void cuti(string &ans, vector<string> &strs, int i, bool use){
        string undo = strs[i];
        if (use) reverse(undo.begin(), undo.end());
        string str1 = "", str2 = "";
        for (int j = i+1; j < strs.size(); ++j) str1 += strs[j];
        for (int j = 0; j < i; ++j) str2 += strs[j];

        for (int k = 0; k < undo.size(); ++k) {
            string cutted = undo.substr(k) + str1 + str2 + undo.substr(0, k);
            ans = ans == "" ? cutted : max(ans, cutted);
        }
    }
    
    void getMaxString(vector<string> &strs){
        for(auto &str: strs){
            string undo = str;
            reverse(str.begin(), str.end());
            str = str > undo? str: undo;
        }
    }
};