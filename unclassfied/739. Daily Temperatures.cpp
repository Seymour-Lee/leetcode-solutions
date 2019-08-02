class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        if(temperatures.size() == 0) return result;
        stack<pair<int, int>> stk;
        stk.push(pair<int, int>{temperatures[0], 0});
        for(int i = 1; i < temperatures.size(); i++){
            if(stk.empty()){
                stk.push(pair<int, int>{temperatures[i], i});
            }
            else if(temperatures[i] > stk.top().first){
                while(stk.empty() == false && temperatures[i] > stk.top().first){
                    auto elem = stk.top();
                    stk.pop();
                    result[elem.second] = i - elem.second;
                }
                stk.push(pair<int, int>{temperatures[i], i});
            }
            else{
                stk.push(pair<int, int>{temperatures[i], i});
            }
        }
        return result;
    }
};

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        if(temperatures.size() == 0) return result;
        stack<pair<int, int>> stk;
        stk.push(pair<int, int>{temperatures[0], 0});
        for(int i = 1; i < temperatures.size(); i++){
            if(stk.empty()){
                stk.push(pair<int, int>{temperatures[i], i});
            }
            else if(temperatures[i] > stk.top().first){
                while(stk.empty() == false && temperatures[i] > stk.top().first){
                    auto elem = stk.top();
                    stk.pop();
                    result[elem.second] = i - elem.second;
                }
                stk.push(pair<int, int>{temperatures[i], i});
            }
            else{
                stk.push(pair<int, int>{temperatures[i], i});
            }
        }
        return result;
    }
};