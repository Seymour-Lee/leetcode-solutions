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