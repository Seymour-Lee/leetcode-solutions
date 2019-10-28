class Solution {
public:
    int maxLength(vector<string>& arr) {
        int ans = 0;
        vector<bool> v(26, false);
        backtracking(arr, 0, v, ans);
        return ans;
    }
    
private:
    void backtracking(vector<string>& arr, int pos, vector<bool> v, int &ans){
        ans = max(ans, (int)count(v.begin(), v.end(), true));
        if(pos == arr.size()) return;
        vector<bool> next = v;
        bool flag = true;
        for(auto c: arr[pos]){
            if(next[c-'a'] == false){
                next[c-'a'] = true;
            }
            else{
                flag = false;
                break;
            }
        }
        if(flag){
            backtracking(arr, pos+1, next, ans);
        }
        backtracking(arr, pos+1, v, ans);
    }
};