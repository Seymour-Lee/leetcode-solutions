class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int lower = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int upper = lower--;
        while(k--){
            if(lower < 0 || (upper < n && abs(arr[upper] - x) < abs(x - arr[lower]))) upper++;
            else lower--;
        }
        return vector<int>(arr.begin()+lower+1, arr.begin()+upper);
    }
};

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = binary(arr, x);
        int r = l--;
        vector<int> ans;
        while(k--){
            if(r >= arr.size() || l >= 0 && abs(x-arr[l]) <= abs(arr[r]-x)) ans.push_back(arr[l--]);
            else ans.push_back(arr[r++]);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
    
private:
    int binary(vector<int> &arr, int target){
        int l = 0, r = arr.size();
        while(l < r){
            int m = l + (r - l) / 2;
            if(arr[m] < target) l = m + 1;
            else r = m;
        }
        return l;
    }
};

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = binary(arr, x);
        int r = l--;
        vector<int> ans;
        while(k--){
            if(r >= arr.size() || l >= 0 && abs(x-arr[l]) <= abs(arr[r]-x)) ans.push_back(arr[l--]);
            else ans.push_back(arr[r++]);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
    
private:
    int binary(vector<int> &arr, int target){
        int l = 0, r = arr.size();
        while(l < r){
            int m = l + (r - l) / 2;
            if(arr[m] < target) l = m + 1;
            else r = m;
        }
        return l;
    }
};