class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        for(int i = 2; i <= n; i++){
            string next = "";
            for(int j = 0; j < result.size();){
                int k = 1;
                while(result[j] == result[j+k]) k++;
                next.push_back('0' + k);
                next.push_back(result[j]);
                j += k;
            }
            result = next;
        }
        return result;
    }
};