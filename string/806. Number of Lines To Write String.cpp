class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int lines = 1;
        int cur_width = 0;
        for(int i = 0; i < S.size(); i++){
            int width = widths[S[i]-'a'];
            if(cur_width + width > 100){
                lines++;
                cur_width = width;
            }
            else{
                cur_width += width;
            }
        }
        return vector<int>{lines, cur_width};
    }
};

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int lines = 1;
        int width = 0;
        for(int i = 0; i < S.size(); i++){
            int w = widths[S[i] - 'a'];
            if(width + w > 100){
                lines++;
                width = w;
            }
            else width += w;
        }        
        return {lines, width};
    }
};