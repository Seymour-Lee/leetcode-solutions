#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
    double r;
    cin >> r;
    const double pi = 3.14159;
    cout<<"A="<<std::setprecision(4) <<fixed<<pi*r*r;
    return 0;
}