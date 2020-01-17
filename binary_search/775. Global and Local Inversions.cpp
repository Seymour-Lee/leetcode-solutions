class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        for(int i = 0; i < A.size(); i++)
            if(abs(A[i] - i) > 1) return false;
        return true;
    }
};

class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int local = 0;
        for(int i = 0; i < A.size()-1; i++) if(A[i] > A[i+1]) local++;
        int global = 0;
        set<int> nums = {A.back()};
        for(int j = A.size()-2; j >= 0; j--){
            auto i = nums.lower_bound(A[j]);
            global += distance(nums.begin(), i);
            // cout<<global<<endl;
            nums.insert(A[j]);
        }
        return local == global;
    }
};