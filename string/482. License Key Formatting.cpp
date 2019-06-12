class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string result;
        transform(S.begin(), S.end(), S.begin(), ::toupper);
        int counter = 0;
        string s =  "";
        for(auto c: S){
            if(c != '-'){
                counter++;
                s += c;
            }
        }
        if(counter == 0) return "";
        int firstGroupSize = counter % K;
        result += s.substr(0, firstGroupSize);
        for(int i = firstGroupSize; i < s.size(); i += K){
            result += "-" + s.substr(i, K);
        }
        return counter % K == 0? result.substr(1, result.size()-1): result;
    }

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string result;
        transform(S.begin(), S.end(), S.begin(), ::toupper);
        int counter = 0;
        string s =  "";
        for(auto c: S){
            if(c != '-'){
                counter++;
                s += c;
            }
        }
        if(counter == 0) return "";
        int firstGroupSize = counter % K;
        result += s.substr(0, firstGroupSize);
        for(int i = firstGroupSize; i < s.size(); i += K){
            result += "-" + s.substr(i, K);
        }
        return counter % K == 0? result.substr(1, result.size()-1): result;
    }
};