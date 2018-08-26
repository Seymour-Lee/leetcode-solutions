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