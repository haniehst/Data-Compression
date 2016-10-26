#include "Vector.h"
template <class T>
Vector<T>::Vector()
{
    _capacity = 50;
    _array = new int[_capacity];
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
void Vector<T>::push(T val)
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
T Vector<T>::operator[](int i)
{
    return _array[i];
}
template <class T>
int Vector<T>::at(int i)
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
}
template <class T>
int Vector<T>::get_size()
{
    return _size;
}
template <class T>
Vector<T>& Vector<T>::operator = (const Vector& v){
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
Vector<T>& Vector<T>::operator += (T i){
    this -> push(i);
    return *this;
}
