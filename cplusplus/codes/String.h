#include <iostream>
#include <memory>

using namespace std;


class String{
public:
    typedef char value_type;
    typedef char* iterator;

    // constructor
    // destructor();
    // =
    // +
    // substr
    // push_back();
    

    String();
    String(const String &s);
    String(const char *);
    String(size_t n, char c);
    ~String();
    String& operator = (String & s);

    iterator begin();
    iterator end();

    size_t size() const;
    size_t length() const;
    
    void resize(size_t s, char c);
    void insert(size_t pos, const String& str);

    char& operator [] (size_t i);
    String& operator += (const String& str);

    bool operator == (const String& a);

    friend ostream& operator << (ostream& os, const String& str);
    friend istream& operator >> (istream& is, const String& str){
        
    }

private:
    size_t _size;
    char *_buffer;
};

// String::String(){
//     _size = 0;
//     _buffer = nullptr;
// }

// char& String::operator [] (size_t i){
//     return _buffer[i];
// }

// istream& operator >> (istream& is, const String& str){
//     for(size_t i = 0; i < str.size(); i++){
//         is>>str._buffer[i];
//     }
//     return is;
// }



