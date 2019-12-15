class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int len = arr.size() / 4;
        for(int i = 0, j = 0+len; j < arr.size(); i++, j++) if(arr[i] == arr[j]) return arr[i];
        return -1;
    }
};