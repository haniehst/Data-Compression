#ifndef VECTOR_H
#define VECTOR_H
#include<iostream>

using namespace std;
typedef unsigned short int usi;

template <class T>
class Vector
{
    public:
        Vector();
        Vector(int);
        Vector(const Vector&);
        void push(T);
        ~Vector();
        int get_size();
        T& operator[](int);
        Vector& operator = (const T&);
        Vector& operator += (const T&);
        int at(T&);
        bool _search(T);
        int get_index(T);

    private:
        T* _array;
        int _size;
        int _capacity;
        void alloc_new();
};

template <class T>
Vector<T>::Vector()
{
    _capacity = 50;
    _array = new T[_capacity];
    _size = 0;
}
template <class T>
Vector<T>::Vector(int i)
{
    _capacity = i;
    _array = new T[_capacity];
    _size = 0;
}
template <class T>
Vector<T>::Vector(const Vector& v) ///copy_constructor
{
        _capacity = v._capacity;
        _size = v._size;
        _array = new T[_capacity];
        for (int i = 0; i<_size; i++)
            _array[i] = v._array[i];
}
template <class T>
void Vector<T>::push(T
                      val)
{
    if(_size + 1 > _capacity)
        alloc_new();
    _array[_size] = val;
    _size ++;
}
template <class T>
Vector<T>::~Vector()
{
    delete []_array;
}
template <class T>
T& Vector<T>::operator[](int i)
{
    if ( i < 0 )
        cerr<<"index less than zero"<<endl;
    if (i >= _size)
        cerr<<"index more than size"<<endl;
    else
        return _array[i];
}
template <class T>
int Vector<T>::at(T& i)
{
    if(i < _size)
        return _array[i];
    throw 10; ///exception
}
template <class T>
void Vector<T>::alloc_new()
{
    _capacity = _size + 100;
    T* tmp = new T[_capacity];
    for (int i=0; i<_size; i++)
        tmp[i] = _array[i];
    delete[] _array;
    _array = tmp;
    delete[] tmp;
}
template <class T>
int Vector<T>::get_size()
{
    return _size;
}
template <class T>
Vector<T>& Vector<T>::operator=(const T& v){
    if(this != &v)
    {
        _capacity = v._capacity;
        _size = v._size;
        delete[] _array;
        _array = new T[_capacity];
        for (int i = 0; i<_size; i++)
            _array[i] = v._array[i];
    }
    return *this;

}

template <class T>
Vector<T>& Vector<T>::operator += (const T& i){
    this -> push(i);
    return *this;
}

template <class T>
bool Vector<T>:: _search(T val){
    for(int i = 0; i< _size;i++)
        if(_array[i] == val)
            return true;
    return false;
}

template <class T>
int Vector<T>::get_index(T val){
    for(int i = 0; i< _size;i++)
        if(_array[i] == val)
            return i;
    return -1;
}
#endif // VECTOR_H
