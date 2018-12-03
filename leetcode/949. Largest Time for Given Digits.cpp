class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        sort(A.begin(), A.end(), [](int a, int b){return a>b;});
        string ans = "";
        for(auto a: A) ans += string(1, a+'0');
        auto f = [](string str){
            return stoi(str.substr(0, 2)) <= 23 && stoi(str.substr(2, 2)) <= 59;
        };
        while(f(ans) == false){
            if(prev_permutation(ans.begin(), ans.end()) == false) return "";
        } 
        return ans.substr(0, 2) + ":" + ans.substr(2, 2);
    }
};