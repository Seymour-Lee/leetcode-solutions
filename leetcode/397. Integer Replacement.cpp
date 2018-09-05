class Solution {
public:
    int integerReplacement(int n) {
        queue<long> q;
        q.push((long)n);
        set<long> seen;
        seen.insert((long)n);
        int result = 0;
        while(q.empty() == false){
            int size = q.size();
            while(size--){
                long a = q.front(); q.pop();
                if(a == 1) return result;
                if(a % 2 == 0){
                    if(seen.find(a >> 1) == seen.end()){
                        q.push(a >> 1);
                        seen.insert(a >> 1);
                    }
                }
                else{
                    if(seen.find(a + 1) == seen.end()){
                        q.push(a + 1);
                        seen.insert(a + 1);
                    }
                    if(seen.find(a - 1) == seen.end()){
                        q.push(a - 1);
                        seen.insert(a - 1);
                    }
                }
            }
            result++;
        }
        return result;
    }
};