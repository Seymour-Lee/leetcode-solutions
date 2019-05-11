// MLE. Cause some segment cur many times in memo array
class NumArray {
public:
    NumArray(vector<int> nums) {
        for(auto num: nums) vals.push_back(num);
        tree = vector<vector<int>>(nums.size(), vector<int>{});
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < nums.size()-i; j++){
                tree[i].push_back(j == 0? vals[i+j]: tree[i][j-1]+vals[i+j]);
            }
        }
    }
    
    void update(int i, int val) {
        int diff = val - vals[i];
        vals[i] = val;
        for(int row = 0; row <= i; row++){
            for(int col = i; col < vals.size(); col++){
                tree[row][col-row] += diff;
            }
        }
    }
    
    int sumRange(int i, int j) {
        return tree[i][j-i];
    }
    
private:
    vector<int> vals;
    vector<vector<int>> tree;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */

class NumArray {
public:
    NumArray(vector<int> nums) {
        if(nums.size() == 0) return;
        length = nums.size();
        tree = vector<int>(nums.size() * 2, 0);
        for(int i = length, j = 0; i < 2 * length; i++, j++) tree[i] = nums[j];
        for(int i = length-1; i > 0; i--) tree[i] = tree[i*2] + tree[i*2+1];
    }
    
    void update(int i, int val) {
        int pos = i + length;
        tree[pos] = val;
        while(pos){
            int l = pos % 2 == 1? pos-1: pos;
            int r = pos % 2 == 1? pos: pos+1;
            tree[pos/2] = tree[l] + tree[r];
            pos = pos / 2;
        }
    }
    
    int sumRange(int i, int j) {
        i += length, j += length;
        int sum = 0;
        while(i <= j){
            if((i % 2) == 1){
                sum += tree[i];
                i++;
            }
            if((j % 2) == 0){
                sum += tree[j];
                j--;
            }
            i = i / 2;
            j = j / 2;
        }
        return sum;
    }
    
private:
    vector<int> tree;
    int length;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */

class SegmentTree{
public:
    SegmentTree(vector<int> &nums){
        len = nums.size();
        if(len == 0) return;
        // auto f = [](int n){
        //     if (n && !(n & (n - 1))) return n; 
        //     int count = 0;
        //     while( n != 0) n >>= 1, count += 1; 
        //     return 1 << count;
        // };
        int n = pow(2, 1+(int)log2(nums.size()));
        // or 
        // int n = f(nums.size());
        tree = vector<int>(2*n-1, 0);
        c(nums, 0, len-1, 0);
    }
    
    void update(int i, int val){
        if(len == 0) return;
        u(i, val, 0, len-1, 0);
    }
    
    int query(int i, int j){
        if(len == 0) return 0;
        return q(i, j, 0, len-1, 0);        
    }
    
    
private:
    vector<int> tree;
    int len;
    
    void c(vector<int> &nums, int l, int r, int pos){
        if(l == r){
            tree[pos] = nums[l];
            return;
        }
        int m = (l + r) / 2;
        c(nums, l, m, 2*pos+1);
        c(nums, m+1, r, 2*pos+2);
        tree[pos] = tree[2*pos+1] + tree[2*pos+2];
    }
    
    void u(int i, int val, int l, int r, int pos){
        if(i < l || r < i) return ;
        if(l == r){
            tree[pos] = val;
            return;
        }
        int m = (l + r) / 2;
        u(i, val, l, m, 2*pos+1);
        u(i, val, m+1, r, 2*pos+2);
        tree[pos] = tree[2*pos+1] + tree[2*pos+2];
    }
    
    int q(int i, int j, int l, int r, int pos){
        if(i <= l && r <= j) return tree[pos];
        if(j < l || r < i) return 0;
        int m = (l + r) / 2;
        return q(i, j, l, m, 2*pos+1) + q(i, j, m+1, r, 2*pos+2);
    }
};

class NumArray {
public:
    NumArray(vector<int> nums) {
        tree = new SegmentTree(nums);
    }
    
    void update(int i, int val) {
        tree->update(i, val);
    }
    
    int sumRange(int i, int j) {
        return tree->query(i, j);
    }
    
private:
    SegmentTree *tree;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */

class zkw{
public:
    zkw(vector<int> nums){
        n = nums.size();
        t = vector<int>(2*n, 0);
        for(int i = 0; i < nums.size(); i++) t[n+i] = nums[i];
        for(int i = n-1; i > 0; --i) t[i] = t[i*2] + t[i*2+1];
        // for(auto e: t) cout<<e<<" "; cout<<endl;
    }
    
    void u(int p, int val){
        for(t[p+=n] = val; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
        // for(auto e: t) cout<<e<<" "; cout<<endl;
    }
    
    int q(int l, int r){
        int ans = 0;
        for(l += n, r += n; l <= r; l >>= 1, r >>= 1){
            // cout<<l<<" "<<r-1<<endl;
            if(l&1) ans += t[l++];
            if((r&1) == 0) ans += t[r--];
        }
        return ans;
    }
    
private:
    vector<int> t;
    int n;
    int N = 1e5;
};

class NumArray {
public:
    NumArray(vector<int> nums) {
        tree = new zkw(nums);
    }
    
    void update(int i, int val) {
        tree->u(i, val);
    }
    
    int sumRange(int i, int j) {
        return tree->q(i, j);
    }
    
private:
    zkw *tree = nullptr;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */

class SegmentTree{
public:
    SegmentTree(vector<int> nums){
        n = nums.size();
        t = vector<int>(2*n, 0);
        for(int i = 0; i < n; i++) t[n+i] = nums[i];
        build();
    }
    
    int query(int l, int r){ // [l, r)
        int ans = 0;
        for(l += n, r += n; l < r; l >>= 1, r >>= 1){
            if(l&1) ans += t[l++];
            if(r&1) ans += t[--r];
        }
        return ans;
    }
    
    void update(int p, int val){
        for(t[p += n] = val; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
    }
    
private:
    vector<int> t;
    int n;
    
    void build(){
        for(int i = n-1; i > 0; i--) t[i] = t[i<<1] + t[i<<1|1];
    }
};

class NumArray {
public:
    NumArray(vector<int>& nums) {
        root = new SegmentTree(nums);
    }
    
    void update(int i, int val) {
        root->update(i, val);
    }
    
    int sumRange(int i, int j) {
        return root->query(i, j+1);
    }
    
private:
    SegmentTree *root;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */