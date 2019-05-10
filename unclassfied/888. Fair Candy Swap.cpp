class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int suma = 0;
        for(auto a: A) suma += a;
        int sumb = 0;
        for(auto b: B) sumb += b;
        int diff = (sumb - suma) / 2;
        set<int> st;
        for(auto b: B) st.insert(b);
        for(auto a: A){
            if(st.find(a + diff) != st.end()){
                return vector<int>{a, diff+a};
            }
        }
        return vector<int>{0, 0};
    }
};