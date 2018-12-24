void operator+=(vector<int> &a, const vector<int> &b) {
    for (int i = 0; i < a.size(); i++)
        a[i] += b[i];
}

void operator-=(vector<int> &a, const vector<int> &b) {
    for (int i = 0; i < a.size(); i++)
        a[i] -= b[i];
}

bool operator<(const vector<int> &a, const int &n) {
    for (int i : a)
        if (i < n)
            return true;
    return false;
}

int operator*(const vector<int> &a, const vector<int> &b) {
    int res = 0;
    for (int i = 0; i < a.size(); i++)
        res += a[i] * b[i];
    return res;
}

class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, int cost = 0) {
        if(needs < 0) return INT_MAX;
        int result = cost + needs * price;
        for(auto &offer: special){
            if(cost + offer.back() >= result) continue;
            needs -= offer;
            result = min(result, shoppingOffers(price, special, needs, cost+offer.back()));
            needs += offer;
        }
        return result;
    }
};

class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return dp(price, special, needs, 0);
    }
    
private:
    unordered_map<string, int> memo;
    
    int dp(vector<int>& p, vector<vector<int>>& sp, vector<int>& n, int cur){
        if(*min_element(n.begin(), n.end()) < 0) return INT_MAX;
        string vstr = vec2str(n);
        if(memo.find(vstr) != memo.end()) return memo[vstr];
        memo[vstr] = cur + multi(n, p);
        for(auto o: sp){
            if(cur+o.back() >= memo[vstr]) continue;
            minus(n, o);
            memo[vstr] = min(memo[vstr], dp(p, sp, n, cur+o.back()));
            add(n, o);
        }
        return memo[vstr];
    }
    
    void add(vector<int> &a, vector<int> &b){
        for(int i = 0; i < a.size(); i++) a[i] += b[i];
    }
    
    void minus(vector<int> &a, vector<int> &b){
        for(int i = 0; i < a.size(); i++) a[i] -= b[i];
    }
    
    int multi(vector<int> &a, vector<int> &b){
        int ans = 0;
        for(int i = 0; i < a.size(); i++) ans += a[i]*b[i];
        return ans;
    }
    
    string vec2str(vector<int> &vec){
        if(vec.size() == 0) return "";
        if(vec.size() == 1) return to_string(vec[0]);
        string ans = to_string(vec[0]);
        for(int i = 1; i < vec.size(); i++) ans += " "+to_string(vec[i]);
        return ans;
    }
};