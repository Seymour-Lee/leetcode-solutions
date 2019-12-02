class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n, 0);
        vector<int> num(n, 0);
        for(auto b: bookings){
            num[b[0]-1] += b[2];
            if(b[1] < n) num[b[1]] -= b[2];
        }
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += num[i];
            ans[i] = sum;
            // if(num[i] < 0) sum += num[i];
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n, 0);
        vector<int> num(n, 0);
        for(auto b: bookings){
            num[b[0]-1] += b[2];
            if(b[1] < n) num[b[1]] -= b[2];
        }
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += num[i];
            ans[i] = sum;
            // if(num[i] < 0) sum += num[i];
        }
        return ans;
    }
};