class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        
        auto midptr = nums.begin() + n / 2;
        nth_element(nums.begin(), midptr, nums.end());
        int mid = *midptr;
        
        #define A(i) nums[(1+2*(i)) % (n | 1)]
        
        int i = 0, j = 0, k = n - 1;
        while(j <= k){
            if(A(j) > mid)
                swap(A(i++), A(j++));
            else if(A(j) < mid)
                swap(A(j), A(k--));
            else
                j++;
        }
    }
};

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int i = (nums.size()-1) / 2;
        int j = nums.size()-1;
        bool ii = true;
        for(int k = 0; k < nums.size(); k++){
            if(ii) ans.push_back(nums[i--]);
            else ans.push_back(nums[j--]);
            ii = !ii;
        }
        nums = ans;
    }
};

