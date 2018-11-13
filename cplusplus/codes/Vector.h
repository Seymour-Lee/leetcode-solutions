#include <iostream>
#include <memory>


using namespace std;

template <class T, class Allocator = allocator<T>> class Vector{
public:
    typedef T value_type;
    typedef T * iterator;
    typedef size_t size_type;

    // new delete[] throw???
    // (done) remember to include <iostream> or include <cstddef> for size_t
    // Vector(std::size_t count, const T& value);
    // Vector(Vector<T> &&rhs);
    // Vector& opeartor=(const Vector<T>& rhs);
    // (done) ~Vector();
    // void push_back(const T& value);
    // std::size_t size();
    // insert
    // at
    // operator[]

    Vector();
    Vector(size_type _s);
    Vector(size_type _s, T _val);
    Vector(const Vector<T, Allocator>& v);
    ~Vector();

    size_type capacity() const;
    size_type size() const;
    bool empty();
    iterator begin();
    iterator end();
    T& front();
    T& back();
    void push_back(const T& val);
    void pop_back();

    void reserve(size_type cap);
    void resize(size_type s);

    T& operator [](size_type i);
    Vector<T, Allocator>& operator = (const Vector<T, Allocator>& v);
    void clear();

private:
    size_type _size;
    size_type _capacity;
    T *_buffer;
};

template<class T, class Allocator>
Vector<T, Allocator>::Vector(){
    _size = 0;
    _capacity = 0;
    _buffer = nullptr;
}

template<class T, class Allocator>
Vector<T, Allocator>::Vector(size_type _s){
    _size = _s;
    _capacity = _s;
    _buffer = new T[_capacity];
}

template<class T, class Allocator>
Vector<T, Allocator>::Vector(size_type _s, T _val){
    _size = _s;
    _capacity = _s;
    _buffer = new T[_capacity];
    for(size_type i = 0; i < _size; i++) _buffer[i] = _val;
}

template<class T, class Allocator>
Vector<T, Allocator>::Vector(const Vector<T, Allocator>& v){
    _size = v._size;
    _capacity = v._capacity;
    _buffer = new T[_capacity];

    for(size_type i = 0; i < _size; i++) _buffer[i] = v._buffer[i];
}

template<class T, class Allocator>
Vector<T, Allocator>::~Vector(){
    for(size_t i = 0; i < _size; i++) (_buffer+i)->~T();
    ::operator delete(_buffer);
}

template<class T, class Allocator>
typename Vector<T, Allocator>::size_type Vector<T, Allocator>::capacity() const{
    return _capacity;
}

template<class T, class Allocator>
typename Vector<T, Allocator>::size_type Vector<T, Allocator>::size() const{
    return _size;
}

template<class T, class Allocator>
bool Vector<T, Allocator>::empty(){
    return _size == 0;
}

template<class T, class Allocator>
typename Vector<T, Allocator>::iterator Vector<T, Allocator>::begin(){
    return _buffer;
}

template<class T, class Allocator>
typename Vector<T, Allocator>::iterator Vector<T, Allocator>::end(){
    return _buffer+_size;
}

template<class T, class Allocator>
T& Vector<T, Allocator>::front(){
    return _buffer[0];
}

template<class T, class Allocator>
T& Vector<T, Allocator>::back(){
    return _buffer[_size-1];
}

template<class T, class Allocator>
void Vector<T, Allocator>::push_back(const T& val){
    if(_size == _capacity){
        reserve(_capacity == 0? 1: _capacity*2);
    }
    // _buffer[_size++] = T(val);
    new(_buffer+_size) T(val);
    _size++;
}

template<class T, class Allocator>
void Vector<T, Allocator>::pop_back(){
    (_buffer+_size-1)->~T();
    _size--;
}

template<class T, class Allocator>
void Vector<T, Allocator>::reserve(size_type cap){
    T *newbuffer = (T*)(::operator new((size_t)(cap * sizeof(T))));
    copy(_buffer, _buffer+_size, newbuffer);
    // for(size_type i = 0; i < _size; i++) newbuffer[i] = _buffer[i];
    _capacity = cap;
    // delete[] _buffer;
    delete(_buffer);
    _buffer = newbuffer;
}

template<class T, class Allocator>
void Vector<T, Allocator>::resize(size_type s){
    reserve(s);
    _size = s;
}

template<class T, class Allocator>
T & Vector<T, Allocator>::operator [] (size_type i){
    return _buffer[i];
}

template<class T, class Allocator>
Vector<T, Allocator> & Vector<T, Allocator>::operator = (const Vector<T, Allocator> &v){
    _size = v.size();
    _capacity = v.capacity();
    if(_buffer != nullptr) delete[] _buffer;
    _buffer = new T[_size];
    for(size_type i = 0; i < _size; i++) _buffer[i] = v._buffer[i];
}

template<class T, class Allocator>
void Vector<T, Allocator>::clear(){
    _size = 0;
    _capacity = 0;
    delete[] _buffer;
    _buffer = nullptr;
}




