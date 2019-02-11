描述2道算法题的思路和时间复杂度（15min）

工作方式小调查 (10min)



### D - 1. Longest Palindrome Substring

leetcode 5 dp 给外星人送货

```C++
string longestPalindromicSubstring(string s){
    if(s.size() <= 1) return s;
    string ans = string(1, s[0]);
    vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
    for(int i = 0; i < dp.size(); i++) dp[i][i] = 1;
    for(int i = 0; i < dp.size()-1; i++){
        if(s[i] == s[i+1]){
            dp[i][i+1] = 2;
            ans = s.substr(i, 2);
        }
    }
    for(int len = 3; len <= s.size(); len++){
        for(int i = 0; i+len-1 < s.size(); i++){
            int j = i+len-1;
            if(s[i] == s[j] && dp[i+1][j-1] != 0){
                dp[i][j] = dp[i+1][j-1]+2;
                if(dp[i][j] > ans.size()) ans = s.substr(i, len);
            }
        }
    }
    return ans;
}
```



### D - 2. Most Frequent Used Words

leetcode 819, 怎么去掉 ' ？

```C++
vector<string> retriveMostFrequentlyUsedWords(string paragraph, vector<string>& banned) {
    transform(paragraph.begin(), paragraph.end(), paragraph.begin(), ::tolower);
    set<string> s;
    for(auto str: banned){
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        s.insert(str);
    } 
    map<string, int> str2times;
    int i, j;
    for(i = 0, j = 0; i < paragraph.size() && j < paragraph.size(); i = j){
        string str;
        while(j < paragraph.size() && 'a' <= paragraph[j] &&  paragraph[j] <= 'z') j++;
        str = paragraph.substr(i, j-i);
        str2times[str]++;
        if(j == paragraph.size()) break;
        while(j < paragraph.size() && !('a' <= paragraph[j] &&  paragraph[j] <= 'z'))
            j++;
    }
    int most = 0;
    vector<string> ans;
    for(auto item: str2times) if(s.find(item.first) == s.end()){
        if(item.second > most){
            ans = {item.first};
            most = item.second;
        }
        else if(item.second == most) ans.push_back(item.first);
    }
    return ans;
}


vector<string> retriveMostFrequentlyUsedWords1(string paragraph, vector<string>& banned) {
    std::replace(paragraph.begin(), paragraph.end(), '\'', ' ');
    std::replace(paragraph.begin(), paragraph.end(), '.', ' ');
    std::replace(paragraph.begin(), paragraph.end(), ',', ' ');
    std::replace(paragraph.begin(), paragraph.end(), '?', ' ');
    std::replace(paragraph.begin(), paragraph.end(), '!', ' ');
    std::replace(paragraph.begin(), paragraph.end(), ';', ' ');
    transform(paragraph.begin(), paragraph.end(), paragraph.begin(), ::tolower);
    unordered_set<string> seen;
    for(auto str: banned){
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        seen.insert(str);
    }
    unordered_map<string, int> str2times;
    istringstream is(paragraph);
    string cur;
    while(getline(is, cur, ' ')) if(cur.size() > 0 && seen.find(cur) == seen.end()) str2times[cur]++;
    map<int, vector<string>> ans;
    for(auto p: str2times) {
        // cout<<p.first<<" "<<p.second<<endl;
        ans[p.second].push_back(p.first);
    }
    return ans.rbegin()->second;
}
```

OA题目要求回vector\<string\>



### D - 3. Count number of substrings with exactly k distinct characters
substrings do not need to be distinct

lower cases only

```C++
// O(n^2)
int findKDistinctNum(string str, int k){
    int n = str.size(); 
    int ans = 0; 
    int cnt[26]; 
    for (int i = 0; i < n; i++) { 
        int dist_count = 0; 
        memset(cnt, 0, sizeof(cnt)); 
        for (int j=i; j<n; j++) { 
            if (cnt[str[j] - 'a'] == 0) dist_count++; 
            cnt[str[j] - 'a']++; 
            if (dist_count == k) ans++; 
            if(dist_count > k) break; 
        } 
    } 
    return ans; 
}
```



set + two pointers?



变形：



### D - 4. MaximumMinimumPath

You are gonna climb mountains represented by a matrix. Each integer in the matrix represents the altitude at that point. You are supposed to climb from the top-left corner to the bottom-right corner and only move rightward or downward in each step. 

You can have many paths to do so. Each path has a minimum altitude. Find the maximum among all the minimum altitudes of all paths. 

e.g. 545136 

Three paths: 5 1 3 6，5 4 3 6，5 4 5 6. Minimums are 1, 3, 4 respectively. Return the maximum in them which is 4. 

another example: 

[8, 4, 7]
 [6, 5, 9]
 3 paths: 8-4-7-9 min: 4 8-4-5-9 min: 4 8-6-5-9 min: 5 return: 5 

You should use DP. Similar to Leetcode 174. Dungeon Game 

```C++
int maxminpath(vector<vector<int>> m){
    if(m.size() == 0 || m[0].size() == 0) return 0;
    vector<int> ans(m[0].size(), m[0][0]);
    for(int i = 1; i < m[0].size(); i++) ans[i] = min(ans[i-1], m[0][i]);
    for(int i = 1; i < m.size(); i++){
        ans[0] = min(ans[0], m[i][0]);
        for(int j = 1; j < m[i].size(); j++){
            ans[j] = (ans[j] < m[i][j] && ans[j-1] < m[i][j])? max(ans[j-1], ans[j]): m[i][j];
        }
    }
    return ans.back();
}
```

or dfs

### D - 5. Subtree: Maximum average node

情景1:算codes speed

情景2:算product category

最大平均子树 注意：**叶子不能是子树，子节点不止两个**，testcase7/7全过

lintcode 597

**Description** Given a binary tree, find the subtree with maximum average. Return the root of the 

subtree. 

**Example** Given a binary tree: 

​	1

​       / \ 

​    -5   11 

​    / \   / \ 

   1  2 4  -2 

return the node 11. 

Your problem can be different in ways like -- it may not be a binary tree or the average doesn't include the root of the substree. 

reference code: Code 

```C++
class Solution {
public:
    /**
     * @param root: the root of binary tree
     * @return: the root of the maximum average of subtree
     */
    TreeNode * findSubtree2(TreeNode * root) {
        // write your code here
        double maxaverage = -std::numeric_limits<double>::max();
        cout<<maxaverage<<endl;
        TreeNode *ans = nullptr;
        dfs(root, &ans, maxaverage);
        return ans;
    }
    
private:
    pair<int, int> dfs(TreeNode *root, TreeNode **ans, double &maxaverage){
        if(root == nullptr) return {0, 0};
        auto l = dfs(root->left, ans, maxaverage);
        auto r = dfs(root->right, ans, maxaverage);
        int num = l.first + r.first + 1;
        int sum = l.second + r.second + root->val;
        double average = double(sum) / double(num);
        // cout<<average<<endl;
        if(average > maxaverage) *ans = root, maxaverage = average;
        return {num, sum};
    }
};
```



### D - 6. Minimum Distances

Amazon要建building，有图

给了一个2d的grid，0表示沟壑，不允许进去；1表示平地，可以走；9表示障碍物，要清除。机器人从左上角开始走，求干掉障碍物的最小步数。

显然BFS

```C++
int removeObstacle(int numRows, int numColumns, int **lot){
    
}

int removeObstacle(int numRows, int numColumns, vector<vector<int>> lot){
    int ans = 0;
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    queue<pair<int, int>> q;
    q.push({0, 0});
    while(q.empty() == false){
        int size = q.size();
        while(size--){
            pair<int, int> p = q.front(); q.pop();
            int x = p.first, y = p.second;
            if(lot[x][y] == 9) return ans;
            for(auto d: dirs){
                int nx = x + d[0], ny = y + d[1];
                if(0 <= nx && nx < numRows && 0 <= ny && ny < numColumns &&
                   lot[nx][ny] != 0) q.push({nx, ny});
            }
        }
        ans++;
    }
    return -1;
}
```



### D - 7. K Nearest Points

背景是卡车送货

```C++
vector<pair<int, int>> topk(int n, vector<vector<int>> points, int k){
    vector<pair<int, int>> ans;
    vector<vector<long long>> sorted;
    for(auto p: points) sorted.push_back({p[0], p[1], p[0]*p[0]+p[1]*p[1]});
    auto f = [](vector<long long> a, vector<long long> b){
        return a[2] < b[2];
    };
    sort(sorted.begin(), sorted.end(), f);
    for(int i = 0; i < k; i++) ans.push_back({sorted[i][0], sorted[i][1]});
    return ans;
}


```



### D - 8. Movies in flight -- Two Sum closest <= target

还有个题是double类型的

You are taking a flight and you wanna watch two movies. You are given int[] dur which includes all the
movie durations. You are also given the duration of the flight which is d in minutes. Now, you need to
pick two movies and the total duration of the two movies is less than or equal to (d - 30min). Find the
pair of movies with the most total duration. If multiple found, return the pair with the longest movie.

```C++
pair<int, int> twosum(vector<int> nums, int target){
    sort(nums.begin(), nums.end());
    int i = 0, j = nums.size()-1;
    pair<int, int> ans;
    int mindiff = INT_MAX;
    while(i < j){
        if(nums[i] + nums[j] <= target){ // should use <=
            if(target - nums[i] - nums[j] < mindiff){
                ans = {nums[i], nums[j]};
                mindiff = target - nums[i] - nums[j];
            }
            i++;
        }
        else j--;
    }
    return ans;
}
```

或者在两个list里找和小于target的所有pair

O(n^2)两层for

O(nlogn)用hash

```C++
vector<pair<int, int>> twosum(vector<pair<int, int>> f, vector<pair<int, int>> r, int target){
    vector<pair<int, int>> ans;
    map<int, vector<int>> dis2id;
    for(auto e: f) dis2id[e.second].push_back(e.first);
    int maxsum = INT_MIN;
    for(auto e: r){
        int id = e.first, dis = e.second;
        auto itor = prev(dis2id.upper_bound(target-dis));
        if(itor == dis2id.end()) continue;
        int sum = dis + itor->first;
        if(sum > maxsum){
            ans = {};
            for(auto i: itor->second) ans.push_back({i, id});
            maxsum = sum;
        }
        else if(sum == maxsum){
            for(auto i: itor->second) ans.push_back({i, id});
        }
    }
    return ans;
}
```



### 9. Reorder Log Files







### 10. Given an array of letters and a window size k, return subarrays of size k with no duplicates. 

e.g. [a, d, f, g, k, g] and window size k = 4 return [[a, d, f, g], [d, f, g, k]] 



### D - 11. MST

Connect all cities with least cost.

```C++
int count;
    vector<int> p;
    
    int f(int x){
        if(p[x] == -1) return x;
        return f(p[x]);
    }
    
    void u(int x, int y){
        int xp = f(x);
        int yp = f(y);
        if(xp != yp) p[xp] = yp, count--;
    }
```



### D - 12. Merge Sorted List

```C++
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode *dummy = new ListNode(-1);
	ListNode *cur = dummy;
    while(l1 && l2){
    	if(l1->val <= l2->val) cur->next = l1, cur = cur->next, l1 = l1->next;
        else cur->next = l2, cur = cur->next, l2 = l2->next;
    }
    if(l1) cur->next = l1;
    if(l2) cur->next = l2;
    return dummy->next;
}
```





Work simulation(原则有先后顺序)
目前两大做题中最重要原则：
1.requirement排在第一，deadline第二。. 1point3acres
2.有manager出现的选项无脑选manager，manager就是一个组的地头蛇。. 1point3acres

[Amazon](http://www.amazon.com/b?_encoding=UTF8&tag=1p3a-guanlian-20&linkCode=ur2&linkId=89c11e2c5b86155c5422f19cca1e9880&camp=1789&creative=9325&node=5)9条主要原则
原则1：客户是上帝，requirement优先，任何影响上帝的事情都不能干，
        如某个requirement影响了上帝的体验， 
        你就是死键盘上也不能砍了，宁愿miss deadline
原则2：为长远考虑，即客户几年之后可能会出现的需求也要考虑到，
        不会为了交付短期的deadline，
        而牺牲长期的价值。（比如 global api  和 local api）
原则3：最高标准，“最高”对应上面的“长远”。
原则4：一般情况，能请示manager就请示manager，manager一般不会出错
原则5：速度很重要，决策和行动都可以改变，因此不需要进行过于广泛的推敲
        ，但提倡在深思熟虑下进行冒险。
原则6：不需要一定要坚持“非我发明”，需求帮助也是可以的，四处寻找创意
        ，并且接受长期被误导的可能. From 1point 3acres bbs
原则7：敢于承担责任，任劳任怨，比如领导说谁会java，你会你就跳出来说我会
原则8：对问题刨根问底，探究细节
原则9：服从大局（团队比个人重要）

打分不是关键，排序才是关键。
大部分情况下其实并没有deadline 和 requirement谁更好，更多还是在
这个组合中你对ddl 和 requirement整体的权衡。

每个选项可以评1~5分，most effective 是5，然后1是least effective
刚开始让你看一些介绍amazon工作环境的视频
1.上来给一段video，场景是项目的晨会，就是把team正在推进的项目描述一下，
期间会有多个项目和你有关系，后面会遇到
2.进入工作界面，可以看到接受到邮件，接收到的instant message
3.进入工作状态。会有同事给你发邮件，发信息。需要你对他们提出的问题做一些判断，也就是给解决问题的选项评分
4.一个21题，有log分析bug，有给报告出问题结论，有判断项目 走向的