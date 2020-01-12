class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return !(rec1[2] <= rec2[0] ||
                 rec1[3] <= rec2[1] ||
                 rec1[0] >= rec2[2] ||
                 rec1[1] >= rec2[3]);
    }
};

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return !(rec1[2] <= rec2[0] ||
                 rec1[3] <= rec2[1] ||
                 rec1[0] >= rec2[2] ||
                 rec1[1] >= rec2[3]);
    }
};

class Solution {
public:
    bool isRectangleOverlap(vector<int>& r1, vector<int>& r2) {
        return r1[2] > r2[0] &&
               r1[3] > r2[1] &&
               r1[0] < r2[2] &&
               r1[1] < r2[3];
    }
};