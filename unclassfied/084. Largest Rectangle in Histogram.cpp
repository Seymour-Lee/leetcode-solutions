class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size() == 0) return 0;
        stack<int> stk;
        int ans = 0;
        stk.push(-1);
        for(int i = 0; i < heights.size(); i++){
            while(stk.top() != -1 && heights[i] <= heights[stk.top()]){
                int top = stk.top(); stk.pop();
                ans = max(ans, heights[top]*(i-stk.top()-1));
            }
            stk.push(i);
        }
        while(stk.top() != -1){
            int top = stk.top(); stk.pop();
            ans = max(ans, heights[top]*((int)heights.size()-stk.top()-1));
        }
        return ans;
    }
};

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size() == 0) return 0;
        stack<int> stk;
        int ans = 0;
        stk.push(-1);
        for(int i = 0; i < heights.size(); i++){
            while(stk.top() != -1 && heights[i] <= heights[stk.top()]){
                int top = stk.top(); stk.pop();
                ans = max(ans, heights[top]*(i-stk.top()-1));
            }
            stk.push(i);
        }
        while(stk.top() != -1){
            int top = stk.top(); stk.pop();
            ans = max(ans, heights[top]*((int)heights.size()-stk.top()-1));
        }
        return ans;
    }
};