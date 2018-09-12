class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        const int sum = maxChoosableInteger * (maxChoosableInteger + 1) / 2;
        if(sum < desiredTotal) return false;
        if(desiredTotal <= 0) return true;
        m_ = vector<char>((1 << maxChoosableInteger), 0);
        return canIWin(maxChoosableInteger, desiredTotal, 0);
    }
    
private:
    vector<char> m_;
    bool canIWin(int W, int T, int state){
        if(T <= 0) return false;
        if(m_[state]) return m_[state] == 1;
        for(int i = 0; i < W; i++){
            if(state & (1 << i)) continue;
            if(!canIWin(W, T-(i+1), state|(1 << i)))
                return m_[state] = 1;
        }
        m_[state] = -1;
        return false;
    }
};