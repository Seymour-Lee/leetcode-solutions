class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> left2right(ratings.size(), 1);
        vector<int> right2left(ratings.size(), 1);
        for(int i = 1; i < left2right.size(); i++)
            left2right[i] = (ratings[i] > ratings[i-1]? left2right[i-1]+1: 1);
        for(int i = right2left.size()-2; i >= 0 ; i--)
            right2left[i] = (ratings[i] > ratings[i+1]? right2left[i+1]+1: 1);
        int minToGive = 0;
        for(int i = 0; i < left2right.size(); i++) 
            minToGive += max(left2right[i], right2left[i]);
        return minToGive;
    }
};