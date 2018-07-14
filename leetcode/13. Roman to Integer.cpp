class Solution {
public:
    int romanToInt(string s) {
        map<string, int> roman;
        roman["I"] = 1;
        roman["V"] = 5;
        roman["X"] = 10;
        roman["L"] = 50;
        roman["C"] = 100;
        roman["D"] = 500;
        roman["M"] = 1000;
        roman["IV"] = 4;
        roman["IX"] = 9;
        roman["XL"] = 40;
        roman["XC"] = 90;
        roman["CD"] = 400;
        roman["CM"] = 900;
        
        int result = 0;
        for(int i = 0; i < s.size(); i++){
            string s1 = s.substr(i, 1);
            string s2 = (i == s.size()-1)? "I": s.substr(i+1, 1);
            if(roman[s1] < roman[s2]){ //eat two char
                result += roman[s.substr(i, 2)];
                i++;
            }
            else{
                result += roman[s.substr(i, 1)];
            }
        }
        
        return result;
    }
};