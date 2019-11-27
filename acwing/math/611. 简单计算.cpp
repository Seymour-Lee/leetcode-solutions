#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int a, b;
    double c;
    int d, e;
    double f;
    cin>>a>>b>>c>>d>>e>>f;
    cout<<"VALOR A PAGAR: R$ "<<setprecision(2)<<fixed<<b*c+e*f;
    return 0;
}