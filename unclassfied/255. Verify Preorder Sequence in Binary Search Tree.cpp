class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        return preorder.size() == recursive(preorder, INT_MIN, INT_MAX, 0);
    }
    
private:
    int recursive(vector<int> &preorder, int minv, int maxv, int l){
        if(l >= preorder.size() || preorder[l] > maxv || preorder[l] < minv)
            return l;
        int r = recursive(preorder, minv, preorder[l], l+1);
        return recursive(preorder, preorder[l], maxv, r);
    }
};