class Solution {
public:
    vector<int> constructRectangle(int area) {
        if(area == 0) return vector<int>{0, 0};
        int w, l;
        for(w = sqrt(area); w >= 1; w--){
            if(area % w == 0){
                l = area / w;
                break;
            }
        }
        return vector<int>{l, w};
    }
};

class Solution {
public:
    vector<int> constructRectangle(int area) {
        int l = sqrt(area);
        int w = l;
        while(l*w != area){
            if(l*w < area) l++;
            else w--;
        }
        return {l, w};
    }
};