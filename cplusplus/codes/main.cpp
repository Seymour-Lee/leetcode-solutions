#include <iostream>
#include <vector>
#include <deque>

#include "template.h"
#include "myvector.h"
#include "Vector.h"
#include "String.h"
#include "round_robin.h"
#include "rrscheduler.h"

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

class A{

private:
    A(int a){};
};

int strcmp2(const char *p1, const char *p2)
{
    const unsigned char *s1 = (const unsigned char *) p1;
    const unsigned char *s2 = (const unsigned char *) p2;
    unsigned char c1, c2;
    do{
        c1 = (unsigned char) *s1++;
        c2 = (unsigned char) *s2++;
        if (c1 == '\0') return c1 - c2;
    }
    while (c1 == c2);
    return c1 - c2;
}

int strcmp1(const char *s1, const char *s2){
    while(*s1 && (*s1 == *s2)) s1++, s2++;
    return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}


int main(){
    // cout<<(int)'\0'<<endl;;
    // test_round_robin();
    // test_scheduler();
    // deque<int> dq = {1, 2, 3, 4, 5};
    // for(auto it = dq.begin(); it != dq.end(); it++) cout<<*it<<" ";


    return 0;
}