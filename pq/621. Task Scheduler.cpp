class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int result = 0;
        vector<int> vec(26, 0);
        for(auto task: tasks) vec[task - 'A']++;
        sort(vec.begin(), vec.end());
        while(vec.back() > 0){
            int i = 0;
            while(i <= n){
                if(vec.back() == 0) break;
                if(i < 26 && vec[25 - i] > 0) vec[25 - i]--;
                result++;
                i++;
            }
            sort(vec.begin(), vec.end());
        }
        return result;
    }
};

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int ans = 0;
        vector<int> stat(26, 0);
        for(auto t: tasks) stat[t-'A']++;
        auto f = [](int a, int b){return a > b;}; // can not be >=, which will raise runtime error
        sort(stat.begin(), stat.end(), f);
        while(stat.front() > 0){
            for(int i = 0; i <= n && stat.front() != 0; i++, ans++) 
                if(i < 26 && stat[i] > 0) 
                    stat[i]--; 
            sort(stat.begin(), stat.end(), f);
        }
        return ans;
    }
};

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int ans = 0;
        vector<int> counter(26, 0);
        for(auto t: tasks) counter[t-'A']++;
        sort(counter.rbegin(), counter.rend());
        while(counter.front() > 0){
            for(int i = 0; i <= n && counter.front() > 0; i++, ans++){
                if(i < 26 && counter[i] > 0) counter[i]--;
            }
            sort(counter.rbegin(), counter.rend());
        }
        return ans;
    }
};