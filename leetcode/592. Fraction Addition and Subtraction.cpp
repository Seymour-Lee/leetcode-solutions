class Solution {
public:
    string fractionAddition(string expression) {
        stringstream ss(expression);
        char op;
        int a, b, c, d;
        ss>>a;
        ss>>op;
        ss>>b;
        while(ss>>c){
            ss>>op;
            ss>>d;
            add(a, b, c, d);
        }
        return to_string(a) + "/" + to_string(b);
    }
    
private:
    int gcd(int a, int b){
        while(b != 0){
            int t = b;
            b = a % b;
            a = t;
        }
        return a;
    }
    
    void add(int &a, int &b, int c, int d){
        int nume = a * d + b * c, deno = b * d;
        int g = gcd(abs(nume), abs(deno));
        a = nume / g;
        b = deno / g;
    }
};