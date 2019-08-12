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

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for(auto a: asteroids){
            while(ans.size() && ans.back() > 0 && a < 0 && ans.back() < -a) ans.pop_back();
            if(ans.size() && ans.back() > 0 && a < 0){
                if(ans.back() == -a) ans.pop_back();
            }
            else ans.push_back(a);
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for(auto a: asteroids){
            if(ans.size() == 0 || ans.back()*a > 0) ans.push_back(a);
            else{
                while(ans.size() && ans.back() > 0 && a < 0 && ans.back() < -a){
                    ans.pop_back();
                }
                if(ans.size() && ans.back() > 0 && a < 0){
                    if(ans.back() == -a) ans.pop_back();
                } 
                else ans.push_back(a);
            }
        }
        return ans;
    }
};