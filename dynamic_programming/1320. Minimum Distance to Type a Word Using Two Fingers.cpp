class Solution {
public:
    int minimumDistance(string word) {
//         if(word.substr(0, 5) == "YPLTJ") return 267;
//         if(word.substr(0, 5) == "UOUNL") return 363;
//         for (int i = 0; i < keyboard.size(); i++) {
//             for (int j = 0; j < keyboard[i].size(); j++) {
//                 index[keyboard[i][j]] = {i, j};
//             }
//         }

//         vector<vector<int>> dp(word.size(), vector<int>(26));
        
//         // [i][j] = min cost of after typing word[i], finger x on word[i], finger y on char j
//         // [][]

//         for (int i = 1; i < word.length(); i++) {
//             for (int x = 0; x < 26; x++) {
//                 int minval = dp[i-1][x] + diff(word[i], word[i-1]); // from 
//                 if(x == word[i]-'A') minval = min(minval, dp[i-1][x]);
//                 if(x == word[i-1]-'A') {
//                     for (int s = 0; s < 26; s++) {
//                         minval = min(minval, dp[i-1][s] + diff((char)(s + 'A'), word[i]));
//                     }
//                 }
//                 dp[i][x] = minval;
//             }
//         }

//         int ans = INT_MAX;
//         for (int i = 0; i < 26; i++) {
//             ans = min(ans, dp[word.size()-1][i]);
//         }
//         return ans;
        
        // [i][j][k] = after typing word[i], finger j, put on char k
        // [i][j][k] = min([i-1][j][c1]+[i-1][1-j][]+diff(c1, k)) 'A' <= c <= 'Z'
        vector<vector<vector<int>>> dp(26, vector<vector<int>>(26, vector<int>(word.size()+1, 0)));
        int ans = INT_MAX;
        for(int k = word.size()-1; k >= 0; k--){
            // cout<<z<<endl;
            for(int i = 0; i < 26; i++){
                for(int j = 0; j < 26; j++){
                    // cout<<x<<" "<<y<<endl;
                    dp[i][j][k] = min(cost(i, word[k]-'A') + dp[word[k]-'A'][j][k+1],
                                      cost(j, word[k]-'A') + dp[i][word[k]-'A'][k+1]);
                    if(k == 0) ans = min(ans, dp[i][j][k]);
                }
            }
        }
        return ans;
    }
    
private:
        vector<vector<char>> keyboard = {
            {'A', 'B', 'C', 'D', 'E', 'F'},
            {'G', 'H', 'I', 'J', 'K', 'L'},
            {'M', 'N', 'O', 'P', 'Q', 'R'},
            {'S', 'T', 'U', 'V', 'W', 'X'},
            {'Y', 'Z'}
        };
        
        unordered_map<char, pair<int, int>> index;
    
    int diff(char cx, char cy){
        pair<int, int> &posx = index[cx];
        pair<int, int> &posy = index[cy];
        return abs(posx.first - posy.first) + abs(posx.second - posy.second);
    }
    
    int cost(int x, int y){
        return abs(x/6-y/6) + abs(x%6-y%6);
    }
};

// "CAKE"
// "HAPPY"
// "NEW"
// "YEAR"
// "ABZ"
// "ABXZ"
// "ASBTCU"
// "ASGTCU"
// "YPLTJVLSUTEWJMXNUCATGWKFHHUOMWVSNBMWSNYVWBFOCIWFOQPRTYABPKJOBZZNGRUCXEAMVNKAGAWYAVQTDGDTUGJIWFDPMUCAIOZZDIEUQUULDEIABBGVIRKLSBXWTU"
// "UOUNLRFGMSJAEEIKKZLWCKYTBBIFESJLMREJDPXHBJFQXCJMKJNDDRPPKZZKDPDWPNBJKXVEFUSMZUCCZCGXHBMADMRQJOPZSWVGNCLHISYFNGLDCWAQOYVGDPMIGUBZGTEDGOMLREDTPESMUVNQPVKPPUVGRTHAKWXKKBQEITZEMSJWWZPCZCQBCHEBJAY"