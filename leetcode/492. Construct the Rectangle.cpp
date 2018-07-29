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