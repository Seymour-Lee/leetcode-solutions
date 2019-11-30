#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){
    double x0, y0, x1, y1;
    cin>>x0>>y0>>x1>>y1;
    cout<<setprecision(4)<<fixed<<sqrt((x1-x0)*(x1-x0)+(y1-y0)*(y1-y0));
    return 0;
}