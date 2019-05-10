class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        x.insert(x.begin(), 4, 0);
        int len = x.size();
        int i = 4;
        for(; i < len && x[i] > x[i-2]; i++);
        if(i == len) return false;
        if(x[i] >= x[i-2]-x[i-4]) x[i-1] = x[i-1] - x[i-3];
        for(i++; i < len && x[i] < x[i-2]; i++);
        return i != len;
    }
};