class Solution {
public:
    string similarRGB(string color) {
        vector<char> chars = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
        string ans = "#";
        for(int i = 0; i < 3; i++){
            int num;
            sscanf(color.c_str() + i * 2 + 1, "%2x", &num);
            int quo = num / 17;
            int rem = num % 17;
            if(rem <= 8){
                ans.push_back(chars[quo]);
                ans.push_back(chars[quo]);
            }
            else{
                ans.push_back(chars[quo+1]);
                ans.push_back(chars[quo+1]);
            }
        }
        return ans;
    }
};

class Solution {
public:
    string similarRGB(string color) {
        vector<char> chars = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
        string ans = "#";
        for(int i = 0; i < 3; i++){
            int num;
            sscanf(color.c_str() + i * 2 + 1, "%2x", &num);
            int quo = num / 17;
            int rem = num % 17;
            if(rem <= 8){
                ans.push_back(chars[quo]);
                ans.push_back(chars[quo]);
            }
            else{
                ans.push_back(chars[quo+1]);
                ans.push_back(chars[quo+1]);
            }
        }
        return ans;
    }
};