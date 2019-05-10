class SnakeGame {
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<pair<int, int>> food) {
        this->width = width;
        this->height = height;
        for(auto f: food) this->food.push(f);
        eaten = 0;
        snake.push_back({0, 0});
        occupied.insert({0, 0});
        dpos = {{"U", {-1, 0}},
                {"L", {0, -1}},
                {"R", {0, +1}},
                {"D", {+1, 0}}};
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        // if(food.size() == 0) return eaten;
        auto pos = snake.front();
        auto delta = dpos[direction];
        pair<int, int> next = {pos.first+delta.first, pos.second+delta.second};
        if(next.first < 0 || height <= next.first || 
           next.second < 0 || width <= next.second) return -1;
        if(food.size() != 0 && next == food.front()){
            food.pop();
            eaten++;
            snake.push_front(next);
            occupied.insert(next);
        }
        else{
            occupied.erase(snake.back());
            snake.pop_back();
            if(occupied.find(next) != occupied.end()) return -1;
            snake.push_front(next);
            occupied.insert(next);
        }
        return eaten;
    }
    
private:
    int width;
    int height;
    queue<pair<int, int>> food;
    int eaten;
    deque<pair<int, int>> snake;
    set<pair<int, int>> occupied;
    unordered_map<string, pair<int, int>> dpos;
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame obj = new SnakeGame(width, height, food);
 * int param_1 = obj.move(direction);
 */