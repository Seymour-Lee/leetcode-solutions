# 0x00 基本算法

## 0x01 位运算

* 

## 0x02 递推与递归



## 0x03 前缀和差分



## 0x04 二分



## 0x05 排序



## 0x06 倍增



## 0x07 贪心



## 0x08 总结与练习



# 0x10 基本数据结构





# 0x50 动态规划

## 算法提高课

* 记算法原理和代码模版是非常重要的（定理，公式）
* 算法提高课是讲定理、公式的应用
* 通过已经做过的题（知识点），来解决当前的问题
* 

### 数字三角形模型

#### AcWing 1015.摘花生 

##### 题目大意

给一个矩阵，矩阵每个元素是一个分数。从左上到右下，只能向右或者向下，求最大的得分数。

##### 思路

二维dp，dpij表示在ij位置的最大分数，那么dpij = gij + max(dp\[i-1\]\[j\], dp\[i\]\[j-1\])。需要注意处理边界条件。

##### 代码

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int r, c;
        cin >> r >> c;
        vector<vector<int>> g = vector<vector<int>>(r, vector<int>(c));
        for(int i = 0; i < r; i++) for(int j = 0; j < c; j++) cin>>g[i][j];
        for(int i = 0; i < r; i++) for(int j = 0; j < c; j++) g[i][j] += max(i-1 >= 0? g[i-1][j]: 0, j-1 >= 0? g[i][j-1]: 0);
        cout<<g.back().back()<<endl;
    }
    return 0;
}
```



#### AcWing 1018. 最低通行费

##### 题目大意

给一个矩阵，矩阵每个元素是一个分数。从左上到右下，只能向右或者向下，求最小的得分数。

##### 思路

二维dp，dpij表示在ij位置的最大分数，那么dpij = gij + min(dp\[i-1\]\[j\], dp\[i\]\[j-1\])。需要注意处理边界条件。

##### 代码

```C++
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<vector<int>> g(N, vector<int>(N));
    for(int i = 0; i < N; i++) for(int j = 0; j < N; j++){
        cin >> g[i][j];
        int minval = min(i-1 >= 0? g[i-1][j]: INT_MAX, j-1 >= 0? g[i][j-1]: INT_MAX);
        g[i][j] += minval == INT_MAX? 0: minval;
    }
    cout<<g[N-1][N-1];
    return 0;
}

```



###最长上升子序列模型



 

## 0x51 线性dp

