class Solution {
public:
    bool canTransform(string start, string end) {
        for(int i = 0, j = 0; i < start.size() && j < end.size();){
            if(start[i] == 'X') i++;
            if(end[j] == 'X') j++;
            if(start[i] != 'X' && end[j] != 'X'){
                if(start[i] != end[j]) return false;
                else if(start[i] == 'L' && j > i) return false;
                else if(start[i] == 'R' && j < i) return false;
                else i++, j++;
            }
        }
        return true;
    }
};