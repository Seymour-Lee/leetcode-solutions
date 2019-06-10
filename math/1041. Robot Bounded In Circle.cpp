class Solution {
public:
    bool isRobotBounded(string instructions) {
        int N = 0, E = 1, S = 2, W = 3;
        int x = 0, y = 0; 
        int dir = N;
        for (int i=0; instructions[i]; i++) { 
            char move = instructions[i]; 
            if (move == 'R') dir = (dir + 1)%4; 
            else if (move == 'L') dir = (4 + dir - 1)%4; 
            else{ 
                if (dir == N) y++; 
                else if (dir == E) x++; 
                else if (dir == S) y--; 
                else x--; 
            } 
        } 
        return (x == 0 && y == 0) || (dir != N); 
    }
};

class Solution {
public:
    bool isRobotBounded(string instructions) {
        int N = 0, E = 1, S = 2, W = 3;
        int x = 0, y = 0; 
        int dir = N;
        for (int i=0; instructions[i]; i++) { 
            char move = instructions[i]; 
            if (move == 'R') dir = (dir + 1)%4; 
            else if (move == 'L') dir = (4 + dir - 1)%4; 
            else{ 
                if (dir == N) y++; 
                else if (dir == E) x++; 
                else if (dir == S) y--; 
                else x--; 
            } 
        } 
        return (x == 0 && y == 0) || (dir != N); 
    }
};