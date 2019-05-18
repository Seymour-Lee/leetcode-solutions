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

class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        for(int i = 2; i <= n; i++){
            string next = "";
            char prev = ans[0];
            int counter = 1;
            for(int j = 1; j < ans.size(); j++){
                char c = ans[j];
                if(c == prev) counter++;
                else next += to_string(counter)+string(1, prev), prev = c, counter = 1;
            }
            next += to_string(counter)+string(1, prev);
            ans = next;
        }
        return ans;
    }
};