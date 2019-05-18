# Solutions

## References


## One-D dp
### 740. Delete and Earn
Obviously, it is a dynamic programming problem, we can use the same way in House Robber to solve this problem. Like many dp/2_pointers problem, we need to pay more attention to initilization.

## Two-D dp
### 005. Longest Palindromic Substring
We can use a 2-d vector to record whether [i][j] is a palindromic.
#### A better way
reverse the string, find the longest common substring of two string. We can not use Trie, a counter-example is "aacazbcaa". I still do not find a better way to solve, maybe we can use kmp?

#### A better better way
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

## Range dp
### 494. Target Sum
Given an array, and we can add +/- previous each problem. Return the number of ways to get the result equal to a target.
The length of the array will not exceed 20, and the elements will be positive, the sum of all elements will not exceed 1000.

#### A naive way
Since the problem tells us the length of the array will not exceed 20, so we can use backtracking to solve this problem.

#### A better way




## Tree-like dp

