class Solution {
public:
    int flipLights(int n, int m) {
        n = n > 6? n % 6 + 6: n;
        set<int> s;
        int init = (1 << n) - 1;
        queue<int> q{{init}};
        for(int i = 0; i < m; i++){
            int qsize = q.size();
            s.clear();
            while(qsize--){
                int cur = q.front();
                q.pop();
                vector<int> next{all(cur, n), odd(cur, n), even(cur, n), three(cur, n)};
                for(auto num: next){
                    if(s.find(num) != s.end()) continue;
                    q.push(num);
                    s.insert(num);
                }
            }
        }
        return q.size();
    }
    
private:
    int all(int cur, int n){
        int f = (1 << n) -1;
        return cur ^ f;
    }
    
    int odd(int cur, int n){
        for(int i = 0; i < n; i += 2){
            cur = cur ^ (1 << i);
        }
        return cur;
    }
    
    int even(int cur, int n){
        for(int i = 1; i < n; i += 2){
            cur = cur ^ (1 << i);
        }
        return cur;
    }
    
    int three(int cur, int n){
        for(int i = 0; i < n; i += 3){
            cur = cur ^ (1 << i);
        }
        return cur;
    }
};

class Solution {
public:
    int flipLights(int n, int m) {
        // rule1: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
        // rule2: 2, 4, 6, 8, 10, 12, 14
        // rule3: 1, 3, 5, 7, 9, 11, 13
        // rule4: 1, 4, 7, 10, 13, 16, 19, 22, 25, 28, 31
        // => 1 always same as 7, 13, 19, 31, ... 12k+1, 12k+7
        //    4                10, 16, 22, 28, .. 12k+4, 12k+10
        // => 2 always same as 6, 8, 12, 14, .... 12k+4, 12k+8
        // => 3: 5, 7, 9, 11
        // 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12
        auto one = [](int a, int b){
            int c = (1<<a)-1;
            return c ^ b;
        };
        auto two = [](int a, int b){
            for(int i = 0; i < a; i += 2) b = b ^ (1<<i);
            return b;
        };
        auto three = [](int a, int b){
            for(int i = 1; i < a; i += 2) b = b ^ (1<<i);
            return b;
        };
        auto four = [](int a, int b){
            for(int i = 0; i < a; i += 3) b = b ^ (1<<i);
            return b;
        };
        n = n % 12;
        unordered_set<int> seen;
        queue<int> q;
        q.push((1<<n)-1);
        while(m--){
            int size = q.size();
            seen.clear();
            while(size--){
                auto a = q.front(); q.pop();
                vector<int> next = {one(n, a), two(n, a), three(n, a), four(n, a)};
                for(auto b: next) if(seen.find(b) == seen.end()){
                    seen.insert(b);
                    q.push(b);
                }
            }
        }
        return q.size();
    }
};