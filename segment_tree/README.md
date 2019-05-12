# Solutions

## References

## Template

Some facts:

* We do not use t[0] in our codes
* The tree is perfect
* The value at nums[p] is in t[p+n]
* Suppose L is odd , then L is right child, and it parent is (L+1)/2, else if L is even, it is left child and its parent if (L-1)/2.
* zkw0 works well when the input range is small
* 

```C++
// https://codeforces.com/blog/entry/18051

class zkw0{
public:
    zkw0(vector<int> nums){
        n = nums.size();
        t = vector<int>(2*n, 0);
        for(int i = 0; i < n; i++) t[n+i] = nums[i];
        build();
    }
    
    int query_interval(int l, int r){ // [l, r)
        int ans = 0;
      	// nums =          [1, 3, 5]; n = 3;
      	// t    = [0, 9, 8, 1, 3, 5];
      	//         0  1  2  3  4  5
      	// input: l = 0, r = 2 -> [0, 2)
      	// output should be nums[0] + nums[1] = 4;
      	// init : l = 3, r = 5; l < r? y;
      	// loop0: l&1? y -> ans += t[3], t[3] = 1, ans = 1, l = 4;
      	// 				r&1? y -> ans += t[4], t[4] = 3, ans = 4, r = 4;
      	//				l = 2, r = 2; l < r? n;
        for(l += n, r += n; l < r; l >>= 1, r >>= 1){
            if(l&1) ans += t[l++]; // if l is odd
            if(r&1) ans += t[--r]; // if r is odd
        }
        return ans;
    }
    
    void add_interval(int l, int r, int val){
        for(l += n, r += n; l < r; l >>= 1, r >>= 1){
            if(l&1) t[l++] += val;
            if(r&1) t[--r] += val;
        }
    }
    
    void update_single(int p, int val){
        for(t[p += n] = val; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
    }

    int query_snigle(int p){
        return t[p+n];
    }
    
private:
    vector<int> t;
    int n;
    
    void build(){
        for(int i = n-1; i > 0; i--) t[i] = t[i<<1] + t[i<<1|1];
    }
};
```

