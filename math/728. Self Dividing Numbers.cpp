class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        for(int i = left; i <= right; i++){
            if(isSelfDividing(i)) result.push_back(i);
        }
        return result;
    }
    
private:
    bool isSelfDividing(int x){
        stringstream stream;
        stream<<x;
        string str = stream.str();
        for(auto c: str){
            if(c == '0' || (x % (c - '0') > 0)) return false;
        }
        return true;
    }
};

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i = left; i <= right; i++){
            int n = i;
            while(n){
                int a = n % 10;
                if(a == 0 || i % a != 0) break;
                n = n / 10;
            }
            if(n == 0) ans.push_back(i);
        }
        return ans;
    }
};