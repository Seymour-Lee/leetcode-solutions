class Solution {
public:
    int addDigits(int num) {
        while(num >= 10){
            int next = 0;
            while(num){
                next += num % 10;
                num = num / 10;
            }
            num = next;
        }
        return num;
    }
};

class Solution {
public:
    int addDigits(int num) {
        return num-9*((num-1)/9);
    }
};