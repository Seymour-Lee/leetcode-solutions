class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people, 0);
        int counter = 1;
        while(candies){
            for(int i = 0; candies && i < num_people; i++, counter++){
                int dis = min(counter, candies);
                ans[i] += dis;
                candies -= dis;
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people, 0);
        int counter = 1;
        while(candies){
            for(int i = 0; candies && i < num_people; i++, counter++){
                int dis = min(counter, candies);
                ans[i] += dis;
                candies -= dis;
            }
        }
        return ans;
    }
};