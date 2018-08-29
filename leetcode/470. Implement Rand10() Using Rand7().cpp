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