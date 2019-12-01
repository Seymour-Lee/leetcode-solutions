/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *   public:
 *     bool hasShips(vector<int> topRight, vector<int> bottomLeft);
 * };
 */

class Solution {
public:
    int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft) {
        int x1 = bottomLeft[0], y1 = bottomLeft[1], x2 = topRight[0], y2 = topRight[1];
        return binary(sea, x1, y1, x2, y2);
    }
    
private:
    int binary(Sea sea, int x1, int y1, int x2, int y2) {
        if(x2 < x1 || y2 < y1) return 0;
        if(!sea.hasShips({ x2, y2 }, { x1, y1 })) return 0;
        if(x2 == x1 && y2 == y1 && sea.hasShips({ x1, y1 }, { x2, y2 })) return 1;
        int a = (x2 - x1) / 2, b = (y2 - y1) / 2;
        return binary(sea, x1, y1, x1 + a, y1 + b) 
             + binary(sea, x1 + a + 1, y1 + b + 1, x2, y2)
             + binary(sea, x1 + a + 1, y1, x2, y1 + b) 
             + binary(sea, x1, y1 + b + 1, x1 + a, y2);
    }
};