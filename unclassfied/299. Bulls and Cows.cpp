class Solution {
public:
    string getHint(string secret, string guess) {
        int a = 0, b = 0;
        map<char, int> ch2freq;
        for(int i = 0; i < secret.size(); i++){
            ch2freq[secret[i]]++;
            if(secret[i] == guess[i]) a++;
        }
        for(int i = 0; i < secret.size(); i++){
            if(ch2freq.find(guess[i]) != ch2freq.end() && ch2freq[guess[i]] > 0){
                b++;
                ch2freq[guess[i]]--;
            }
        }
        return to_string(a) + "A" + to_string(b-a) + "B";
    }
};