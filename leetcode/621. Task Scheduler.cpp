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