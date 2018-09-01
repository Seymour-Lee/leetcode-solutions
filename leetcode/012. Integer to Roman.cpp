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