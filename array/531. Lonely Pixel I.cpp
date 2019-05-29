class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int ans = 0;
        vector<int> rcounter(picture.size(), 0);
        vector<int> ccounter(picture[0].size(), 0);
        for(int i = 0; i < picture.size(); i++){
            for(int j = 0; j < picture[i].size(); j++){
                if(picture[i][j] == 'B'){
                    rcounter[i]++;
                    ccounter[j]++;
                }
            }
        }
        for(int i = 0; i < picture.size(); i++){
            for(int j = 0; j < picture[i].size(); j++){
                if(picture[i][j] == 'B'){
                    if(rcounter[i] == 1 && ccounter[j] == 1)
                        ans++;
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& p) {
        vector<int> r(p.size(), 0);
        vector<int> c(p[0].size(), 0);
        for(int i = 0; i < p.size(); i++) for(int j = 0; j < p[i].size(); j++){
            if(p[i][j] == 'B') r[i]++, c[j]++;
        }
        int ans = 0;
        for(int i = 0; i < p.size(); i++) for(int j = 0; j < p[i].size(); j++){
            if(p[i][j] == 'B' && r[i] == 1 && c[j] == 1) ans++; 
        }
        return ans;
    }
};