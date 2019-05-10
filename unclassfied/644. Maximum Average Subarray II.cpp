class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double l = *min_element(nums.begin(), nums.end());
        double r = *max_element(nums.begin(), nums.end());
        while(r - l > 0.00001){
            double m = l + (r - l) / 2;
            if(islarger(nums, m, k)) r = m;
            else l = m;
        }
        return l;
    }
    
private:
    bool islarger(vector<int> &num, double mid, int k){
        double sum = 0, prev_sum = 0, min_sum = 0;
        for(int i = 0; i < num.size(); i++){
            sum += num[i] - mid;
            if(i >= k){
                prev_sum += num[i-k] - mid;
                min_sum = min(prev_sum, min_sum);
            }
            if(i >= k-1 && sum > min_sum) return false;
        }
        return true;
    }
};