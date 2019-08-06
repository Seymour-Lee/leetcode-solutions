class Solution {
public:
    string getHint(string secret, string guess) {
        int a = 0, b = 0;
        vector<int> aa(10, 0), bb(10, 0);
        for(int i = 0; i < secret.size(); i++){
            if(secret[i] == guess[i]) a++;
            else aa[secret[i]-'0']++, bb[guess[i]-'0']++;
        }
        for(int i = 0; i < aa.size(); i++) b += min(aa[i], bb[i]);
        return to_string(a)+"A"+to_string(b)+"B";
    }
};