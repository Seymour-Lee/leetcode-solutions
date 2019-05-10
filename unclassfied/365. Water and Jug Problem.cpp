class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        int g = gcd(x, y);
        if(g == 0) return z == 0;
        return (x + y >= z) && (z % g) == 0;
    }
    
private: 
    int gcd(int x, int y){
        while(y){
            int tmp = x % y;
            x = y;
            y = tmp;
        }
        return x;
    }
};