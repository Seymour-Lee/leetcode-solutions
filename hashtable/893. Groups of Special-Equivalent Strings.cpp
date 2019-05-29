class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        set<vector<int>> st;
        for(auto str: A){
            vector<int> counter = vector<int>(52, 0);
            for(int i = 0; i < str.size(); i++){
                counter[str[i] - 'a' + 26 * (i % 2)]++;
            }
            st.insert(counter);
        }
        return st.size();
    }
};

class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        unordered_set<string> seen;
        for(auto str: A){
            string a = "", b = "";
            for(int i = 0; i < str.size(); i++){
                if(i % 2 == 0) a += str[i];
                else b += str[i];
            }
            sort(a.begin(), a.end());
            sort(b.begin(), b.end());
            seen.insert(a+b);
        }
        return seen.size();
    }
};