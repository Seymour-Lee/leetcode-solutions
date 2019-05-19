class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        unordered_map<int, int> num2times;
        for(auto a: A) num2times[a]++;
        for(auto p: num2times) if(p.second > 1) return p.first;
        return -1;
    }
};

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        while(true){
            int a = rand()%A.size();
            int b = rand()%A.size();
            if(a != b && A[a] == A[b]) return A[a];
        }
    }
};

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        unordered_set<int> seen;
        for(auto a: A){
            if(seen.find(a) != seen.end()) return a;
            seen.insert(a);
        }
        return 0;
    }
};