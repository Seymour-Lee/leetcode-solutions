class Solution {
public:
    int findNthDigit(int n) {
        if(n < 10) return n;
        long counter = 9;
        long group = 10;
        int digits = 2;
        while(counter + 9 * group * digits <= n){
            counter += 9 * group * digits;
            group = group * 10;
            digits++;
        }
        long num = group;
        while(counter + digits < n){
            num++;
            counter = counter + digits;
        }
        int remain = digits - n + counter;
        while(remain--){
            num = num / 10;
        } 
        return num % 10;
    }
};

class Solution {
public:
    int findNthDigit(int n) {
        if(n < 10) return n;
        long counter = 9;
        long group = 10;
        int digits = 2;
        while(counter + 9 * group * digits <= n){
            counter += 9 * group * digits;
            group = group * 10;
            digits++;
        }
        long num = group;
        while(counter + digits < n){
            num++;
            counter = counter + digits;
        }
        int remain = digits - n + counter;
        while(remain--){
            num = num / 10;
        } 
        return num % 10;
    }
};