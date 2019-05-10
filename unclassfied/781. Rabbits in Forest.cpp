class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int result = 0;
        if(answers.size() == 0) return result;
        map<int, int> ans2times;
        for(auto ans: answers) ans2times[ans]++;
        for(auto item: ans2times){
            if(item.first == 0) result += item.second;
            else if(item.first + 1 >= item.second) result += item.first+1;
            else{
                int colors = ceil((double)item.second / (item.first + 1));
                result += (item.first + 1) * colors;
            }
        }
        return result;
    }
};