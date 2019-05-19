# Solutions

## References


## 961. N-Repeated Element in Size 2N Array
We can use hashtable to solve this problem easily, but there is a random way to solve this problem.
```C++
class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        while(true){
            int a = rand()%A.size();
            int b = rand()%A.size();
            if(a != b && A[a] == A[b]) return A[a];
        }
    }
};
```
