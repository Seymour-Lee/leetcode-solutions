class Solution {
public:
    int myAtoi(string str) {
        if(str == "") return 0;
        long long result = 0;
        for(int i = 0; i < str.size(); i++){
            if(str[i] == '+' || str[i] == '-' || isdigit(str[i])){
                str = str.substr(i, str.size()-i);
                break;
            }
            if(str[i] != ' '){
                return 0;
            }
        }
        
        bool negative = false;
        if(str[0] == '-'){
            negative = true;
            str = str.substr(1, str.size()-1);
        }
        else if(str[0] == '+'){
            str = str.substr(1, str.size()-1);
        }
        for(int i = 0; i < str.size(); i++){
            if(!isdigit(str[i])){
                str = str.substr(0, i);
                break;
            }
        }
        if(str.size() == 0) return 0;
        
        for(int i = 0; i < str.size(); i++){
            if(result * 10 + (str[i] - '0') < result) result = LONG_LONG_MAX;
            else result = result * 10 + (str[i] - '0');
        }
        
        result = negative? (-1) * result: result;
        if(result > INT_MAX) return INT_MAX;
        if(result < INT_MIN) return INT_MIN;
        
        return (int)result;
    }
};