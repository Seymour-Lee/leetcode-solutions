class Solution {
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, 
                    vector<vector<int>>& nuts) {
        int dist = 0, diff = INT_MIN;
        auto f = [](vector<int> a, vector<int> b){
            return abs(a[0]-b[0]) + abs(a[1]-b[1]);
        };
        for(auto nut: nuts){
            dist += f(nut, tree)*2;
            diff = max(diff, f(nut, tree)-f(nut, squirrel));
        }
        return dist - diff;
    }
};