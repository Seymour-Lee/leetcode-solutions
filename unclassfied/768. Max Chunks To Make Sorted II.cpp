class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans = 0;
        multiset<int> cur;
        multiset<int> exp;
        vector<int> a = arr;
        sort(a.begin(), a.end());
        for(int i = 0; i < a.size(); i++){
            exp.insert(a[i]);
            cur.insert(arr[i]);
            if(cur == exp) ans++; 
        }
        return ans;
    }
};

