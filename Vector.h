#ifndef VECTOR_H
#define VECTOR_H

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
        T operator[](int);
        Vector& operator = (const Vector&);
        Vector& operator += (T);
        int at(int i);

    private:
        T* _array;
        int _size;
        int _capacity;
        void alloc_new();
};

#endif // VECTOR_H
