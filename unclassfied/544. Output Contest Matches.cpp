class Solution {
public:
    string findContestMatch(int n) {
        vector<string> contest;
        for(int i = 1; i <= n; i++) contest.push_back(to_string(i));
        return recursion(contest);
    }
    
private:
    string recursion(vector<string> vec){
        if(vec.size() == 1) return vec.front();
        vector<string> ans;
        for(int i = 0; i < vec.size()/2; i++){
            ans.push_back("("+vec[i]+","+vec[vec.size()-1-i]+")");
        }
        return recursion(ans);
    }
};