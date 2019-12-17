# References to solutions

## Topics

- [ ] Segment Tree
- [x] Binary Indexed Tree
- [x] Binary Search Tree
- [x] Trie
- [ ] Dynamic Programming
- [x] Binary Search



lower_bound 和 upper_bound 均用于求下界。对于某个target，lower求

```C++
int lower_bound(vector<int> nums, int target){
	int l = 0, r = nums.size();
 	while(l < r){
  	int m = l + (r - l) / 2;
    if(nums[m] < target) l = m + 1;
    else r = m;
  }
  return l;
}
```


