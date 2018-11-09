#include <iostream>

using namespace std;

template <class T> class Vector{
public:
    typedef T * iterator;
    typedef size_t size_type;

    Vector();
    Vector(size_type _s);
    Vector(size_type _s, T _val);
    Vector(const Vector<T>& v);
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
    Vector<T>& operator = (const Vector<T>& v);
    void clear();

private:
    size_type _size;
    size_type _capacity;
    T *_buffer;
};

template<class T>
Vector<T>::Vector(){
    _size = 0;
    _capacity = 0;
    _buffer = nullptr;
}

template<class T>
Vector<T>::Vector(size_type _s){
    _size = _s;
    _capacity = _s;
    _buffer = new T[_capacity];
}

template<class T>
Vector<T>::Vector(size_type _s, T _val){
    _size = _s;
    _capacity = _s;
    _buffer = new T[_capacity];
    for(size_type i = 0; i < _size; i++) _buffer[i] = _val;
}

template<class T>
Vector<T>::Vector(const Vector<T>& v){
    _size = v._size;
    _capacity = v._capacity;
    _buffer = new T[_capacity];
    for(size_type i = 0; i < _size; i++) _buffer[i] = v._buffer[i];
}

template<class T>
Vector<T>::~Vector(){
    delete[] _buffer;
}

template<class T>
typename Vector<T>::size_type Vector<T>::capacity() const{
    return _capacity;
}

template<class T>
typename Vector<T>::size_type Vector<T>::size() const{
    return _size;
}

template<class T>
bool Vector<T>::empty(){
    return _size == 0;
}

template<class T>
typename Vector<T>::iterator Vector<T>::begin(){
    return _buffer;
}

template<class T>
typename Vector<T>::iterator Vector<T>::end(){
    return _buffer+_size;
}

template<class T>
T& Vector<T>::front(){
    return _buffer[0];
}

template<class T>
T& Vector<T>::back(){
    return _buffer[_size-1];
}

template<class T>
void Vector<T>::push_back(const T& val){
    if(_size == _capacity){
        reserve(_capacity == 0? 1: _capacity*2);
    }
    _buffer[_size++] = val;
}

template<class T>
void Vector<T>::pop_back(){
    _size--;
}

template<class T>
void Vector<T>::reserve(size_type cap){
    T *newbuffer = new T[cap];
    for(size_type i = 0; i < _size; i++) newbuffer[i] = _buffer[i];
    _capacity = cap;
    delete[] _buffer;
    _buffer = newbuffer;
}

template<class T>
void Vector<T>::resize(size_type s){
    reserve(s);
    _size = s;
}

template<class T>
T & Vector<T>::operator [] (size_type i){
    return _buffer[i];
}

template<class T>
Vector<T> & Vector<T>::operator = (const Vector<T> &v){
    _size = v.size();
    _capacity = v.capacity();
    if(_buffer != nullptr) delete[] _buffer;
    _buffer = new T[_size];
    for(size_type i = 0; i < _size; i++) _buffer[i] = v._buffer[i];
}

template<class T>
void Vector<T>::clear(){
    _size = 0;
    _capacity = 0;
    delete[] _buffer;
    _buffer = nullptr;
}




