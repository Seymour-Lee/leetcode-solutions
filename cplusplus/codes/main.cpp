#include <iostream>
#include <vector>

#include "template.h"
#include "myvector.h"

using namespace std;





int main(){
    cout<<"hello world\n";
    // assert(0 > 1);
    myvector<int> vec(10, 1);
    myvector<int> vec1(vec);
    cout<<vec1.front()<<endl;
    for(int i = 0; i < vec1.size(); i++) cout<<vec1[i]<<" ";
    // for(auto a: vec) cout<<a<<" ";
    cout<<endl;
    cout<<getMax<int>(1, 2)<<endl;
    cout<<getMax<char>('a', 'c')<<endl;
    cout<<getMax<double>(3.0, 2.9)<<endl;
    return 0;
}