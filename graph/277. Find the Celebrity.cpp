// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        map<int, int> in;
        map<int, int> out;
        for(int i = 0; i < n; i++){
            in[i] = 0;
            out[i] = 0;
        }
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(knows(i, j)){
                    in[j]++;
                    out[i]++;
                }
                if(knows(j, i)){
                    in[i]++;
                    out[j]++;
                }
            }
        }
        for(int i = 0; i < n; i++){
            if(out[i] == 0 && in[i] == n-1)
                return i;
        }
        return -1;
    }
};

// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        vector<int> ou(n, 0), in(n, 0);
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) if(i != j){
            if(knows(i, j)) ou[i]++, in[j]++;
        }
        for(int i = 0; i < n; i++) if(ou[i] == 0 && in[i] == n-1) return i;
        return -1;
    }
};