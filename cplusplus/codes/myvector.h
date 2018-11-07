#include <iostream>

template <class T> class myvector{
public:
    myvector(){
        vArr = nullptr;
        vCapacity = 0;
        vSize = 0;
    }

    myvector(unsigned int _vSize, unsigned int _val){
        vCapacity = _vSize;
        vSize = _vSize;
        vArr = new T[vCapacity];
        for(decltype(_vSize) i = 0; i < vSize; i++)
            vArr[i] = _val;
    }

    myvector(const myvector<T> &vec){
        this = vec;
    }

    ~myvector(){
        delete vArr;
    }

    T &operator [](unsigned int i){
        assert((i < vSize) && (i >= 0));
        return vArr[i];
    }

    myvector<T> &operator =(myvector<T> vec){

    }

    void push_back(const T &item){
        expand();
        vArr[vSize] = item;
        vSize++;
    }

    void pop_back(){
        assert(vSize > 0);
        vSize--;
        shrink();
    }

    unsigned int size(){
        return vSize;
    }

    unsigned int capacity(){
        return vCapacity;
    }

    void insert(unsigned int pos, T &item){
        assert(pos <= vSize);
        expand();
        vSize++;
        for(auto i = vSize-1; i > pos; i++) vArr[i] = vArr[i-1];
        vArr[pos] = item;
    }

    void erase(unsigned int pos){
        assert(pos < vSize);
        for(auto i = pos; i < vSize-1; i++) vArr[i] = vArr[i+1];
        vSize--;
        shrink();
    }

    T &front(){
        assert(vSize > 1);
        return vArr[0];
    }

    T &back(){
        assert(vSize > 1);
        return vArr[vSize-1];
    }

    T &at(unsigned int i){
        assert((0 <= i) && (i < vSize));
        return vArr[i];
    }

    void clear(){
        delete vArr;
        vArr = nullptr;
        vSize = 0;
        vCapacity = 0;
    }



private:
    unsigned int vCapacity;
    unsigned int vSize;
    T *vArr;

    void expand(){
        if(vSize == vCapacity){
            if(vCapacity == 0){
                resize(1, false);
            }
            else{
                resize(2*vCapacity, true);
            }
        }
    }

    void shrink(){
        if(vSize * 2 < vCapacity){
            if(vSize == 0){
                clear();
            }
            else{
                resize(vCapacity/2, true);
            }
        }
    }

    void resize(unsigned int n, bool copy){
        T *newArr = new T[n];
        if(newArr == nullptr){
            throw "myvector<T>::reserve(): memory allocation error";
        }
        if(copy){
            for(decltype(n) i = 0; i < vSize; i++){
                newArr[i] = vArr[i];
            }
        }
        if(vArr != nullptr) delete vArr;
        vArr = newArr;
        vCapacity = n;
    }
};



