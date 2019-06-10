class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int result = 0;
        for(auto p: points){
            map<int, int> table;
            table.clear();
            for(auto q:points){
                table[(p.first-q.first) * (p.first-q.first) + (p.second-q.second) * (p.second-q.second)]++;
            }
            for(auto item: table){
                if(item.second > 1){
                    result += item.second * (item.second-1);
                }
            }
        }
        return result;
    }
};

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int result = 0;
        for(auto p: points){
            map<int, int> table;
            table.clear();
            for(auto q:points){
                table[(p[0]-q[0])*(p[0]-q[0]) + (p[1]-q[1])*(p[1]-q[1])]++;
            }
            for(auto item: table){
                if(item.second > 1){
                    result += item.second * (item.second-1);
                }
            }
        }
        return result;
    }
};