## C++

### 1. Override vs. Overload

We override a function to change the behavior of that function in a derived class. It is a type of polymorphism in C++. Usually, there will be a base class providing interface, and the derived class provides implementation.

Overload means some functions have some function, but different arguments. One of the most commen cases is constructors. But usually using a different name is a better choice than using overload.

### 2. new/delete vs. malloc/free

When we use new operator, the memory is allocated from free store and returns a fully typed pointer. If it fails to get new memory, it will throw a exception.  New and Delete operators can handle arrays. The compiler calculates the size using type-id. New/Delete can be overridden legally. Constructor and Destructor use these two operators to initialize or destroy the object.

Malloc will get the memory from heap and return a void pointer. If it fails to get some memory it will return NULL. Also when we use malloc, we need to specify the size required in bytes. We can reallocate larger chunk of memory simple, because there is no copy constructor to worry about. Malloc/free can not be overridden legally.

New and malloc can not be mixed. Whether Free Store and Heap areas are the same is an implementation details.

### 3. map queue stack vector

### 4. static vs. non-static

### 5. class vs. struct

The biggest defferent between class and struct is the access-specifier. Members of a class are private by default. Members of a struct or union are public by default.

### 6. Inheritance

Inheritance means that a class can derive properties from another class.

**Public mode**: If we derive a sub class from a public base class. Then the public member of the base class will become public in the derived class and protected members of the base class will become protected in derived class.

**Protected mode**: If we derive a sub class from a Protected base class. Then both public member and protected members of the base class will become protected in derived class.

**Private mode**: If we derive a sub class from a Private base class. Then both public member and protected members of the base class will become Private in derived class.

### 7. What is polymorphism in C++

In C++, there are two kinds of polymorphism. One is compile time polymorphism, another is runtime polymorphism.

Compile time polymorphism is achieved by function overloading or operator overloading.

Runtime polymorphism is achieved by function overriding. Function overriding occurs when a derived class has a definition for one of the member functions of the base class. That base function is said to be overridden.

### 8. How are virtual functions and vtable implemented



### 9. delete vs delete[]

The **delete []** operator deallocates memory and calls destructors for an array of objects created with new **[]** . Using **delete** on a pointer returned by new **[]** or **delete []** on a pointer returned by new results in undefined behavior. The **delete[]** operator is used to **delete** arrays.







## Coding

### 1. Round-Robin Scheduling

Given job_queue, done_queue, current_time, quantum_time, calculate a round of RR scheduling.

Calculate all jobs' turn around time, waiting time and etc.

### 2. Ping-Pong

Given APIs: Send, Recev, Wait and etc functions, implement Ping() and Pong() to communicate with each other(Round Trip). There is a handler after sending or receiving to deal info for Wait()

### 3. Print all odd numbers between 1 to 100



### 4. Remove duplicate from unsorted array (2 methods)



### 5. is Power of 2 (Multi-Methods)

`return n <= 0? false: (n&(n-1)) == 0;` or

```C++
if(n <= 0) return false;
while(n % 2 == 0) n = n / 2;
return n == 1;
```



### 6. Get the largest 1 million numbers (minHeap)

Given 1 billion numbers and you can not store them all.

If I can store all numbers: Bubble k times (nk) + temporary array[0...k-1] ((n-k)*k) + Sort (nlogn) + **minHeap** + maxHeap extract k times (n+klogn) + Quick sort if no need for sorted output (n)



### 7. Median of datastream (minHeap+maxHeap/set) (two follow ups, explain time complexity)

### 8. Meeting Rooms

```C++
// Able to attend all meetings?
class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        if(intervals.size() <= 1) return true;
        auto f = [](Interval a, Interval b){return a.start <= b.start;};
        sort(intervals.begin(), intervals.end(), f);
        for(decltype(intervals.size()) i = 0; i < intervals.size()-1; i++){
            if(intervals[i].start == intervals[i+1].start 
               || intervals[i].end > intervals[i+1].start){
                return false;
            }
        }
        return true;
    }
};
```

```C++
// How many rooms do we need?
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<pair<int, bool>> times;
        for(auto e: intervals){
            times.push_back({e.start, true});
            times.push_back({e.end, false});
        }
        auto f = [](pair<int, bool> a, pair<int, bool> b){
            if(a.first != b.first) return a.first < b.first;
            return (int)a.second < (int)b.second;
        };
        sort(times.begin(), times.end(), f);
        int ans = 0;
        int count = 0;
        for(auto p: times){
            if(p.second) count++;
            else count--;
            ans = max(ans, count);
        }
        return ans;
    }
};
```

### 9. Write a Battleship AI (Onsite)

```C++

```



### 10. Price Data

Given couple sets of data(buy in price, sell price, latency) and a color tag that describe the
action, use new data to get the new color tag. (Glassdoor)

### 11. Wiggle Sort

```C++
class Solution {
public:
    // init: [1, 3, 2, 2, 3, 1]
    // 
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        auto midptr = nums.begin() + n / 2;
        nth_element(nums.begin(), midptr, nums.end());
        int mid = *midptr;
        
        #define A(i) nums[(1+2*(i)) % (n | 1)]
        
        int i = 0, j = 0, k = n - 1;
        while(j <= k){
            if(A(j) > mid)
                swap(A(i++), A(j++));
            else if(A(j) < mid)
                swap(A(j), A(k--));
            else
                j++;
        }
    }
};
```

### 11. Implement a stack using linked list



### 12. Given hour and minute, returns the degrees between the hands of the clock



### 13. Given a binary tree, how to guarantee thread-safe when there’re a lot of threads inserting and reading node.


### 14.  Implement multiplication of two integers



### 15. Find the closest leaf in a Binary Tree



### 16. Calculate mod 5 of a binary numbers (FSM)





## Operating System

### 1. What is virtual memory

Virtual memory is a memory management technique. It maps the virtual addresses used by a program, into physical addresses in computer's main memory. With virtual memory and paging methods, we can use more memory than might be physically available. Also, virtual memory frees program from having to manage a shared memory space, increased security due to memory isolation.

### 2. Compiled Language vs. Interpreted Language

If we compile a compiled language's program, the program will be expressed in the instructions of the target machine. Usually, we should get binary codes.

A program will read and execute interpreted language's program line by line. Ususlly the program is called interpreter. For example if I write a+b in Python, Python's interpreter will call a function like add(a, b), and finally execute ADD intruction in native machine codes.

Generally, a compiled language should have a faster performance. But interpreter is easier to implement and is more convenient for dynamic languages.

### 3. What is cache

A cache is a hardware or software component which stores data, so that we can use these data faster in the future. Generally, the data is the result of an earlier computation or a copy of data stored somewhere.

### 4. What is mutex

Mutex means mutual exclusion. It is used to prevent the race condition. It requires that one thread of exection never enter its critical section while another concurrent thread of execution enters its own critical section. In other words, no two thread enter their critical sections at the same time.

Modern locks, in pretty much all environments, are designed such that it isn't possible for two threads to lock an object at the same time. It *is* possible for modern processors to have two threads running on two different cores attempt to take a lock at very nearly the same time, but they all implement synchronization mechanisms that allow software to tell them not to allow it.



### 5. What is critical section

A critical section is the part of a program that accesses shared resources.

### 6. What is fork

Fork is an operation whereby a process creates a copy of itself. It is usually a system call in Unix system, implemented in the kernal. The purpose of fork() is to create a new process, which becomes the child process of the caller. After a new child process is created, both processes will execute the next instruction following the fork() system call. Therefore, we have to distinguish the parent from the child.

### 7. Stack vs. Heap

In the context of Operating Systems, stack and heap are the two sections of the memory layout of a process. The stack is used to keep track of variables/parameters local to a function in a program. Whenever you call a new function, a new stack frame is pushed to the stack with parameters and variables local to that function. When that function returns, the stack frame is popped out and the context switches back to the previous function (the caller). 

A heap is a kind of a global memory pool. A function can allocate memory on the heap if it wants the data to live longer than the function itself. Objects allocated on the heap are accessible to all the functions, given they have the reference/address of the object to access it. In C, you can allocate memory on the heap using the malloc(3) family of functions. 

Memory allocation on heap is much slower than on stack. Because heap is a far more complicated data structure than stack. For many architectures, allocating memory on the stack is just a matter of changing the stack pointer in one instruction. Allocating memory on the heap involves looking for a big enough block, splitting it, and managing the "book-keeping" that allows things like `free()` in a different order.

### 8. Deadlock



### 9. System Call



### 10. Python vs. Java







## Computer Network

### 1. TCP vs. UDP





## BrainTeaser

### 1. Three Baskets

We get three baskets, apple, orange and their mix, with all wrong label attached. Just take one fruit from three baskets and recorrect the labels.

We pick a fruit from mix, if it is an apple, the current correct label should be orange. And the orange label should be mix. And the apple label should be orange.



## Behaviour Questions

### 1. Talk about a challenging project, why challenging

### 2. Why Akuna Capital? Why not Google, Facebook? Why not Bay Area?

### 3. How do you solve the conflicts with your teammate?

### 4. Describe a hard bug you had and how you solved it



```C++
#include <iostream>
#include <memory>


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

```





