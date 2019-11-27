#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main(){
    string a;
    double b, c;
    cin >> a >> b >> c;
    cout<<"TOTAL = R$ "<<setprecision(2)<<fixed<<b+0.15*c;
    return 0;
}