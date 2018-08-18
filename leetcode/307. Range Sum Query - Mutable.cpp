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