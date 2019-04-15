class Solution {
public:
    int numberOfDays(int Y, int M) {
        map<int, int> m2days = {{1, 31}, {2, 28}, {3, 31}, {4, 30}, {5, 31}, {6, 30}, {7, 31}, {8, 31}, {9, 30}, {10, 31}, {11, 30}, {12, 31}};
        auto f = [](int year){
            return (year % 4 == 0 && year % 100 !=0)||(year % 400 ==0 );
        };
        if(M == 2 && f(Y)) return 29;
        return m2days[M];
    }
};