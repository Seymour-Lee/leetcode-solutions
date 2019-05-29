# Solutions

## References

### Member
#### 1d

[053. Maximum Subarray](#053. Maximum Subarray)

[121.Best Time to Buy and Sell Stock](#121. Best Time to Buy and Sell Stock)

[198. House Robber](#198. House Robber)

[256. Paint House](#256. Paint House)

[303. Range Sum Query - Immutable](#303. Range Sum Query - Immutable)

[509. Fibonacci Number](#509. Fibonacci Number)

[740. Delete and Earn](#740. Delete and Earn)

[746. Min Cost Climbing Stairs](#746. Min Cost Climbing Stairs)

[1048. Longest String Chain](#1048. Longest String Chain)










#### 2d

[005. Longest Palindromic Substring](#005. Longest Palindromic Substring)



### Range

#### 1d

[070. Climbing Stairs](#070. Climbing Stairs)

[338. Counting Bits](#338. Counting Bits)



#### 2d

[516. Longest Palindromic Subsequence](#516. Longest Palindromic Subsequence)

[062. Unique Paths](#062. Unique Paths)

[063. Unique Paths II](#063. Unique Paths II)








## 005. Longest Palindromic Substring
**type: member-2d**
We can use a 2-d vector to record whether [i][j] is a palindromic.

### A better way
reverse the string, find the longest common substring of two string. We can not use Trie, a counter-example is "aacazbcaa". I still do not find a better way to solve, maybe we can use kmp?

### A better better way
We can construct the palindromic from the center character.
```C++
class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        for(int pos = 0; pos < s.size(); pos++){
            int i = pos, j = pos;
            while(i >= 0 && j < s.size() && s[i] == s[j]) i--, j++;
            if(j-i-1 > ans.size()) ans = s.substr(i+1, j-i-1);
            i = pos, j = pos+1;
            while(i >= 0 && j < s.size() && s[i] == s[j]) i--, j++;
            if(j-i-1 > ans.size()) ans = s.substr(i+1, j-i-1);
        }
        return ans;
    }
};
```



## 053. Maximum Subarray

**type: member 1d**

dp[i] = maxSubarray end with nums[i]



## 062. Unique Paths

**type: member 2d**

dp[i]\[j] = ways to pos[i]\[j]



## 063. Unique Paths II

**type: member 2d**

dp[i]\[j] = ways to pos[i]\[j]



## 070. Climbing Stairs

**type: range 1d**

dp[i] = the number of ways to level i



## 121. Best Time to Buy and Sell Stock

**type: member 1d**

dp[i] = max value to get if sell on day[i]



## 139. Word Break

**type: member 1d**

dp[i] = whether str.substr(0, i+1) is true



## 198. House Robber

**type: member 1d**
dp[i] = max values rob or not house[i]
Similar to 740. Delete and Earn



## 256. Paint House

**type: member 1d**

dp[i] = min cost with color[i]



## 303. Range Sum Query - Immutable

**type: member 1d**

dp[i] = sum from 0 to [i]



## 338. Counting Bits

**type: range 1d** 
[i] represent the number of bits of i



## 494. Target Sum

**type: range**
Given an array, and we can add +/- previous each problem. Return the number of ways to get the result equal to a target.
The length of the array will not exceed 20, and the elements will be positive, the sum of all elements will not exceed 1000.

### A naive way
Since the problem tells us the length of the array will not exceed 20, so we can use backtracking to solve this problem.

### A better way



## 509. Fibonacci Number

**type: member 1d**

dp[i] = i-th Fibonacci Number



## 516. Longest Palindromic Subsequence
**type: member 2d**

### A straight way
let dp[i]\[j\] = the longest palindromic subsequence from i to j

### A tricky way
reverse string s, find the longest common subsequence



## 740. Delete and Earn

**type: member 1d**
Obviously, it is a dynamic programming problem, we can use the same way in House Robber to solve this problem. Like many dp/2_pointers problem, we need to pay more attention to initilization.



## 746. Min Cost Climbing Stairs

**tpye: member 1d**

dp[i] = min cost to level i



## 1048. Longest String Chain

**type: member 1d**

dp[i] = max end with [i]







