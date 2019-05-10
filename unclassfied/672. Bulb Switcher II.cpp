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