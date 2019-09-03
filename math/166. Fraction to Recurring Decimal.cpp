class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0) return "0";
        bool sign = ((numerator < 0) ^ (denominator < 0));
        string result = sign? "-": "";
        long long num = abs(numerator);
        long long den = abs(denominator);
        result += to_string(abs(num / den));
        num = num % den;
        if(num == 0) return result;
        result += ".";
        map<long long, long long> num2size;
        num2size[num] = result.size();
        while(num != 0){
            num = num * 10;
            long long quo = num / den;
            result += to_string(abs(quo));
            num = num % den;
            if(num2size.find(num) != num2size.end()){
                result.insert(result.begin()+num2size[num], '(');
                result += ')';
                break;
            }
            else{
                num2size[num] = result.size();
            }
        }
        return result;
    }
};

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0) return "0";
        bool sign = ((numerator < 0) ^ (denominator < 0));
        string result = sign? "-": "";
        long long num = labs(numerator);
        long long den = labs(denominator);
        result += to_string(abs(num / den));
        num = num % den;
        if(num == 0) return result;
        result += ".";
        unordered_map<long long, long long> num2size;
        num2size[num] = result.size();
        while(num != 0){
            num = num * 10;
            long long quo = num / den;
            result += to_string(abs(quo));
            num = num % den;
            if(num2size.find(num) != num2size.end()){
                result.insert(result.begin()+num2size[num], '(');
                result += ')';
                break;
            }
            else{
                num2size[num] = result.size();
            }
        }
        return result;
    }
};