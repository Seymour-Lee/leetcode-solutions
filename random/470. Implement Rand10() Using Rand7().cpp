// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int idx = 41;
        while(idx > 40){
            int row = rand7();
            int col = rand7();
            idx = col + (row - 1) * 7;
        }
        return 1 + idx % 10;
    }
};

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int ans = 50;
        while(ans > 40) ans = rand7()+(rand7()-1)*7;
        return 1+(ans-1) % 10;
    }
};