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