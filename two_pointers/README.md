# Solutions

## References


## 003. Longest Substring Without Repeating Characters
We can use two pointers to solve this problem. Pointer i points to the left bound of the window, while pointer j points to the next element of the right bound, in other words, the next element we are going to consider. Like many dp/2_pointers problem, we need to inilize the boundary condition, s[0].

### Optimization
We concern about the max window size without repeating characters, so we can use an array to record the next position(left bound of a window) of each character.



