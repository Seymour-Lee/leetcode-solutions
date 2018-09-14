class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> count(26, 0);
        int maxLengthCur = 0;
        for(int i = 0; i < p.size(); i++){
            if(i > 0 && (p[i]-p[i-1] == 1 || p[i-1]-p[i] == 25)){
                maxLengthCur++;
            }
            else{
                maxLengthCur = 1;
            }
            count[p[i]-'a'] = max(count[p[i]-'a'], maxLengthCur);
        }
        return accumulate(count.begin(), count.end(), 0);
    }
};