class Solution {
public:
    int countArrangement(int N) {
        vector<bool> visited(N+1, false);
        int counter = 0;
        backtracking(N, 1, visited, counter);
        return counter;
    }
    
private:
    void backtracking(int N, int pos, vector<bool> visited, int &counter){
        if(pos > N){
            counter++;
            return;
        }
        for(int i = 1; i <= N; i++){
            if(visited[i] == false && (pos % i == 0 || i % pos == 0)){
                visited[i] = true;
                backtracking(N, pos+1, visited, counter);
                visited[i] = false;
            }
        }
    }
};