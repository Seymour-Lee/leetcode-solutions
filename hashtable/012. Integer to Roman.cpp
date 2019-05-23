class Solution {
public:
    string intToRoman(int num) {
        string result = "";
        map<int, string> int2roman;
        int2roman[1] = "I";int2roman[5] = "V";int2roman[10] = "X";
        int2roman[50] = "L";int2roman[100] = "C";int2roman[500] = "D";
        int2roman[1000] = "M";int2roman[4] = "IV";int2roman[9] = "IX";
        int2roman[40] = "XL";int2roman[90] = "XC";int2roman[400] = "CD";
        int2roman[900] = "CM";
        for(auto itor = int2roman.rbegin(); itor != int2roman.rend() && num; itor++){
            int re = num / itor->first;
            num = num % itor->first;
            while(re--) result = result + itor->second;
        }
        return result;
    }
};

class Solution {
public:
    string intToRoman(int n) {
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
        string ans = "";
        for(auto p = num2str.rbegin(); p != num2str.rend(); p++){
            if(n == 0) break;
            auto num = p->first;
            auto str = p->second;
            int counter = n / num;
            while(counter--) ans += str, n -= num;
            // cout<<ans<<" "<<n<<endl;
        }
        
        return ans;
    }
};