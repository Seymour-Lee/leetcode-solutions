class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        if(people.size() == 0) return 0;
        sort(people.begin(), people.end());
        int result = 0;
        int i = 0;
        int j = people.size()-1;
        while(i <= j){
            if(people[i] + people[j] <= limit) i++;
            result++;
            j--;
        }
        return result;
    }
};