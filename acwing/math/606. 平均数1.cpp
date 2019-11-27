#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    double a, b;
    cin >> a >> b;
    cout<<"MEDIA = "<<std::setprecision(5) <<fixed<<(a*3.5+b*7.5) / 11.0;
    return 0;
}