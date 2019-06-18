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

class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        return dfs(preorder, 0, preorder.size());
    }
    
private:
    bool dfs(vector<int> &p, int l, int r){
        if(l >= r) return true;
        int maxval = p[l++];
        int m = l;
        while(m < r && p[m] < maxval) m++;
        int pos = m;
        while(pos < r) if(p[pos++] < maxval) return false;
        return dfs(p, l, m) && dfs(p, m, r);
    }
};

class Solution {
public:
    int pos = 0;
    bool verifyPreorder(vector<int>& preorder, int minval = INT_MIN, int maxval = INT_MAX) {
        if(pos == preorder.size() || preorder[pos] > maxval) return true;
        int midval = preorder[pos++];
        return midval > minval && verifyPreorder(preorder, minval, midval) && verifyPreorder(preorder, midval, maxval);
    }
};