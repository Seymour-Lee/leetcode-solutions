class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<pair<int, int>> num2list;
        for(int i = 0; i < nums.size(); i++) for(auto num: nums[i])
            num2list.push_back({num, i});
        auto f = [](pair<int, int> a, pair<int, int> b){return a.first < b.first;};
        sort(num2list.begin(), num2list.end(), f);
        int i = 0, j = 0;
        unordered_map<int, int> list2freq;
        list2freq[num2list[0].second]++;
        vector<int> ans{num2list[0].first, num2list.back().first};
        while(i < num2list.size() && j < num2list.size()){
            while(list2freq.size() < n && j+1 < num2list.size()){
                j++;
                list2freq[num2list[j].second]++;
            }
            if(j == num2list.size() || list2freq.size() < n) break;
            int a = num2list[i].first, b = num2list[j].first;
            int c = ans[0], d = ans[1];
            if(b-a < d-c || (a < c && b-a == d-c)) ans = {a, b};
            while(list2freq.size() == n && i <= j){
                list2freq[num2list[i].second]--;
                if(list2freq[num2list[i].second] == 0) list2freq.erase(num2list[i].second);
                i++;
            }
            i--;
            a = num2list[i].first, b = num2list[j].first;
            c = ans[0], d = ans[1];
            if(b-a < d-c || (a < c && b-a == d-c)) ans = {a, b};
            i++;
        }
        return ans;
    }
};