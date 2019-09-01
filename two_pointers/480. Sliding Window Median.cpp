class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        unordered_map<int, int> outofdate;
        priority_queue<int, vector<int>, less<int>> lo;
        priority_queue<int, vector<int>, greater<int>> hi;
        int i = 0;
        while(i < k) lo.push(nums[i++]);
        for(int j = 0; j < k/2; j++) {hi.push(lo.top()); lo.pop();}
        ans.push_back(k&1? lo.top(): ((double)lo.top()+(double)hi.top())/2.0);
        while(i < nums.size()){
            int out = nums[i-k];
            int in = nums[i++];
            int balance = (out <= lo.top()? -1: 1);
            outofdate[out]++;
            if(lo.empty() == false && in <= lo.top()){
                lo.push(in);
                balance++;
            }
            else{
                hi.push(in);
                balance--;
            }
            if(balance < 0){
                lo.push(hi.top());
                hi.pop();
                balance++;
            }
            if(balance > 0){
                hi.push(lo.top());
                lo.pop();
                balance--;
            }
            while(outofdate[lo.top()]) outofdate[lo.top()]--, lo.pop();
            while(hi.empty() == false && outofdate[hi.top()]) outofdate[hi.top()]--, hi.pop();
            ans.push_back(k&1? lo.top(): ((double)lo.top()+(double)hi.top())/2.0);
        }
        return ans;
    }
};

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        multiset<long long> win(nums.begin(), nums.begin()+k);
        auto itor = win.begin();
        advance(itor, k/2);
        if(k % 2 == 0) ans.push_back((*itor+*prev(itor))/2.0);
        else ans.push_back(*itor);
        // for(auto a: win) cout<<a<<" "; cout<<endl;
        for(int i = k; i < nums.size(); i++){
            win.erase(win.lower_bound(nums[i-k]));
            win.insert(nums[i]);
            // for(auto a: win) cout<<a<<" "; cout<<endl;
            auto itor = win.begin();
            advance(itor, k/2);
            if(k % 2 == 0) ans.push_back((*itor+*prev(itor))/2.0);
            else ans.push_back(*itor);
        }
        return ans;
    }
};