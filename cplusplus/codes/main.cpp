#include <iostream>
#include <vector>
#include <deque>
#include <string>

#include "template.h"
#include "myvector.h"
#include "stlvector.h"
#include "Vector.h"
#include "String.h"
#include "round_robin.h"
#include "rrscheduler.h"

#include "stlstring.h"
#include "mystring.h"

using namespace std;

class A{

public:
    int *ptr;
    A(const A &a){
        cout<<"in A's copy constructor"<<endl;
        this->ptr = new int;
        *this->ptr = *(a.ptr);
    }
    A(int val){
        cout<<"in A's low copy constructor"<<endl;
        ptr = new int;
        *ptr = val;
    }
    A(){ptr = new int; cout<<"in A's constructor"<<endl;}
    ~A(){cout<<"here "<<(*ptr)<<" "; delete ptr; cout<<"in A's destructor"<<endl;}
};

void test_vector_destructor(){
    stlvector<A> as;
    A a(1), b(2);
    as.push_back(a);
    as.push_back(b);
    as.pop_back();

    stlvector<A> bs(as);
    cout<<as.size()<<" "<<bs.size()<<endl;
}

void test_vector(){
    stlvector<int> v;
    // cout<<v.front();

   v.reserve(2);
   assert(v.capacity() == 2);

   stlvector<string> v1(2);
   assert(v1.capacity() == 2);
   assert(v1.size() == 2);
   assert(v1[0] == "");
   assert(v1[1] == "");

   v1[0] = "hi";
   assert(v1[0] == "hi");

   stlvector<int> v2(2, 7);
   assert(v2[1] == 7);

   stlvector<int> v10(v2);
   assert(v10[1] == 7);

   stlvector<string> v3(2, "hello");
   assert(v3.size() == 2);
   assert(v3.capacity() == 2);
   assert(v3[0] == "hello");
   assert(v3[1] == "hello");

   v3.resize(1);
   assert(v3.size() == 1);
   assert(v3[0] == "hello");

   stlvector<string> v4 = v3;
   assert(v4.size() == 1);
   assert(v4[0] == v3[0]);
   v3[0] = "test";
   assert(v4[0] != v3[0]);  
   assert(v4[0] == "hello");

   v3.pop_back();
   assert(v3.size() == 0);

   stlvector<int> v5(7, 9);
   stlvector<int>::iterator it = v5.begin();
   for(auto a: v5) assert(a == 9);
   while (it != v5.end())
   {
      assert(*it == 9);
      ++it;
   }

   stlvector<int> v6;
   v6.push_back(100);
   assert(v6.size() == 1);
   assert(v6[0] == 100);
   v6.push_back(101);
   assert(v6.size() == 2);
   assert(v6[0] == 100);
   v6.push_back(101);

   cout << "SUCCESS\n";
}



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

void test_stlvector(){
    stlvector<int> test(2, 2);
	cout << "size = " << test.size() << "\t";
	cout << "capacity = " << test.capacity() << endl;

	test.push_back(1);
	cout << "size = " << test.size() << "\t";
	cout << "capacity = " << test.capacity() << endl;

	test.push_back(2);
	cout << "size = " << test.size() << "\t";
	cout << "capacity = " << test.capacity() << endl;

	test.push_back(3);
	cout << "size = " << test.size() << "\t";
	cout << "capacity = " << test.capacity() << endl;

	test.pop_back();
	cout << "size = " << test.size() << "\t";
	cout << "capacity = " << test.capacity() << endl;

	std::cout << test[2] << endl;

	test.erase(test.begin() + 1, test.begin() + 2);
	test.erase(test.begin());
	for (stlvector<int>::iterator it = test.begin(); it != test.end(); it++)
	{
		std::cout << *it << std::endl;
	}
}


int main(){
    // cout<<(int)'\0'<<endl;;
    // test_round_robin();
    // test_scheduler();
    // deque<int> dq = {1, 2, 3, 4, 5};
    // for(auto it = dq.begin(); it != dq.end(); it++) cout<<*it<<" ";
    test_rrschedual();
    // test_vector();
    // test_vector_destructor();
    // test_stlvector();
    // stlstring a("string");
    // stlstring b(10, 'a');
    // stlstring a(b.subvec(0));
    // for(auto ch: a) cout<<ch;
    // test_mystring();
    // test_stlstring();
    // int buf[19];
    // cout<<sizeof(buf)<<endl;
    // cout<<sizeof(int)<<endl;
    // copy(a.begin(), a.end(), b.begin());
    // cout<<a<<endl;
    // cout<<b<<endl;
    try{

        // throw bad_alloc();
        // __STL_THROW("aaa");
    }
    catch(bad_alloc &e){
        cerr<<e.what()<<endl;;
    }
    // catch(exception &e){
    //     cerr<<e.what()<<endl;
    // }
    return 0;
}