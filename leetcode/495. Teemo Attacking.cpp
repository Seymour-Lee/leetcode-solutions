class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int result = 0;
        int end = 0;
        for(auto t: timeSeries){
            if(t >= end){
                result += duration;
                end = t + duration;
            }
            else{ // t < end
                result += t + duration - end;
                end = t + duration;
            }
        }
        return result;
    }
};