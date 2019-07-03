class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int largest = INT_MIN;
        int smallest = INT_MAX;
        for(auto a: A){
            largest = max(largest, a);
            smallest = min(smallest, a);
        }
        return max(0, largest - smallest - 2 * K);
    }
};

class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int minval = *min_element(A.begin(), A.end());
        int maxval = *max_element(A.begin(), A.end());
        return max(0, maxval-minval-2*K);
    }
};

class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int maxval = *max_element(A.begin(), A.end());
        int minval = *min_element(A.begin(), A.end());
        return maxval-minval > 2*K? maxval-minval-2*K: 0;
    }
};