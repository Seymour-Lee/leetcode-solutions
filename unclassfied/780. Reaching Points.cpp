class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while(sx < tx && sy < ty) if(tx < ty) ty = ty % tx; else tx = tx % ty;
        return sx == tx && (ty - sy) % sx == 0 || sy == ty && (tx - sx) % sy == 0;
    }
};

class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while(tx >= sx && ty >= sy && tx != ty) {
            if(tx > ty) {
                if(tx == sx) return false;
                if(ty == sy) return (tx - sx) % ty == 0;
                tx %= ty;
            }
            else {
                if(ty == sy) return false;
                if(tx == sx) return (ty - sy) % tx == 0;
                ty %= tx;
            }
        }
        return (tx == sx && ty == sy);
    }
};