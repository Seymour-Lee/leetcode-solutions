class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int result = 0;
        int largest = 0;
        for(int i = 0; i < arr.size(); i++){
            largest = max(arr[i], largest);
            if(largest == i) result++;
        }
        return result;
    }
};