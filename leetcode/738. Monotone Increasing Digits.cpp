class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string str = to_string(N);
        int j = str.size();
        for(int i = str.size()-1; i > 0; i--){
            if(str[i-1] > str[i]){
                str[i-1]--;
                j = i;
            }
        }
        for(int i = j; i < str.size(); i++) str[i] = '9';
        return stoi(str);
    }
};