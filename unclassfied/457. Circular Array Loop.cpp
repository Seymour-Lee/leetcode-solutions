class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        map<int, int> pos2next;
        int size = nums.size();
        vector<bool> visited(size, false);
        for(int i = 0; i < size; i++){
            if(visited[i]) continue;
            int pos = i;
            while(true){
                visited[pos] = true;
                int next = (pos + nums[pos]) % size;
                if(next < 0) next += size;
                if(next == pos || nums[next] * nums[pos] < 0) break;
                if(pos2next.count(next)) return true;
                pos2next[pos] = next;
                pos = next;
            }
        }
        return  false;
    }
};