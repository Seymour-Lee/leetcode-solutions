class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
        int twenty = 0;
        for(int i = 0; i < bills.size(); i++){
            if(bills[i] == 5){
                five++;
            }
            else if(bills[i] == 10){
                if(five){
                    ten++;
                    five--;
                }
                else{
                    return false;
                }
            }
            else if(bills[i] == 20){
                if(five && ten){
                    five--;
                    ten--;
                    twenty++;
                }
                else if(five >= 3){
                    five = five - 3;
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> count(3, 0);
        for(auto b: bills){
            if(b == 5) count[0]++;
            if(b == 10){
                if(--count[0] < 0) return false;
                count[1]++;
            }
            if(b == 20){
                if(count[1]){
                    if((--count[1] < 0) ||  (--count[0] < 0)) return false;
                    count[2]++;
                }
                else{
                    count[0] -= 3;
                    if(count[0] < 0) return false;
                    count[2]++;
                }
            }
        }
        return true;
    }
};