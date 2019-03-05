#include <iostream>
#include <memory>

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



#define __BAD_ALLOC throw std::bad_alloc()


template <class Tp, class Tv>
void construct(Tp* ptr, const Tv& val){
    new (ptr)Tp(val);
}

template <class T>
void destroy(T* pointer){
    pointer->~T();
}

template <class T>
void destroy(T* first, T* last){
    for(; first != last; first++) destroy(first);
}

template <class T>
void deallocate(T* _buffer){
    if(_buffer != nullptr) free(_buffer);
}

template <class T>
T* doallocate(ptrdiff_t size){
    T* space = (T*)(malloc((size_t)(size * sizeof(T))));
    if(space == 0) __BAD_ALLOC;
    return space;
}

template <class T> class stlvector{
public:
    typedef T value_type;
    typedef value_type* iterator;
    typedef const value_type* const_iterator;
    typedef size_t size_type;
    typedef value_type& reference;

    iterator begin() {return start;}
    const_iterator begin() const { return start; }
    iterator end() {return finish;}
    const_iterator end() const { return finish; }
    size_type size() const {return size_type(int(end()-begin()));}
    size_type capacity() const {return size_type(int(end_of_storage-start));}
    bool empyt(){return start == finish;}
    reference operator[](size_type n){return *(start + n);}
    reference at(size_type n) { if(n >= size()) throw std::out_of_range("out of range in stlvector<T>::at()"); return *(start + n); }
    reference front(){return *start;}
    reference back(){return *(finish-1);}

    stlvector(): start(nullptr), finish(nullptr), end_of_storage(nullptr){}
    stlvector(size_type n, const T& value){fill_and_initialize(n, value);}
    stlvector(size_type n){fill_and_initialize(n, T());}
    stlvector(stlvector<T> &&_x): start(std::move(_x.start)), finish(std::move(_x.finish)), end_of_storage(std::move(_x.end_of_storage)){}
    stlvector(const stlvector<T> &_x){
        start = doallocate<T>(_x.size());
        finish = std::uninitialized_copy(_x.begin(), _x.end(), start);
        end_of_storage = finish;
    }
    ~stlvector(){
        destroy<T>(start, finish);
        // delete(start);
        deallocate<T>(start);
    }

    stlvector<T>& operator=(const stlvector<T>& _x){
        if(&_x != this){
            const size_type _xlen = _x.size();
            if(_xlen > capacity()){
                iterator new_start = doallocate<T>(_xlen);
                uninitialized_copy(start, finish, new_start);
                destory(start, finish);
                deallocate(start);
                start = new_start;
                end_of_storage = start + _xlen;
            }
            else if(size() >= _xlen){
                iterator _i = copy(_x.begin(), _x.end(), start);
                destory(_i);
            }
            else{ // xlen > size()
                copy(_x.begin(), _x.begin()+size(), start);
                uninitialized_copy(_x.begin()+size(), _x.end(), finish);
            }
            finish = start + _xlen;
        }
        return *this;
    }

    void resize(size_type _new_size, const T& _x){
        if(_new_size < size()){
            erase(begin()+_new_size, end());
        }
        else{
            insert(end(), _new_size-size(), _x);
        }
    }

    void resize(size_type _new_size) { resize(_new_size, T()); }

    void reserve(size_type n){
        iterator new_start = doallocate<T>(n);
        iterator new_finish = start;
        try{
            new_finish = std::uninitialized_copy(start, finish, new_start);
        }
        catch(std::exception &e){
            destroy<T>(new_start, new_finish);
            deallocate<T>(new_start);
            throw;
        }
        destroy<T>(start, finish);
        deallocate<T>(start);
        start = new_start;
        finish = new_finish;
        end_of_storage = start + n;
    }

    void pop_back(){
        --finish;
        destroy<T>(finish);
    }

    void push_back(const T& x){
        if(finish == end_of_storage){
            reserve((start == end_of_storage? 1: capacity()*2));
        }
        construct<T>(finish, x);
        finish++;
    }

    iterator insert(iterator position, const T& _x){
        if(finish != end_of_storage && position == end()){
            construct<T>(finish, _x);
            finish++;
        }
        else{
            insert(position, _x);
        }
        return position;
    }

    iterator insert(iterator position, size_type n, const T& _x){
        if(n != 0){
            if(size_type(end_of_storage - finish) >= n){
                T _x_copy = _x;
                const size_type elems_after = finish - position;
                iterator old_finish = finish;
                if(elems_after > n){
                    uninitialized_copy(finish-n, finish, finish);
                    finish += n;
                    copy_backward(position, old_finish-n, old_finish);
                    fill(position, position+n, _x_copy);
                }
                else{
                    std::uninitialized_fill_n(finish, n - elems_after, _x_copy);
					finish += n - elems_after;
					std::uninitialized_copy(position, old_finish, finish);
					finish += elems_after;
					fill(position, old_finish, _x_copy);
                }
            }
            else{
                const size_type old_size = size();
				const size_type len = old_size + std::max(old_size, n);
				iterator new_start = doallocate<T>(len);
				iterator new_finish = new_start;
				new_finish = std::uninitialized_copy(start, position, new_start);
				new_finish = std::uninitialized_fill_n(new_finish, n, _x);
				new_finish = std::uninitialized_copy(position, finish, new_finish);
				destroy<T>(start, finish);
				deallocate<T>(start);
				start = new_start;
				finish = new_finish;
				end_of_storage = new_start + len;
            }
        }
        return position;
    }


    iterator erase(iterator position){
        if(position + 1 != end()){
            std::copy(position+1, finish, position);
        }
        finish--;
        destroy<T>(finish);
        return position;
    }

    iterator erase(iterator first, iterator last){
        iterator new_finish = std::copy(last, finish, first);
        destroy<T>(new_finish, finish);
        finish = new_finish;
        return first;
    }

    stlvector<T> subvec(size_type pos, size_type len = -1) const{
        std::cout<<"len is "<<len<<std::endl;
        std::cout<<"equal? "<<(len == -1)<<std::endl;
        len = (len == -1? size()-pos: len);
        stlvector<T> sub(len);
        std::copy(start+pos, start+pos+len, sub.start);
        return sub;
    }


private:
    iterator start;
    iterator finish;
    iterator end_of_storage;

    void fill_and_initialize(size_type n, const T& value){
        start = allocate_and_fill(n, value);
        finish = start + n;
        end_of_storage = finish;
    }

    iterator allocate_and_fill(size_type n, const T& value){
        iterator _start = doallocate<T>(n);
        iterator curr = _start;
        while(n--) construct<T>(curr, value), curr++;
        return _start;
    }

    void insert_aux(iterator position, const T& _x = T()){
        if(finish != end_of_storage){
            construct<T>(finish, *(finish-1));
            finish++;
            T _x_copy = _x;
            std::copy_backward(position, finish-2, finish-1);
            *position = _x_copy;
        }
        else{
            ptrdiff_t old_size = size();
            const size_type len = old_size != 0? 2*old_size: 1;
            iterator new_start = doallocate<T>(len);
            iterator new_finish = new_start;
            try{
                new_finish = std::uninitialized_copy(start, position, new_start);
                construct<T>(new_finish, _x);
                new_finish++;
            }
            catch(std::exception &e){
                destroy<T>(new_start, new_finish);
                deallocate<T>(new_start);
                throw;
            }
            destroy<T>(start, finish);
            deallocate<T>(start);
            start = new_start;
            finish = new_finish;
            end_of_storage = new_start + len;
        }
    }

};

typedef stlvector<char> vecstlstring;



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