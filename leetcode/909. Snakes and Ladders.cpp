class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        map<int, int> dist;
        dist[1] = 0;
        queue<int> q;
        q.push(1);
        while(q.empty() == false){
            int front = q.front(); q.pop();
            if(front == n*n) return dist[front];
            for(int i = front+1; i <= min(front+6, n*n); i++){
                int rc = get(i, n);
                int r = rc / n, c = rc % n;
                int end = board[r][c] == -1 ? i : board[r][c];
                if(dist.find(end) == dist.end()){
                    dist[end] = dist[front]+1;
                    q.push(end);
                }
            }
        }
        return -1;
    }
    
private:
    int get(int s, int N) {
        // Given a square num s, return board coordinates (r, c) as r*N + c
        int quot = (s-1) / N;
        int rem = (s-1) % N;
        int row = N - 1 - quot;
        int col = row % 2 != N % 2 ? rem : N - 1 - rem;
        return row * N + col;
    }
};