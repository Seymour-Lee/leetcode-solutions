/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        for(int i = 0, x = 0; i < 10 && x < 6; i++){
            string guess = wordlist[rand() % wordlist.size()];
            x = master.guess(guess);
            vector<string> wlist;
            for(auto w: wordlist){
                if(match(guess, w) == x)
                    wlist.push_back(w);
            }
            wordlist = wlist;
        }
    }
    
private:
    int match(string a, string b){
        int ans = 0;
        for(int i = 0; i < a.size(); i++) if(a[i] == b[i]) ans++;
        return ans;
    }
};