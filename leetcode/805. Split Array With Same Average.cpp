class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) {
        int n = A.size();
        int m = n / 2;
        int total = accumulate(A.begin(), A.end(), 0);
        bool possible = false;
        for(int i = 1; i <= m && possible == false; i++)
            if(total * i % n == 0) possible = true;
        if(possible == false) return false;
        
        vector<unordered_set<int>> sums(m+1);
        sums[0].insert(0);
        for(auto num: A){
            for(int i = m; i >= 1; i--){
                for(auto t: sums[i-1]){
                    sums[i].insert(t+num);
                }
            }
        }
        for(int i = 1; i <= m; i++)
            if(total*i%n == 0 && sums[i].find(total*i/n) != sums[i].end())
                return true;
        return false;
    }
};