class Solution {
public:
    bool isStrobogrammatic(string num) {
        // 0, 1, 6, 8, 9
        map<char, char> valid2mirror = {{'0', '0'}, {'1', '1'}, 
                                        {'6', '9'}, {'8', '8'}, {'9', '6'}};
        for(int i = 0, j = num.size()-1; i <= j; i++, j--){
            if(i == j) return num[i] == '0' || num[i] == '1' || num[i] == '8';
            if(valid2mirror.find(num[i]) == valid2mirror.end() ||
               valid2mirror[num[i]] != num[j]){
                return false;
            }
        }
        return true;
    }
};