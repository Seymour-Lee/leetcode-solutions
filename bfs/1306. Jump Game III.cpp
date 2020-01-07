class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<bool> v(arr.size(), false);
        queue<int> q;
        q.push(start);
        v[start] = true;
        while(q.empty() == false){
            int size = q.size();
            while(size--){
                int pos = q.front(); q.pop();
                if(arr[pos] == 0) return true;
                int lpos = pos-arr[pos];
                int rpos = pos+arr[pos];
                if(0 <= lpos && lpos < arr.size() && v[lpos] == false){
                    q.push(lpos);
                    v[lpos] = true;
                }
                if(0 <= rpos && rpos < arr.size() && v[rpos] == false){
                    q.push(rpos);
                    v[rpos] = true;
                }
            }
        }
        return false;
    }
};