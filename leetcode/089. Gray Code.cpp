class Solution {
public:
    vector<int> grayCode(int n) {
        if(n == 0) return vector<int>{0};
        vector<int> result = grayCode(n-1);
        int size = result.size();
        for(int i = 0; i < size; i++){
            result.push_back(result[size-i-1] + pow(2, n-1));
        }
        return result;
    }
};

class Solution {
public:
    vector<int> grayCode(int n) {
        if(n == 0) return vector<int>{0};
        vector<int> ans;
        set<int> seen;
        stack<int> stk;
        stk.push(0);
        while(stk.empty() == false){
            int cur = stk.top(); stk.pop();
            if(seen.find(cur) != seen.end()) continue;
            seen.insert(cur);
            ans.push_back(cur);
            for(int i = 0; i < n; i++){
                int next = cur ^ 1 << i;
                if(seen.find(next) == seen.end()){
                    stk.push(next);
                    break;
                }
            }
        }
        return ans;
    }
};