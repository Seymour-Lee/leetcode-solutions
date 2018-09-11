class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int, priority_queue<int, vector<int>, greater<int>>> backs;
        int need_more = 0;
        for(auto num: nums){
            if(backs[num-1].empty() == false){
                int count = backs[num-1].top();
                backs[num-1].pop();
                backs[num].push(++count);
                if(count == 3)
                    need_more--;
            }
            else{
                backs[num].push(1);
                need_more++;
            }
        }
        return need_more == 0;
    }
};