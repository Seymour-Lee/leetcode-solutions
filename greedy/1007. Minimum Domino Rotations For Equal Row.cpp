class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int n = A.size();
        unordered_map<int, int> num2times;
        for(auto a: A) num2times[a]++;
        for(auto b: B) num2times[b]++;
        vector<int> nums;
        for(auto p: num2times) if(p.second >= n) nums.push_back(p.first);
        unordered_map<int, unordered_set<int>> num2posa;
        unordered_map<int, unordered_set<int>> num2posb;
        unordered_map<int, unordered_set<int>> num2pos;
        for(int i = 0; i < A.size(); i++) num2pos[A[i]].insert(i), num2posa[A[i]].insert(i);
        for(int i = 0; i < B.size(); i++) num2pos[B[i]].insert(i), num2posb[B[i]].insert(i);
        int ans = INT_MAX;
        for(auto num: nums) if(num2pos[num].size() >= n){
            // maybe ans
            // cout<<num<<endl;
            unordered_set<int> a = {};
            unordered_set<int> b = {};
            for(auto pos: num2pos[num]){
                
                if(num2posa[num].find(pos) != num2posa[num].end() && num2posb[num].find(pos) != num2posb[num].end()) continue;
                // cout<<pos<<" ";
                if(num2posa[num].find(pos) != num2posa[num].end()) a.insert(pos);
                if(num2posb[num].find(pos) != num2posb[num].end()) b.insert(pos);
            }
            // cout<<endl;
            // cout<<ans<<" "<<a.size()<<" "<<b.size()<<endl;
            ans = min(ans, (int)min(a.size(), b.size()));
        }
        return ans == INT_MAX? -1: ans;
    }
};

class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int n = A.size();
        auto f = [&](int target){
            int ra = 0, rb = 0;
            for(int i = 0; i < A.size(); i++){
                if(A[i] != target && B[i] != target) return -1;
                if(A[i] != target) ra++;
                if(B[i] != target) rb++;
            }
            return min(ra, rb);
        };
        int ans = f(A[0]);
        if(ans != -1 || A[0] == B[0]) return ans;
        return f(B[0]);
    }
};