class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        if(asteroids.size() <= 1) return asteroids;
        vector<int> ans{asteroids[0]};
        for(int i = 1; i < asteroids.size(); i++){
            int tail = ans.back();
            if(tail * asteroids[i] < 0){
                if(tail < 0 && asteroids[i] > 0){
                    ans.push_back(asteroids[i]);
                }
                else{
                    int ast = abs(asteroids[i]);
                    while(ans.empty() == false && ans.back() > 0 && ans.back() < ast) ans.pop_back();
                    if(ans.empty() == true) ans.push_back(-ast);
                    else if(ans.back() < 0) ans.push_back(-ast);
                    else if(ans.back() == ast) ans.pop_back();
                }
            }
            else{
                ans.push_back(asteroids[i]);
            }
        }
        return ans;
    }
};