class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<long long> dis;
        dis.push_back(((long long)p1[0]-p2[0])*((long long)p1[0]-p2[0]) 
                      + ((long long)p1[1]-p2[1])*((long long)p1[1]-p2[1]));
        dis.push_back(((long long)p1[0]-p3[0])*((long long)p1[0]-p3[0]) 
                      + ((long long)p1[1]-p3[1])*((long long)p1[1]-p3[1]));
        dis.push_back(((long long)p1[0]-p4[0])*((long long)p1[0]-p4[0]) 
                      + ((long long)p1[1]-p4[1])*((long long)p1[1]-p4[1]));
        dis.push_back(((long long)p2[0]-p3[0])*((long long)p2[0]-p3[0]) 
                      + ((long long)p2[1]-p3[1])*((long long)p2[1]-p3[1]));
        dis.push_back(((long long)p2[0]-p4[0])*((long long)p2[0]-p4[0]) 
                      + ((long long)p2[1]-p4[1])*((long long)p2[1]-p4[1]));
        dis.push_back(((long long)p3[0]-p4[0])*((long long)p3[0]-p4[0]) 
                      + ((long long)p3[1]-p4[1])*((long long)p3[1]-p4[1]));
        sort(dis.begin(), dis.end());
        return dis[0] == dis[1] && dis[1] == dis[2] && dis[2] == dis[3]
               && dis[4] == dis[5] && dis[0] != 0 && dis[4] != 0;
    }
};

class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        auto f = [](vector<int> &a, vector<int> &b){
            return (a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]);
        };
        unordered_set<int> dis = {f(p1, p2), f(p2, p3), f(p3, p4), f(p4, p1), f(p1, p3), f(p2, p4)};
        return dis.size() == 2 && dis.find(0) == dis.end();
    }
};

class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        auto f = [](vector<int> &a, vector<int> &b){
            return (a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]);
        };
        unordered_set<int> dis = {f(p1, p2), f(p2, p3), f(p3, p4), f(p4, p1), f(p1, p3), f(p2, p4)};
        return dis.size() == 2 && dis.find(0) == dis.end();
    }
};