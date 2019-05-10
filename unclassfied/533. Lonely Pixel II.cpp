class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int N) {
        // This is not a good problem, cause the description is confusing
        int m = picture.size();
        if(!m) return 0;
        int n = picture[0].size();
        if(!n) return 0;
        vector<int> rows(m,0), cols(n,0);
        unordered_map<string,int> um;
        vector<string> srows;
        for(int i = 0; i < m; ++i){
            string s;
            for(int j = 0; j < n; ++j){
                if(picture[i][j] == 'B'){
                    rows[i]++;
                    cols[j]++;
                }
                s.push_back(picture[i][j]);
            }
            um[s]++;
            srows.push_back(s);
        }
        int res = 0;
        for(int i = 0; i < m; ++i)
            if(rows[i] == N && um[srows[i]] == N)
                for(int j = 0; j < n; ++j)
                     if(picture[i][j] == 'B' && cols[j] == N) ++res;        
        return res;
    }
};

class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int N) {
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
                    if(rcounter[i] == ccounter[j] && rcounter[i] == N){
                        bool allsame = true;
                        for(int r = 0; r < picture.size() && allsame; r++){
                            if(picture[r][j] == 'B')
                                allsame = allsame && (picture[r] == picture[i]);
                        }
                        if(allsame) ans++;
                    }
                }
            }
        }
        return ans;
    }
};