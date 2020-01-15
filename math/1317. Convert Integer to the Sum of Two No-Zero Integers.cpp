class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int a = 1, b = n-1;
        while(a <= b){
            if(check(a, b)) break;
            a++, b--;
        }
        return {a, b};
    }
    
private:
    bool check(int a, int b){
        string aa = to_string(a), bb = to_string(b);
        return aa.find('0') == string::npos && bb.find('0') == string::npos;
    }
};