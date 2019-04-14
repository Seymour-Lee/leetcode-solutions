class Solution {
public:
    bool divisorGame(int N) {
        return N % 2 == 0;
        // vector<bool> dp(N+1, false);
        // dp[1] = false;
        // for(int i = 2; i <= N; i++){
        //     for(int x = 1; x < i; x++){
        //         if(dp[])
        //     }
        // }
        // return dp[N];
        queue<int> q;
        q.push(N);
        int step = 0;
        while(q.empty() == false){
            // even -> Alice, odd -> Bob
            int size = q.size();
            while(size--){
                int cur = q.front(); q.pop();
                if(cur == 1 && step % 2 == 0) return true;
                int counter = 0;
                for(int i = 1; i < cur; i++){
                    if(cur % i == 0){
                        q.push(cur - i);
                        counter++;
                    }
                }
                // if(counter == 0 && step % 2 == 0) return false;
            }
            step++;
        }
        cout<<"er "<<step<<endl;
        return step % 2 == 0;
    }
};