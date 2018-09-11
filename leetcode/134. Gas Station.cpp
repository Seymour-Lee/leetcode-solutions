class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int size = gas.size();
        int ans = 0;
        int sum = 0;
        int total = 0;
        for(int i = 0; i < size; i++){
            sum += gas[i] - cost[i];
            if(sum < 0){
                total += sum;
                sum = 0;
                ans = i + 1;
            }
        }
        total += sum;
        return total < 0? -1: ans;
    }
};