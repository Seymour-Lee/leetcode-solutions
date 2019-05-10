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