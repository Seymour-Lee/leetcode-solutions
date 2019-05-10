class Solution {
public:
    int numSimilarGroups(vector<string>& A) {
        unordered_set<string> nore(A.begin(), A.end());
        A = vector<string>(nore.begin(), nore.end());
        if(A.size() < 2) return A.size();        
        int count = 0;
        vector<int> p(A.size(), -1);
        auto s = [](const string a, const string b){
            int two = 2;
            for(int i = 0; i < a.size(); i++){
                if(a[i] != b[i]) two--;
                if(two < 0) return false;
            }
            return two == 0;
        };
        
        for(int i = 0; i < A.size(); i++) for(int j = i+1; j < A.size(); j++){
            if(s(A[i], A[j])) u(p, i, j, count);
        }
        
        return A.size()-count;
    }
    
private:
    int f(vector<int> &p, int x){
        if(p[x] == -1) return x;
        return f(p, p[x]);
    }
    
    void u(vector<int> &p, int x, int y, int &count){
        int xp = f(p, x);
        int yp = f(p, y);
        if(xp != yp) p[xp] = yp, count++;
    }
};