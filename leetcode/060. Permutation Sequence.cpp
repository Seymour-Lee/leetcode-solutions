class Solution {
public:
    string getPermutation(int n, int k) {
        string str = "";
        for(char ch = '1'; ch < '1' + n; ch++) str += ch;
        while(--k) next_permutation(str.begin(), str.end());
        return str;
    }
};