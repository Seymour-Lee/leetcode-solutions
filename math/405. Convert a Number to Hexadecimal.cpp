class Solution {
public:
    string toHex(int num) {
        if(num == 0) return "0";
        string result = "";
        int counter = 0;
        while(num && counter < 8){
            int cur = num & 15;
            if(cur < 10) result.push_back(cur + '0');
            else result.push_back('a' + cur - 10);
            num = num >> 4;
            counter++;
        }
        reverse(result.begin(),result.end());
        return result;
    }
};

class Solution {
public:
    string toHex(int num) {
        if(num == 0) return "0";
        string result = "";
        int counter = 0;
        while(num && counter < 8){
            int cur = num & 15;
            if(cur < 10) result.push_back(cur + '0');
            else result.push_back('a' + cur - 10);
            num = num >> 4;
            counter++;
        }
        reverse(result.begin(),result.end());
        return result;
    }
};