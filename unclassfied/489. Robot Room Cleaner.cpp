/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */
class Solution {
public:
    void cleanRoom(Robot& robot) {
        if(visited[i][j] == true) return;
        visited[i][j] = true;
        robot.clean();
        for(int d = 0; d < 4; d++){
            if(robot.move()){
                i += dir_x[dir];
                j += dir_y[dir];
                cleanRoom(robot);
                robot.turnRight();
                robot.turnRight();
                robot.move();
                robot.turnRight();
                robot.turnRight();
                i -= dir_x[dir];
                j -= dir_y[dir];
            }
            robot.turnRight();
            dir = (dir+1) % 4;
        }
    }
    
private:
    unordered_map<int, unordered_map<int, bool>> visited;
    int i = 0, j = 0, dir = 0;
    vector<int> dir_x = {1, 0, -1, 0}; // down, up, left, right
    vector<int> dir_y = {0, 1, 0, -1};
};