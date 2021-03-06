class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0;
        int right = nums.size()-1;
        while(true){
            int p = partition(nums, left, right);
            if(p == k-1) return nums[p];
            if(p > k - 1) right = p - 1;
            else left = p + 1;
        }
    }
    
private:
    int partition(vector<int> &nums, int left, int right){
        int pivot = nums[left];
        int l = left + 1;
        int r = right;
        while(l <= r){
            if(nums[l] < pivot && nums[r] > pivot){
                swap(nums[l++], nums[r--]);
            }
            if(nums[l] >= pivot) l++;
            if(nums[r] <= pivot) r--;
        }
        swap(nums[left], nums[r]);
        return r;
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int l = 0, r = nums.size()-1;
        while(l <= r){
            int pivot = partition(nums, l, r);
            if(pivot+1 == k) return nums[pivot];
            if(pivot+1 < k) l = pivot+1;
            else r = pivot-1;
        }
        return -1;
    }
    
private:
    int partition(vector<int> &nums, int l, int r){
        int s = l;
        int pivot = nums[l++];
        while(l <= r){
            if(nums[l] < pivot && pivot < nums[r]) swap(nums[l++], nums[r--]);
            if(nums[l] >= pivot) l++;
            if(nums[r] <= pivot) r--;
        }
        swap(nums[s], nums[r]);
        return r;
    }
};