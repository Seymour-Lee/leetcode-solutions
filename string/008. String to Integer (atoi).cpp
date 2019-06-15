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

int myAtoi(string str) {
        string s=""; 
        bool neg=false; 
        bool start=false; 
      //1. clean the string    
        for (auto x: str){
            if (isalpha(x)|| x =='.'){
                break; 
            }
            if(isspace(x)){
                if (start == true) break; 
                else
                    continue; 
            }
            if (x == '-'){
                if (start == true) break;
                neg= true; 
                start = true ; 
            }
            if (x == '+'){
                if (start == true) break;
              
                start=true;
            }
            if (isdigit(x)){
                start= true; 
                s.push_back(x); 
            }
        }
        long long int num=0; 
        if (s == ""){
            return 0; 
        }
//2. convert string to int. 
//if number is larger than INTMAX/10 check the flag to see if the number is +ve or -ve and return INT_MAX or INT_MIN appropriately 
// else, just check the flag and return the number
        for (auto x:s){
            if (num > INT_MAX/10 ){
                if (neg==false){
                    return INT_MAX;
                }
                else if (neg == true){
                    return INT_MIN; 
                }
           }
             num=num*10 + (x- '0');
        }

        int x; 
        if (num > INT_MAX){
            if (neg==true){
                return INT_MIN;
            }
            else 
                return INT_MAX;
        }

        else 
            x= num; 
        if (neg == true){
            return (-1)*x;
        }
        else 
            return x; 
        return 0;
    }