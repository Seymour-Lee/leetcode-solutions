class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int V, int K) {
        int n = heights.size();
        while (V--) {
            int j = K;
            for (int i = K - 1; i >= 0; i--) {
                if (heights[i] > heights[j]) break;
                else if (heights[i] < heights[j]) j = i;
            }
            if (j == K) {
                for (int i = K + 1; i < n; i++) {
                    if (heights[i] > heights[j]) break;
                    else if (heights[i] < heights[j]) j = i;
                }
            }
            heights[j]++;
        }
        
        return heights;
    }
};

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        if(target == "0000") return 0;
        unordered_set<string> deads(deadends.begin(), deadends.end());
        if(deads.find("0000") != deads.end() || deads.find(target) != deads.end()) return -1;
        queue<string> q;
        q.push("0000");
        unordered_set<string> seen;
        seen.insert("0000");
        int ans = 0;
        while(q.empty() == false){
            int size = q.size();
            ans++;
            while(size--){
                string front = q.front(); q.pop();
                for(auto &ch: front){
                    char ori = ch;
                    for(int i = -1; i <= 1; i+=2){
                        ch = ((ch+i+10-'0')%10) + '0';
                        if(front == target) return ans;
                        if(deads.find(front) == deads.end() && seen.find(front) == seen.end()){
                            q.push(front);
                            seen.insert(front);
                        }
                        ch = ori;
                    }
                }
            }
        }
        return -1;
    }
};