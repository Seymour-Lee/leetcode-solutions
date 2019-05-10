class Solution {
public:
    Solution(vector<int> w) {
        srand(time(0));
        sum = 0;
        if(w.size() == 0) return;
        vec.push_back(w[0]);
        for(int i = 1; i < w.size(); i++)
            vec.push_back(w[i]+vec.back());
        sum = vec.back();
    }
    
    int pickIndex() {
        int target = (rand() % sum) + 1;
        int l = 0;
        int r = vec.size()-1;
        while(l <= r){
            int m = l + (r - l) / 2;
            if(m-1 >= 0 && vec[m-1] < target && target <= vec[m]) return m;
            if(m-1 < 0 && target <= vec[m]) return m;
            if(vec[m] > target) r = m-1;
            else{ // vec[m] < target
                l = m+1;
            }
        }
        return r;
    }
    
private:
    vector<int> vec;
    int sum;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */