/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int p = peak(target, mountainArr);
        int l = binary(target, mountainArr, 0, p+1);
        if(l != -1) return l;
        int r = binary1(target, mountainArr, p, mountainArr.length());
        if(r != -1) return r;
        return -1;
    }
    
private:
    int binary(int target, MountainArray &A, int l, int r){
        while(l < r){
            int m = l + (r - l) / 2;
            int val = A.get(m);
            if(val == target) return m;
            if(val < target) l = m+1;
            else r = m;
        }
        return -1;
    }
    
    int binary1(int target, MountainArray &A, int l, int r){
        while(l < r){
            int m = l + (r - l) / 2;
            int val = A.get(m);
            if(val == target) return m;
            if(val > target) l = m+1;
            else r = m;
        }
        return -1;
    }
    
    int peak(int target, MountainArray &A){
        int l = 0;
        int r = A.length()-1;
        while(l <= r){
            int m = l + (r - l) / 2;
            int prev = A.get(m-1);
            int next = A.get(m+1);
            int val = A.get(m);
            if(A.get(m-1) < val && val > next) return m;
            else if(prev < val && val < next) l = m;
            else if(prev > val && val > next) r = m;
        }
        return 0;
    }
};