### Coding

* lc103 Binary Tree Zigzag Level Order Traversal **BFS，用level判断是否逆序；stack？**

- 给一个由0和1组成的matrix，打印出duplicate的row的序列 **如果row的len小于32，直接压缩int，否则用string；不让转换类型的话，用trie**

- 问一个string input里 有没有duplicate words **只问true or false的话，直接变set，看set和vector的size是否一致。要是求有哪些重复的话，用hash**
- 要将string input里找frequency由高至低 print 出每个word **map，然后反向再建map**
- 一個機器人在infinite的grid上，可以往上下左右走， 從（0，0）開始，給你一list的command，記錄在每個點經過多少次。 **模拟，然后map记录**
- 一个先递增后递减的数组[1,2,3,4,5,4,3], 查找一个数，返回true和false，问了边界怎么处理，有负数怎么办，有重复的数字怎么办。**做3次log(n)的binary search, 第一次找中点，然后以中点为分界线在两边找。**

- find longest reapted substring **https://www.geeksforgeeks.org/suffix-tree-application-3-longest-repeated-substring/**
- 还有给与一个数组， 输出出现次数为奇数的数字 **map**

* lc703 Kth Largest Element in a Stream 给定一个K， 有一个 Input Stream, 每次收入一个 Int，当输入的数字 >= K 个时，输出第 K 大数字 **heap**

- 找岛屿数量 **union find**

  1. followup1: replace all the islands with their size.
  2. followup2: 如果有人来买岛，给出某个range size的选项。如何优化。

- recursive的方式求一个数的factorial **写递归**

- 给个sorted的string array，问我怎么找到某个string **Binary Search**

- lc69 Sqrt(x) **binary search，left = 0, right = x， m*m <= x && x < (m+1)\*(m+1)**

- lc56 Merge Intervals **end点从小到大排序，merge，注意要一直merge直到无法merge**

  ```C++
  /**
   * Definition for an interval.
   * struct Interval {
   *     int start;
   *     int end;
   *     Interval() : start(0), end(0) {}
   *     Interval(int s, int e) : start(s), end(e) {}
   * };
   */
  class Solution {
  public:
      vector<Interval> merge(vector<Interval>& intervals) {
          auto f = [](Interval &a, Interval &b){
              return a.end < b.end;
          };
          sort(intervals.begin(), intervals.end(), f);
          vector<Interval> ans;
          for(auto p: intervals){
              if(ans.size() == 0 || ans.back().end < p.start){
                  ans.push_back(p);
              }
              else{
                  while(ans.size() > 0 && ans.back().end >= p.start){
                      auto last = ans.back();
                      ans.pop_back();
                      p.start = min(p.start, last.start);
                  }
                  ans.push_back(p);
              }
          }
          return ans;
      }
  };
  ```

  

- coin change 最少多少个coin，有多少种方法，**要是coin数量有限怎么办???**

  ```C++
  class Solution { // minimize coins
  public:
      int coinChange(vector<int>& coins, int amount) {
          vector<int> dp(amount+1, INT_MAX-1); dp[0] = 0;
          for(int i = 1; i <= amount; i++) for(auto c: coins) if(i-c >= 0) dp[i] = min(dp[i], dp[i-c]+1);
          return (dp[amount] == INT_MAX-1)? -1: dp[amount];
      }
  };
  
  class Solution { // how many ways
  public:
      int change(int amount, vector<int>& coins) {
          vector<int> dp(amount+1, 0); dp[0] = 1;
          for(auto c: coins) for(int i = c; i <= amount; i++) dp[i] += dp[i-c];
          return dp[amount];
      }
  };
  ```

  

- 给一个sentence 分别print出每一个单词, 列出所有corner case/如果单词里有typo怎么办 用什么数据结构识别/ 如果有标点符号怎么办 **istringstream**

  ```C++
  std::replace(paragraph.begin(), paragraph.end(), ';', ' ');
  transform(paragraph.begin(), paragraph.end(), paragraph.begin(), ::tolower);
  ```

- 括号匹配 **只有小括号的话，counter；不止小括号的话，用栈**

- implement min && max heap

  ```C++
  
  ```

- implemtn hashmap

  ```C++
  
  ```

- 给一个table，三列分别为customerID，productID 和 timeStamp。找出most common 3 consecutive product seqeuence. 意思是每个customer根据timestamp有一个visit product的sequence，然后找所有customer sequence 里出现最多次的长度为3的连续串。follow-up问了一下这题的情况如果不用hash function 怎么。**没看懂啥意思**

- Word Break II 给一个string，一个关键词列表dict，返回一个可能的分割方法。如果没有可能的分割方法就返回比如空串之类的。比如"thisskyisblue" -> "this sky is blue"

  ```C++
  // TLE
  class Solution {
  public:
      vector<string> wordBreak(string s, vector<string>& wordDict) {
          vector<string> ans;
          set<string> dict(wordDict.begin(), wordDict.end());
          backtracking(s, dict, ans, "");
          return ans;
      }
      
  private:
      void backtracking(string s, set<string> dict, vector<string> &ans, string cur){
          if(s == ""){
              ans.push_back(cur.substr(1));
              return;
          }
          for(int i = 1; i <= s.size(); i++){
              if(dict.find(s.substr(0, i)) != dict.end())
                  backtracking(s.substr(i), dict, ans, cur+" "+s.substr(0, i));
          }
      }
  };
  
  class Solution {
  public:
      vector<string> wordBreak(string s, vector<string>& wordDict) {
          vector<string> ans;
          set<string> dict(wordDict.begin(), wordDict.end());
          if(m.count(s)) return m[s];
          if(dict.count(s)){ //a whole string is a word
              ans.push_back(s);
          }
          for(int i=1;i<s.size();++i){
              string word=s.substr(i);
              if(dict.count(word)){
                  string rem=s.substr(0,i);
                  vector<string> prev=combine(word,wordBreak(rem,wordDict));
                  ans.insert(ans.end(),prev.begin(), prev.end());
              }
          }
          m[s]=ans; //memorize
          return ans;
      }
      
  private:
      map<string, vector<string>> m;
      vector<string> combine(string word, vector<string> prev){
          for(auto &p: prev) p += " "+word;
          return prev;
      }
  };
  ```

- 机器人只能往坐下,正下,右下方移动. 问这个grid是不是有效的, 机器人需要从第一层一直move到最后一层.
  for example: 
  0 1 0 0 1 1 0
  0 0 1 1 0 1 0
  0 1 0 0 1 1 0  
  这个就是valid的grid
  0 1 0 0 1 1 0
  1 0 1 0 0 1 0
  0 1 0 0 1 1 0  

  这个就不是valid的grid. **没看懂**

- lc05 5. Longest Palindromic Substring **dp**  follow up：有两个同样长的回文如何输出第一个 **多写句if**

- lc268 Missing Number **xor**  follow up sorted array **二分**

- lc973 K Closest Points to Origin **sort / pq**

- 问string a能否通过rearrange变成string b **map / vector**

- 机场乘客登机顺序 有头等舱经济舱等 怎么保证舱位优先的先登机 舱位相同的先来的先登记 设计一个数据结构并分析时间复杂度等 **map<int, vector\<int\>>**

- lc 1 Two Sum **unordered_map** time complexity: O(n)

  稍微变化的2-sum，把所有的和为n的pair找出来，但每个元素只能用一次，{1,1,1,2,7,9,9,9}, n=10, 就返回{(1,9),(1,9),(1,9)},每个1用一次，9用一次不需要考虑permutation，直接双指针。。。最开始还理解错题了以为一个pair只能一次 **map扫一遍，然后找pair，取俩数出现次数的min**

- 一个数组里，找出连续子数组的最大的和。 **dp with one var**

- 自己设计一个队列数据结构, 实现add和poll：
  class Queue {
      class node{
             int val;
             node next;
             node(int val){ this.val = val;}
       }
       node head;
       node tail;
       public void add(int data){  .....  };
       public void poll(){.......};
  }
  大概这样，复杂度全是O(1);

  ```C++
  
  ```

- merge two sorted arrays. **Just do it**

- lc230 Kth Smallest Element in a BST followup再写了用stack的版本

  ```C++
  class Solution {
  public:
      int kthSmallest(TreeNode* root, int k) {
          int ans = 0;
          int counter = 0;
          dfs(root, counter, k, ans);
          return ans;
      }
      
  private:
      void dfs(TreeNode *root, int &counter, int k, int &ans){
          if(root == nullptr || counter > k) return;
          dfs(root->left, counter, k, ans);
          counter++;
          if(counter == k) ans = root->val;
          dfs(root->right, counter, k, ans);
      }
  };
  
  class Solution {
  public:
      int kthSmallest(TreeNode* root, int k) {
          stack<TreeNode *> stk;
          TreeNode *node = root;
          while(node){
              stk.push(node);
              node = node->left;
          }
          while(--k){
              auto node = stk.top()->right;
              stk.pop();
              while(node){
                  stk.push(node);
                  node = node->left;
              }
          }
          return stk.top()->val;
      }
  };
  ```

- lc295 Find Median from Data Stream

  ```C++
  class MedianFinder {
  public:
      /** initialize your data structure here. */
      MedianFinder() {
          
      }
      
      void addNum(int num) {
          if(maxHeap.empty()) maxHeap.push(num);
          else if(minHeap.empty()){
              if(num > maxHeap.top()){
                  int top = maxHeap.top(); maxHeap.pop();
                  maxHeap.push(num);
                  minHeap.push(top);
              }
              else minHeap.push(num);
          }
          else{
              if((maxHeap.size() + minHeap.size()) % 2 == 1){ // max_size = min_size + 1
                  if(num <= maxHeap.top()) minHeap.push(num);
                  else{
                      int top = maxHeap.top(); maxHeap.pop();
                      minHeap.push(top);
                      maxHeap.push(num);
                  }
              }
              else{
                  if(num >= minHeap.top()) maxHeap.push(num);
                  else{
                      int top = minHeap.top(); minHeap.pop();
                      minHeap.push(num);
                      maxHeap.push(top);
                  }
              }
          }
      }
      
      double findMedian() {
          if((maxHeap.size() + minHeap.size()) % 2 == 1) return (double)maxHeap.top();
          else return ((double)maxHeap.top() + (double)minHeap.top()) / 2.0;
      }
      
  private:
      priority_queue<int, vector<int>, greater<int>> maxHeap;
      priority_queue<int, vector<int>, less<int>> minHeap;
      
      
  };
  ```

- lc387 First Unique Character in a String **map**

- 公司有员工，让设计系统，实现api hire和terminate **map or tree，根据部门建树**

  面我的是美国老哥，上来问了我4道bq，之后做题。题目就给了我一张公司内部人员架构图，一个公司有很多部门，每个部门有一个主管和一堆员工。然后oodesign，设计对应的类，之后再选择数据结构表述公司架构，最后给我任意一个员工，找到从这个员工开始，到他能管理到的最底层员工的深度。
  可能是我的oodeign有问题，面试官看我最后写完一直说我的时间复杂度太高，不应该根据员工构建树，而应该根据部门。最后还是挂了，后来问问题，发现他是tech leader。哭泣。感觉自己跪在了oodesign上。

- 如下：假设有N个连续的灯泡，序号为1-N，每次点亮其中一个，如果这个灯泡之前（就是序号比它小）的所有灯泡都已经点亮，那么这个灯泡就会顺便闪一下。
  现在给出点亮灯泡的顺序，问中间闪了几次。（可怜我听他口述题目好久才搞懂on和shine不同）
  举个栗子：灯泡5个，输入为点亮顺序[5, 1, 3, 2, 4]
  第一次点亮5，之前1，2，3，4都不亮，不闪烁；
  第二次点亮1，之前没灯，闪烁
  第三次点亮3，之前灯2没被点亮，不闪烁
  第四次点亮2，之前灯全被点亮，闪烁，
  第五次点亮4，之前灯都被点亮，闪烁
  答案：3

  这题最优解应该是时间复杂度**O(n)**，空间复杂度**O(1)**

  推荐 yrccheer的方法：从后往前维护最小值，解释见下面帖子。
  lz方法：记录从0开始的连续点亮的长度k，用原来数组的正负记录是否点亮；如果当前值等于k，那么result+1并且更新k直到下一个没被点亮的灯。

- 删除链表倒数第N个结点 **双指针**

- 求链表倒数第K个node **双指针**

- The first non-repeat character, 例如：Input: "wwddeacc" Output: "e" **map - 2 pass**

- 设计hashmap和trie 完成insert search delete操作
  trie要多加一个startwith的function

  ```C++
  
  ```

- lc252 Meeting Rooms **线扫描** followup：是如果是有两间会议室如何去modify your code(lc253) **counter判断改一下**

- lc146 LRU Cache

  ```C++
  class LRUCache {
  public:
      LRUCache(int capacity) {
          this->capacity = capacity;
      }
      
      int get(int key) {
          if(k2v.find(key) == k2v.end()) return -1;
          keypos.erase(k2p[key]);
          keypos.push_front(key);
          k2p[key] = keypos.begin();
          return k2v[key];
      }
      
      void put(int key, int value) {
          if(k2v.size() == capacity && k2v.find(key) == k2v.end()){
              k2p.erase(keypos.back());
              k2v.erase(keypos.back());
              keypos.pop_back();
          }
          else if(k2v.find(key) != k2v.end()){
              keypos.erase(k2p[key]);
          }
          keypos.push_front(key);
          k2p[key] = keypos.begin();
          k2v[key] = value;
      }
      
  private:
      unordered_map<int, int> k2v;
      unordered_map<int, list<int>::iterator> k2p;
      list<int> keypos;
      int capacity;
  };
  
  /**
   * Your LRUCache object will be instantiated and called as such:
   * LRUCache obj = new LRUCache(capacity);
   * int param_1 = obj.get(key);
   * obj.put(key,value);
   */
  ```

- 象棋中骑士从a点到b点到最短距离 **BFS**

- 按照空格给字符串分词，每个单词计数 **map**

- 判断一个字符串是不是另外两个字符串的乱序组合 比如 X = "ABCD"; Y = "ACDBE"; Z = "AABCDCBDE"; Z是XY的顺序组合，所以是false。**用一个两个指针i,j分别指向XY的当前字符下标，然后遍历Z的字符， X能匹配就i++ 然后 continue； Y 能匹配就j++ 然后continue， 如果最后都能匹配返回false，有一个不能就返回true。**(有bug) **我感觉要写递归**

- build structure for employee and supervisor relationship
  there is only one employee who does not have supervisors **没看懂**

- 求图距离小于等于K的节点 **直接算吧**

- 一个数组， 输出出现次数为基数的数字 **map**

- 题述是假设有一个University Campus，里面有很多router、wifi，但是也有很多smart phones macbooks等devices。想办法描述这个网络，并且可以实现检测两个device的连通性 **g union-find**

- 给一堆未排序好的顾客购买记录(cistomID, itemID, timeStamp(购买时间))，然后要求出现次数最多的，连续3次购买的物品(需要是同一个顾客)。举个例子，(1, A, 0), (1, B, 2), (1, C, 4), (1,D, 5), (2, A, 0), (2, B, 2), (2, C, 4). 那么A-B-C出现过两次，B-C-D出现过一次。**按照custom id，time排序，然后以3为window size，用map存出现次数**

- 给个字符串，让你返回一个字符串只包含unique的char **map**

- lc50 Pow(x, n)

  ```C++
  class Solution {
  public:
      double myPow(double x, int n) {
          if(n == 0) return 1.0;
          if(x == 0.0) return 0.0;
          bool sign = n > 0? true: false;
          long p = labs((long)n);
          return sign? binaryPow(x, p): 1 / binaryPow(x, p);
      }
      
  private:
      double binaryPow(double x, long n){
          if(n == 0) return 1.0;
          if(n % 2 == 1){
              double half = binaryPow(x, n/2);
              return half * half * x;
          }
          else{
              double half = binaryPow(x, n/2);
              return half*half;
          }
      }
  };
  ```

- lc210 Course Schedule II  time & space complexity follow up: 如果要回传所有可能答案? time & space complexity? **拓扑排序**

  ```C++
  class Solution {
  public:
      vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
          vector<int> ans;
          vector<int> indegree(numCourses, 0);
          unordered_map<int, unordered_set<int>> node2nexts;
          for(auto p: prerequisites){
              indegree[p.first]++;
              node2nexts[p.second].insert(p.first);
          }
          vector<bool> visited(numCourses, false);
          queue<int> q;
          for(int i = 0; i < indegree.size(); i++) if(indegree[i] == 0) q.push(i);
          while(q.empty() == false){
              int node = q.front(); q.pop();
              visited[node] = true;
              ans.push_back(node);
              for(auto next: node2nexts[node]){
                  indegree[next]--;
                  if(indegree[next] == 0) q.push(next);
              }
          }
          return ans.size() == numCourses? ans: vector<int>{};
      }
  };
  ```

- lc45Jump Game II  求到达对岸最少跳跃次数 没有负数，必定有解

  ```C++
  class Solution {
  public:
      int jump(vector<int>& nums) {
          if(nums.size() <= 1) return 0;
          vector<int> dp(nums.size(), -1);
          dp[0] = 0;
          for(int i = 0; i < nums.size(); i++) if(dp[i] != -1){
              for(int len = 1; len <= nums[i] && i+len < nums.size(); len++){
                  if(dp[i+len] == -1) dp[i+len] = dp[i]+1;
                  else dp[i+len] = min(dp[i+len], dp[i]+1);
              }
          }
          return dp.back();
      }
  };
  ```

- 双栈排序 只能用栈给一个无序的栈排序

  ```C++
  stack<int> sortStack(stack<int> &input) 
  { 
      stack<int> tmpStack; 
    
      while (!input.empty()) 
      { 
          // pop out the first element 
          int tmp = input.top(); 
          input.pop(); 
    
          // while temporary stack is not empty and top 
          // of stack is greater than temp 
          while (!tmpStack.empty() && tmpStack.top() > tmp) 
          { 
              // pop from temporary stack and push 
              // it to the input stack 
              input.push(tmpStack.top()); 
              tmpStack.pop(); 
          } 
    
          // push temp in tempory of stack 
          tmpStack.push(tmp); 
      } 
    
      return tmpStack; 
  } 
  ```

- lc 121Best Time to Buy and Sell Stock 加上返回哪天买进和卖出 即index

  ```C++
  class Solution {
  public:
      int maxProfit(vector<int>& prices) {
          if(prices.size() <= 1) return 0;
          int ans = 0;
          int minval = prices.front();
          for(int i = 1; i < prices.size(); i++){
              if(prices[i] < minval) minval = prices[i];
              else ans = max(ans, prices[i]-minval);
          }
          return ans;
      }
  };
  ```

- lc21 Merge Two Sorted Lists **Just do it**

- lc 978 Longest Turbulent Subarray  然后再问了下把array改成linkedlist，我就直接循环做了

  A subarray `A[i], A[i+1], ..., A[j]` of `A` is said to be *turbulent* if and only if:

  - For `i <= k < j`, `A[k] > A[k+1]` when `k` is odd, and `A[k] < A[k+1]` when `k` is even;
  - **OR**, for `i <= k < j`, `A[k] > A[k+1]` when `k` is even, and `A[k] < A[k+1]` when `k` is odd.

  That is, the subarray is turbulent if the comparison sign flips between each adjacent pair of elements in the subarray.

  Return the **length** of a maximum size turbulent subarray of A.

  ```C++
  class Solution {
  public:
      int maxTurbulenceSize(vector<int>& A) {
          if(A.size() <= 1) return A.size();
          int ans = 1;
          vector<int> up(A.size(), 1);
          vector<int> down(A.size(), 1);
          for(int i = 1; i < A.size(); i++){
              if(A[i-1] < A[i]) up[i] = down[i-1]+1, ans = max(ans, up[i]);
              if(A[i-1] > A[i]) down[i] = up[i-1]+1, ans = max(ans, down[i]);
          }
          return ans;
      }
  };
  ```

- lc621 Task Scheduler

  ```C++
  class Solution {
  public:
      int leastInterval(vector<char>& tasks, int n) {
          int ans = 0;
          vector<int> stat(26, 0);
          for(auto t: tasks) stat[t-'A']++;
          auto f = [](int a, int b){return a > b;};
          sort(stat.begin(), stat.end(), f);
          while(stat.front() > 0){
              for(int i = 0; i <= n && stat.front() != 0; i++, ans++) 
                  if(i < 26 && stat[i] > 0) 
                      stat[i]--; 
              sort(stat.begin(), stat.end(), f);
          }
          return ans;
      }
  };
  ```

- lc08 String to Integer (atoi)

  ```C++
  class Solution {
  public:
      int myAtoi(string str) {
          int sign = 1, base = 0, i = 0;
          while (str[i] == ' ') { i++; }
          if (str[i] == '-' || str[i] == '+') {
              sign = 1 - 2 * (str[i++] == '-'); 
          }
          while (str[i] >= '0' && str[i] <= '9') {
              if (base >  INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7)) {
                  if (sign == 1) return INT_MAX;
                  else return INT_MIN;
              }
              base  = 10 * base + (str[i++] - '0');
          }
          return base * sign;
      }
  };
  ```

- lc234 Palindrome Linked List

  ```C++
  /**
   * Definition for singly-linked list.
   * struct ListNode {
   *     int val;
   *     ListNode *next;
   *     ListNode(int x) : val(x), next(NULL) {}
   * };
   */
  class Solution {
  public:
      bool isPalindrome(ListNode* head) {
          ListNode* slow = head;
          ListNode* fast = head;
          int counter = 0;
          while (fast != NULL && fast->next != NULL) {
              slow = slow->next;
              fast = fast->next->next;
              counter += 2;
          }
          if(fast) counter++;
          if(counter % 2) slow = slow->next;
          slow = reverseList(slow);
          
          while(slow){
              if(head->val != slow->val) return false;
              slow = slow->next;
              head = head->next;
          }
          return true;
      }
      
  private:
      ListNode *reverseList(ListNode * head){
          ListNode *dummy = new ListNode(-1);
          while(head){
              ListNode *old = dummy->next;
              dummy->next = head;
              head = head->next;
              dummy->next->next = old;
          }
          return dummy->next;
      }
  };
  ```

- lc445 Add Two Numbers II   Follow up：怎么利用这个加法的function来做乘法，在他的引导下，基本也把思路秒了，不用写出来。

  ```C++
  /**
   * Definition for singly-linked list.
   * struct ListNode {
   *     int val;
   *     ListNode *next;
   *     ListNode(int x) : val(x), next(NULL) {}
   * };
   */
  class Solution {
  public:
      ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
          stack<ListNode *> num1;
          stack<ListNode *> num2;
          ListNode *cur = l1;
          while(cur){
              num1.push(cur);
              cur = cur->next;
          }
          cur = l2;
          while(cur){
              num2.push(cur);
              cur = cur->next;
          }
          ListNode *head = nullptr;
          int carry = 0;
          int sum = 0;
          while(num1.empty() == false || num2.empty() == false){
              int a = num1.empty()? 0: num1.top()->val;
              if(num1.empty() == false) num1.pop();
              int b = num2.empty()? 0: num2.top()->val;
              if(num2.empty() == false) num2.pop();
              sum = (a + b + carry) % 10;
              carry = (a + b + carry) / 10;
              cur = new ListNode(sum);
              cur->next = head;
              head = cur;
          }
          if(carry == 1){
              cur = new ListNode(1);
              cur->next = head;
              head = cur;
          }
          return head;
      }
  };
  ```

- 





Given an array of integers, and every integer represents column height.Find maximum amount of water of these columns can trap if we can remove two of columns of them. 

1.给一个string，可能是一个单词，可能是一段话， 要求返回最长的重复的substring。例如：
Input："I like apple, I like banana." Output: "I like"
Input: "banana" Output: "ana"

给一个正整数，问最少多少步可以到1（奇数可选择加一或者减一，偶数只能选择除以二）







### Data Struct && Tech

* Whta is priority_queue，怎么实现的，手写heap代码
* Hashmap原理、时空复杂度，最差复杂度 有Collision怎么解决  hashset hashmap的区别 
* BST与二叉树  BST查找复杂度、什么时候用BST什么时候用hashtable；
* array, arraylist, linked list 分别是什么, random access 的 time complexity
* vector有哪些interface还有vector和array对内存的分配
* 要在一台内存较小的移动设备上存储大量数据 究竟是应该用数组还是链表 我当时直接懵了 后来胡乱答了一通 说用链表 不然的话本来内存就很小 用数组得连续分配内存 容易external fragmentation 面试官说cool 但是给我的感觉是我没有答出他想要的答案但是讲的很有道理的样子（事后经过同学提醒应该是用数组 链表得多存一个指针）
* Abstract Class是什么，和普通的class比有什么区别
* 什么是Polymorphism
* Greedy vs DP
* java和javascript有什么区别，回答了java多线程， js单线程；java编译语言，js脚本语言等等诸如此类
* overriding + overloading
* 什么是 graph, tree, binary tree, binary search tree 用什么 data structure 存 graph
* 给一个情景，说一个family围坐在一个圆桌上，然后用什么数据结构设计，并且当 new family想加入时，该怎么操作（method）。什么额外条件都没有，随你自己说和写。





### Sefl-Intro

* 需要很快时间学习一个新知识来完成的项目
* 要compromise小細節來趕上的deadline（tradeoff）deadline 过后有没有做什么 improvement，怎么做
* 先解释项目，项目怎么展开的遇到了哪些困难技术trade off
* 自我介绍
* 举一个例子，当你的peer在学业或者工作上陷入困难时，你是怎么做帮助他的，最后结果如何?
* 以往有限时间内必须拿出结果的经历，为什么选了某个特定的技术，有没有什么规划好却没有实现的功能
* 最自豪的经历
* 你没有在deadline之前完成任务的经历
* 讲一个你帮同事分担任务的经历
* a situation or tast you have to dive in
* a situation you have to take a risk.
* 一个是项目中犯过的错误，what’s the biggest mistake/failure you’ve made?
* 另一个是如果项目进度很慢怎么办
* 过了下简历，如何lead课程项目的
* ddl处理，完不成怎么办
* 实习中需要gather information and make a decision的例子，遇到新问题且无法搜集相关资料怎么办
* 讲一个被困难stuck住的经历
* 描述一件你曾经失败的事情  一个没有克服的困难  讲一件没有达成自己目标的事情
* how to communicate with the teammate, if u guys have some disagreements.
* how to choose between different technical stack? 
* 之前经历过项目中最有挑战性 or most interesting的project
* 因为时间不够而放弃的项目里的本应实现的feature
* 讲述一次放弃的经历
* 受到强烈质疑该怎么办
* courses in this semester and plan courses next semester;  当前的学习目标
* why Amazon
* How to work with limited time or resource?
* 有没有为了project深入理解package运作的经验
* 违背过的承诺
* 你以前实习的manager有没有对你失望过？
* 你事先没有发现问题的例子
* 有没有学习新东西的经历？有没有没能完成的目标？

* 有没有做过stand out的project
* 自己做决定的经历
* 帮助struggle队友的经历
* talk about project你想做而不是出于学业／工作压力做的？
* Describe a situation in which you took extra responsibility for a task that does not belong to you..
* Tell me about a time when you had difficulty working with someone on a side or class project?
  What did you do to overcome this?

















