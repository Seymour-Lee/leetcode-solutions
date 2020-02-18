class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int ans = 0;
        int n = row.size();
        vector<int> ptn(n, 0);
        vector<int> pos(n, 0);
        for(int i = 0; i < n; i++){
            ptn[i] = (i%2 == 0? i+1: i-1);
            pos[row[i]] = i;
        }
        for(int i = 0; i < n; i++){
            for(int j = ptn[pos[ptn[row[i]]]]; i != j; j = ptn[pos[ptn[row[i]]]]){
                swap(row[i], row[j]);
                swap(pos[row[i]], pos[row[j]]);
                ans++;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size()/2;
        count = n;
        p = vector<int>(n, -1);
        for(int i = 0; i < n; i++) u(row[2*i]/2, row[2*i+1]/2);
        return n-count;
    }
    
private:
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
};

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size()/2;
        count = n;
        p = vector<int>(n, -1);
        for(int i = 0; i < n; i++) u(row[2*i]/2, row[2*i+1]/2);
        return n-count;
    }
    
private:
    int count;
    vector<int> p;
    
    int f(int x){
        if(p[x] == -1) return x;
        return p[x] = f(p[x]);
    }
    
    void u(int x, int y){
        int xp = f(x);
        int yp = f(y);
        if(xp != yp) p[xp] = yp, count--;
    }
};