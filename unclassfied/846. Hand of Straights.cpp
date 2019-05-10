class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        map<int, int> num2freq;
        int counter = 0;
        for(auto num: hand) num2freq[num]++;
        while(num2freq.empty() == false){
            int mini = num2freq.begin()->first;
            for(int c = mini; c < mini + W; c++){
                if(num2freq.find(c) == num2freq.end()){
                    return false;
                }
                num2freq[c]--;
                if(num2freq[c] == 0){
                    num2freq.erase(c);
                }
            }
        }
        return true;
    }
};