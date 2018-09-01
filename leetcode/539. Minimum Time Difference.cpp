class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<pair<int, int>> times;
        for(auto p: timePoints) {
            times.push_back(pair<int, int>{stoi(p.substr(0, 2)), 
                                           stoi(p.substr(3))});
        }
        auto cmp = [](pair<int, int> a, pair<int, int> b){
            return a.first == b.first? a.second < b.second: a.first < b.first;
        };
        sort(times.begin(), times.end(), cmp);
        times.push_back(pair<int, int>{times.front().first+24, 
                                       times.front().second});
        int result = INT_MAX;
        for(decltype(times.size()) i = 0; i != times.size()-1; i++){
            int diff = times[i+1].second - times[i].second;
            diff += (times[i+1].first - times[i].first) * 60;
            result = min(diff, result);
        }
        return result;
    }
};