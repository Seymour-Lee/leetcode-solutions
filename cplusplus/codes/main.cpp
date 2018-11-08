#include <iostream>
#include <vector>

#include "template.h"
#include "myvector.h"
#include "Vector.h"
#include "String.h"

using namespace std;


void test_vector(){
    Vector<int> v;
    // cout<<v.front();

   v.reserve(2);
   assert(v.capacity() == 2);

   Vector<string> v1(2);
   assert(v1.capacity() == 2);
   assert(v1.size() == 2);
   assert(v1[0] == "");
   assert(v1[1] == "");

   v1[0] = "hi";
   assert(v1[0] == "hi");

   Vector<int> v2(2, 7);
   assert(v2[1] == 7);

   Vector<int> v10(v2);
   assert(v10[1] == 7);

   Vector<string> v3(2, "hello");
   assert(v3.size() == 2);
   assert(v3.capacity() == 2);
   assert(v3[0] == "hello");
   assert(v3[1] == "hello");

   v3.resize(1);
   assert(v3.size() == 1);
   assert(v3[0] == "hello");

   Vector<string> v4 = v3;
   assert(v4.size() == 1);
   assert(v4[0] == v3[0]);
   v3[0] = "test";
   assert(v4[0] != v3[0]);  
   assert(v4[0] == "hello");

   v3.pop_back();
   assert(v3.size() == 0);

   Vector<int> v5(7, 9);
   Vector<int>::iterator it = v5.begin();
   for(auto a: v5) assert(a == 9);
   while (it != v5.end())
   {
      assert(*it == 9);
      ++it;
   }

   Vector<int> v6;
   v6.push_back(100);
   assert(v6.size() == 1);
   assert(v6[0] == 100);
   v6.push_back(101);
   assert(v6.size() == 2);
   assert(v6[0] == 100);
   v6.push_back(101);

   cout << "SUCCESS\n";
}


int main(){
    test_vector();
    vector<int> a;
    // cout<<"hello world\n";
    // // assert(0 > 1);
    // myvector<int> vec(10, 1);
    // myvector<int> vec1(vec);
    // cout<<vec1.size()<<endl;
    // cout<<vec1.front()<<endl;
    // for(int i = 0; i < vec1.size(); i++) cout<<vec1[i]<<" ";
    // // for(auto a: vec) cout<<a<<" ";
    // cout<<endl;
    // cout<<getMax<int>(1, 2)<<endl;
    // cout<<getMax<char>('a', 'c')<<endl;
    // cout<<getMax<double>(3.0, 2.9)<<endl;
    return 0;
}