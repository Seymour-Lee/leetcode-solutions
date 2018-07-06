# Solutions of Leetcode



## 1. Two Sum

**题目描述**

Given an array of integers, return **indices** of the two numbers such that they add up to a specific target.

You may assume that each input would have **exactly** one solution, and you may not use the *same* element twice.

**Example:**

```
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
```



**解题思路**

用map做映射，index -> target - value



## 2. Add Two Numbers

**题目描述**

You are given two **non-empty** linked lists representing two non-negative integers. The digits are stored in **reverse order** and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

**Example**

```
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
```



**解题思路**

双指针分别跟着两个List，一个工作指针负责构建新的List，根据双指针是否为空决定给该位的value赋值0或pointer->val。最后根据carry位来决定是否new一个最高位的节点。

链表类题目需要返回链表时，可new一个名为dummyHead的头节点，最后return dummyHead->next。



## 3. Longest Substring Without Repeating Characters

**题目描述**

Given a string, find the length of the **longest substring** without repeating characters.

**Examples:**

Given `"abcabcbb"`, the answer is `"abc"`, which the length is 3.

Given `"bbbbb"`, the answer is `"b"`, with the length of 1.

Given `"pwwkew"`, the answer is `"wke"`, with the length of 3. Note that the answer must be a **substring**, `"pwke"`is a *subsequence* and not a substring.



**解题思路**

滑动窗口，若set中含窗口右侧的元素，则窗口左边界右移；否则窗口右边界右移，并向set中添加新的元素。



## 7. Reverse Integer

**题目描述**

Given a 32-bit signed integer, reverse digits of an integer.

**Example 1:**

```
Input: 123
Output: 321
```

**Example 2:**

```
Input: -123
Output: -321
```

**Example 3:**

```
Input: 120
Output: 21
```

**Note:**
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.



**解题思路**

对原数模10，除10。对result乘10，加模10的结果。加之前判断result和模10结果与INT上下界的大小关系。















































































