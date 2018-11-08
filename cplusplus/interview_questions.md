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









## Coding

### 1. Round-Robin Scheduling

Given job_queue, done_queue, current_time, quantum_time, calculate a round of RR scheduling.

Calculate all jobs' turn around time, waiting time and etc.

### 2. Ping-Pong

Given APIs: Send, Recev, Wait and etc functions, implement Ping() and Pong() to communicate with each other(Round Trip). There is a handler after sending or receiving to deal info for Wait()

### 3. Print all odd numbers between 1 to 100



### 4. Remove duplicate from unsorted array (2 methods)



### 5. Power of 2 (Multi-Methods)



### 6. Get the largest 1 million numbers (minHeap)

Given 1 billion numbers and you can not store them all.

### 7. Median of datastream (minHeap+maxHeap/set) (two follow ups, explain time complexity)





## Operating System

### 1. What is virtual memory

Virtual memory is a memory management technique. It maps the virtual addresses used by a program, into physical addresses in computer's main memory. With virtual memory and paging methods, we can use more memory than might be physically available. Also, virtual memory frees program from having to manage a shared memory space, increased security due to memory isolation.

### 2. Compiled Language vs. Interpreted Language

If we compile a compiled language's program, the program will be expressed in the instructions of the target machine. Usually, we should get binary codes.

A program will read and execute interpreted language's program line by line. Ususlly the program is called interpreter. For example if I write a+b in Python, Python's interpreter will call a function like add(a, b), and finally execute ADD intruction in native machine codes.

Generally, a compiled language should have a faster performance.

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





## BrainTeaser

### 1. Three Baskets

We get three baskets, apple, orange and their mix, with all wrong label attached. Just take one fruit from three baskets and recorrect the labels.

We pick a fruit from mix, if it is an apple, the current correct label should be orange. And the orange label should be mix. And the apple label should be orange.



## Behaviour Questions

### 1. Talk about a challenging project, why challenging

### 2. Why Akuna Capital? Why not Google, Facebook? Why not Bay Area?

### 3. How do you solve the conflicts with your teammate?

### 4. Describe a hard bug you had and how you solved it



