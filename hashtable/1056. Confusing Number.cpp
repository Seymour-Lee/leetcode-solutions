class Solution {
public:
    bool confusingNumber(int N) {
        // 0, 1, 6, 8, 9 are rotated 180 degrees, they become 0, 1, 9, 8, 6
        unordered_map<char, char> a2b = {{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
        unordered_set<char> invalid = {'2', '3', '4', '5', '7'};
        string str = to_string(N);
        string ori = str;
        reverse(str.begin(), str.end());
        for(auto &c: str){
            if(invalid.find(c) != invalid.end()) return false;
            c = a2b[c];
        }
        return str != ori;
    }
};

class Solution {
public:
    bool confusingNumber(int N) {
        string str = to_string(N);
        unordered_map<char, char> a2b = {
            {'0', '0'},
            {'1', '1'},
            {'6', '9'},
            {'8', '8'},
            {'9', '6'},
        };
        string rev = "";
        for(auto c: str){
            if(a2b.find(c) == a2b.end()) return false;
            rev += a2b[c];
        }
        reverse(rev.begin(), rev.end());
        return str != rev;
    }
};