





### 376. Wiggle Subsequence

#### 题目大意

一个int的序列，每个元素按照增减增减或减增减增的顺序，那么满足wiggle，给一个array，求最长的wiggle subsequence。

#### 思路

显然是个dp的问题。因为有增减增减和减增减增两种情况，所以单个数据结构记录dp值，是不够的。不妨用两个vector来记录，inc和des。inc[i]表示以num[i]结尾的，最后一位为增的最长序列；des[i]表示以num[i]结尾的，最后一位为减的最长序列。初始化时，inc和des的每个元素置为1，用一个int ans来返回结果。

这题实际上贪心也可以解。

#### Code

```C++
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();
        int ans = 1;
        vector<int> inc(nums.size(), 1);
        vector<int> dec(nums.size(), 1);
        for(int i = 1; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]) inc[i] = max(inc[i], dec[j]+1);
                if(nums[j] > nums[i]) dec[i] = max(dec[i], inc[j]+1);
            }
            ans = max({ans, inc[i], dec[i]});
        } 
        return ans;
    }
};

// Greedy
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();
        int inc = 1;
        int dec = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[i-1]) inc = dec+1;
            if(nums[i] < nums[i-1]) dec = inc+1;
        }
        return max(inc, dec);
    }
};
```

