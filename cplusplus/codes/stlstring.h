#include <iostream>
#include <memory>


template <class _CharT> class stl_basic_string{
public:
    typedef _CharT value_type;
    typedef size_t size_type;
    typedef value_type* iterator;
    typedef const value_type* const_iterator;
    typedef value_type& reference;

    stl_basic_string(): _size(0), _buffer(nullptr){}
    stl_basic_string(iterator __val): _size(strlen(__val)), _buffer(new value_type[_size]){
        std::copy(__val, __val+_size, _buffer);
    }
    stl_basic_string(const reference __other): _size(__other.size()), _buffer(new value_type[_size]){
        std::copy(__other.begin(), __other.end(), _buffer);
    }

    ~stl_basic_string(){
        delete [] _buffer;
    }

    size_type size() const { return _size; }
    size_type length() const { return _size; }
    iterator begin(){ return _buffer; }
    const_iterator begin() const { return _buffer; }
    iterator end() { return _buffer + _size; }
    const iterator end() const { return _buffer + _size; }

    reference operator = (const reference __other){
        if(this != &__other){
            delete[] _buffer;
            _size = __other._size;
            _buffer = new value_type[_size];
            std::copy(__other.begin(), __other.end(), _buffer);
        }
        return *this;
    } 

    stl_basic_string substr(size_type __pos = 0, size_type __len = -1){
        if(__pos+__len > size()) throw std::out_of_range("out of range in substr()");
        __len = (__len == -1? size()-__pos: __len);
        stl_basic_string __sub;
        __sub._size = __len;
        __sub._buffer = new value_type[_size];
        std::copy(begin()+__pos, begin()+__pos+__len, __sub._buffer);
        return __sub;
    }

    void push_back(value_type __value){
        iterator __new_buffer = new value_type[_size+1];
        std::copy(_buffer, _buffer+_size, __new_buffer);
        *(__new_buffer+_size) = __value;
        delete[] _buffer;
        _size++;
        _buffer = __new_buffer;
        std::cout<<__value<<"hhh"<<_size<<std::endl;
        // *(_buffer+_size) = __value;
    }

    reference operator [] (size_type i){
        if(i < 0 || i > size()) throw std::out_of_range("out of range in stl_basic_string::operator[]");
        return *(_buffer + i);
    }

    stl_basic_string operator + (const stl_basic_string& b){
        stl_basic_string str;
        str._size = _size + b._size;
        str._buffer = new value_type[str._size];
        std::copy(begin(), end(), str._buffer);
        std::copy(b._buffer, b._buffer+b._size, str._buffer+_size);
        return str;
    }
    

    friend std::ostream& operator << (std::ostream &os, const stl_basic_string& __val){
        std::cout<<__val.size()<<std::endl;
        for(size_type i = 0; i < __val.size(); i++) os.put(__val._buffer[i]);
        return os;
    }


    // constructor
    // destructor();
    // =
    // +
    // substr
    // push_back();

private:
    size_type _size;
    iterator _buffer;

    size_type strlen(iterator itor){
        size_type len = 0;
        while(*itor != '\0') itor++, len++;
        return len;
    }

};

typedef stl_basic_string<char> stlstring;

void test_stlstring(){
    stlstring a("abcdef"), b("ghijk");
    a.push_back('a');
    std::cout<<a<<std::endl;
    // std::cout<<(*a.end())<<std::endl;
    std::cout<<a.substr(1, 6)<<std::endl;
    stlstring c = a+b;
    std::cout<<c<<std::endl;
}