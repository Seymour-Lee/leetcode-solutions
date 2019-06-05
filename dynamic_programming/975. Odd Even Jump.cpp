class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        int n  = A.size(), res = 1;
        vector<int> higher(n), lower(n);
        higher[n - 1] = lower[n - 1] = 1;
        map<int, int> map;
        map[A[n - 1]] = n - 1;
        for (int i = n - 2; i >= 0; --i) {
            auto hi = map.lower_bound(A[i]), lo = map.upper_bound(A[i]);
            if (hi != map.end()) higher[i] = lower[hi->second];
            if (lo != map.begin()) lower[i] = higher[(--lo)->second];
            if (higher[i]) res++;
            map[A[i]] = i;
        }
        return res;
    }
};

class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        int ans = 1;
        vector<bool> odd(A.size(), false);
        vector<bool> eve(A.size(), false);
        map<int, int> n2i;
        odd.back() = true, eve.back() = true, n2i[A.back()] = A.size()-1;
        for(int i = A.size()-2; i >= 0; i--){
            // odd
            auto lower = n2i.lower_bound(A[i]);
            // upper
            auto upper = n2i.upper_bound(A[i]);
            // if i-th is odd-jump
            if(lower != n2i.end()) odd[i] = eve[lower->second];
            if(upper != n2i.begin()) eve[i] = odd[prev(upper)->second];
            if(odd[i]) ans++;
            n2i[A[i]] = i;
        }
        return ans;
    }
};