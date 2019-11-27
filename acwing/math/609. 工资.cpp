#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int a, b;
    double c;
    cin >> a >> b >> c;
    cout<<"NUMBER = "<<a<<endl;
    cout<<"SALARY = U$ "<<setprecision(2)<<fixed<<b*c;
    return 0;
}