class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int result = 0;
        vector<int> count(121, 0);
        for(auto age: ages) count[age]++;
        for(int i = 0; i <= 120; i++){
            int a = count[i];
            for(int j = 0; j <= 120; j++){
                int b = count[j];
                if(i * 0.5 + 7 >= j) continue;
                if(i < j) continue;
                if(i < 100 && 100 < j) continue;
                result += (i == j? a * (b - 1): a * b);
            }
        }
        return result;
    }
};

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int ans = 0;
        vector<int> count(121, 0);
        for(auto age: ages) count[age]++;
        for(int i = 0; i <= 120; i++){
            int a = count[i];
            for(int j = 0; j <= 120; j++){
                int b = count[j];
                if(i * 0.5 + 7 >= j) continue;
                if(i < j) continue;
                if(i < 100 && 100 < j) continue;
                ans += (i == j? a * (b - 1): a * b);
            }
        }
        return ans;
    }
};