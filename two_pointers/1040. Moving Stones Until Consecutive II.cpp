class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& A) {
        sort(A.begin(), A.end());
        int i = 0, n = A.size(), low = n;
        int high = max(A[n - 1] - n + 2 - A[1], A[n - 2] - A[0] - n + 2);
        for (int j = 0; j < n; ++j) {
            while (A[j] - A[i] >= n) ++i;
            if (j - i + 1 == n - 1 && A[j] - A[i] == n - 2)
                low = min(low, 2);
            else
                low = min(low, n - (j - i + 1));
        }
        return {low, high};
    }
};

class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& A) {
        sort(A.begin(), A.end());
        int i = 0, n = A.size(), low = n;
        int high = max(A[n - 1] - n + 2 - A[1], A[n - 2] - A[0] - n + 2);
        for (int j = 0; j < n; ++j) {
            while (A[j] - A[i] >= n) ++i;
            if (j - i + 1 == n - 1 && A[j] - A[i] == n - 2)
                low = min(low, 2);
            else
                low = min(low, n - (j - i + 1));
        }
        return {low, high};
    }
};