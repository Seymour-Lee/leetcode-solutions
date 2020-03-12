class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() < 2) return nums.size();
        vector<int> up(nums.size(), 1);
        vector<int> down(nums.size(), 1);
        for(int i = 1; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    up[i] = max(up[i], down[j]+1);
                }
                else if(nums[i] < nums[j]){
                    down[i] = max(down[i], up[j]+1);
                }
            }
        }
        return max(up.back(), down.back());
    }
};

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();
        int ans  = 1;
        vector<int> dpinc(nums.size(), 1);
        vector<int> dpdec(nums.size(), 1);
        for(decltype(nums.size()) i = 1; i < nums.size(); i++){
            for(decltype(i) j = 0; j < i; j++){
                dpinc[i] = nums[i] > nums[j]? max(dpdec[j]+1, dpinc[i]): dpinc[i];
                dpdec[i] = nums[i] < nums[j]? max(dpinc[j]+1, dpdec[i]): dpdec[i];
            }
            ans = max(ans, max(dpinc[i], dpdec[i]));
        }
        return ans;
    }
};

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();
        int inc = 1;
        int dec = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[i-1]) inc = dec+1;
            if(nums[i] < nums[i-1]) dec = inc+1;
        }
        return max(inc, dec);
    }
};

class Solution {
public:
    int wiggleMaxLength(vector<int>& A) {
        vector<int> up(A.size(), 1), dw(A.size(), 1);
        for(int j = 0; j < A.size(); j++) for(int i = 0; i < j; i++){
            if(A[i] < A[j]) up[j] = max(up[j], dw[i]+1);
            if(A[i] > A[j]) dw[j] = max(dw[j], up[i]+1);
        }
        return A.size()? max(*max_element(up.begin(), up.end()), *max_element(dw.begin(), dw.end())): 0;
    }
};

class Solution {
public:
    int wiggleMaxLength(vector<int>& A) {
        vector<int> up(A.size(), 1), dw(A.size(), 1);
        for(int j = 0; j < A.size(); j++) for(int i = 0; i < j; i++){
            if(A[i] < A[j]) up[j] = max(up[j], dw[i]+1);
            if(A[i] > A[j]) dw[j] = max(dw[j], up[i]+1);
        }
        return A.size()? max(*max_element(up.begin(), up.end()), *max_element(dw.begin(), dw.end())): 0;
    }
};