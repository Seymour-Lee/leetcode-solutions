class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pos = m + n -1;
        m--;
        n--;
        while(m >= 0 || n >= 0){
            int one = m >= 0? nums1[m]: INT_MIN;
            int two = n >= 0? nums2[n]: INT_MIN;
            if(one > two){
                nums1[pos--] = one;
                m--;
            }
            else{
                nums1[pos--] = two;
                n--;
            }
        }
    }
};