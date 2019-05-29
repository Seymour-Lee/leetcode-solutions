class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        if(A.size() == 1) return 0;
        if(A[0].size() == 2) return 0;
        vector<string> cols;
        for(int j = 0; j < A[0].size(); j++){
            string str = "";
            for(int i = 0; i < A.size(); i++){
                str += string(1, A[i][j]);
            }
            cols.push_back(str);
        }
        int ans = 0;
        for(auto col: cols){
            int i = 0;
            while(col[i] == col[i+1]) i++;
            while(i < col.size()-1){
                if(col[i] > col[i+1]){
                    ans++;
                    break;
                }
                i++;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        vector<string> strs;
        for(int j = 0; j < A[0].size(); j++){
            string cur = "";
            for(int i = 0; i < A.size(); i++) cur += A[i][j];
            strs.push_back(cur);
        }
        int ans = 0;
        for(auto str: strs){
            int i = 1;
            while(i < str.size() && str[i-1] <= str[i]) i++;
            if(i != str.size()) ans++;
        }
        return ans;
    }
};

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int ans = 0;
        for(int j = 0; j < A[0].size(); j++){
            for(int i = 0; i < A.size()-1; i++) if(A[i][j] > A[i+1][j]){
                ans++;
                break;
            }
        }
        return ans;
    }
};