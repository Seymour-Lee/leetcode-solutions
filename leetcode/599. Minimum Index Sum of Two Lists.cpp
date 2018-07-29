class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> result;
        map<string, int> andy;
        for(int i = 0; i < list1.size(); i++) andy[list1[i]] = i;
        int minSum = INT_MAX;
        for(int i = 0; i < list2.size(); i++){
            if(andy.find(list2[i]) != andy.end()){
                if(minSum > andy[list2[i]]+i){
                    result.clear();
                    result.push_back(list2[i]);
                    minSum = andy[list2[i]]+i;
                }
                else if(minSum == andy[list2[i]]+i){
                    result.push_back(list2[i]);
                }
            }
        }
        return result;
    }
};