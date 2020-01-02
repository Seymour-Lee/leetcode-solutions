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

class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        sort(A.rbegin(), A.rend());
        string num;
        for(auto a: A) num.push_back(a+'0');
        while([](string str){
                return str.substr(0, 2) <= "23" && str.substr(2, 2) <= "59";
            }(num) == false){
            if(prev_permutation(num.begin(), num.end()) == false) return "";
        }
        return num.substr(0, 2) + ":" + num.substr(2, 2);
    }
};