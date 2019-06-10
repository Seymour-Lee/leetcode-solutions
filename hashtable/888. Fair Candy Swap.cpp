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

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int diff = (accumulate(A.begin(), A.end(), 0)-accumulate(B.begin(), B.end(), 0)) / 2;
        // find A[i], B[j], such that A[i]-B[j] = diff/2;
        // B[j] = A[i]-diff
        unordered_set<int> as;
        for(auto a: A) as.insert(a);
        for(auto b: B) if(as.find(diff+b) != as.end()) return {b+diff, b};
        return {-1, -1};
    }
};