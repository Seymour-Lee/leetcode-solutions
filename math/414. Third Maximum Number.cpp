class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long first = LONG_MIN, second = LONG_MIN, third = LONG_MIN;
        for(auto num: nums){
            if(num > first) third = second, second = first, first = num;
            else if(num < first && num > second) third = second, second = num;
            else if(num < second && num > third) third = num;
        }
        if(third == LONG_MIN) return first;
        return third;
    }
};

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long one = long(INT_MIN)-1, two = long(INT_MIN)-1, three = long(INT_MIN)-1;
        for(auto a: nums){
            long num = (long)a;
            if(num > one){
                three = two;
                two = one;
                one = num;
            }
            else if(num > two && num != one){
                three = two;
                two = num;
            }
            else if(num > three && num != two && num != one){
                three = num;
            }
        }
        // cout<<one<<" "<<two<<" "<<three<<endl;
        if(three == long(INT_MIN)-1) return one;
        return three;
    }
};