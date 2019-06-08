class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        set<int> ans;
        for(int i = 0; pow(x, i) <= bound; i++){
            int xi = pow(x, i);
            for(int j = 0; pow(y, j) <= bound-xi; j++){
                int yj = pow(y, j);
                if(xi + yj <= bound) ans.insert(xi+yj);
                if(y == 1) break;
            }
            if(x == 1) break;
        }
        return vector<int>(ans.begin(), ans.end());
    }
};

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<bool> dp(bound+1, false);
        for(int i = 0; pow(x, i) <= bound; i++){
            for(int j = 0; pow(x,i)+pow(y, j) <= bound; j++){
                dp[pow(x,i)+pow(y, j)] = true;
                if(y == 1) break;
            }
            if(x == 1) break;
        }
        vector<int> ans;
        for(int i = 0; i < dp.size(); i++) if(dp[i]) ans.push_back(i);
        return ans;
    }
};