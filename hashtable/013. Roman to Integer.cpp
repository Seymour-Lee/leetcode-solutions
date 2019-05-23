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

class Solution {
public:
    int romanToInt(string s) {
        map<int, string> num2str = {{1, "I"},
                            {5, "V"},
                            {10, "X"},
                            {50, "L"},
                            {100, "C"},
                            {500, "D"},
                            {1000, "M"},
                            {4, "IV"},
                            {9, "IX"},
                            {40, "XL"},
                            {90, "XC"},
                            {400, "CD"},
                            {900, "CM"},
                           };
        int ans = 0;
        for(auto p = num2str.rbegin(); p != num2str.rend(); p++){
            auto num = p->first;
            auto str = p->second;
            while(s.find(str) == 0) ans += num, s = s.substr(str.size());
        }
        return ans;
    }
};