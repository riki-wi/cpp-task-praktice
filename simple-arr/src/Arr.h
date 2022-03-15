#ifndef SIMPLE_ARR_ARR_H
#define SIMPLE_ARR_ARR_H

#include "ArrayException.h"

template<typename T>
class Arr
{

private:
    T* mas;
    int size;

public:
    T& operator[](int index)
    {
        if(index < 0 || size <= index)
            throw IndexException();
        return mas[index];
    }

    Arr()
    {
        Arr<T>::size = 0;
        Arr<T>::mas = new T[size];
    }

    explicit Arr(int size)
    {
        Arr<T>::size = size;
        Arr<T>::mas = new T[size];
    }

    Arr(int size, T init)
    {
        Arr<T>::size = size;
        Arr<T>::mas = new T[size];
        for(int i = 0; i < size; i++)
        {
            mas[i] = init;
        }
    }

    T getElement(int index)
    {
        if(index < 0 || size <= index)
            throw IndexException();
        return mas[index];
    }

    int getSize()
    {
        return size;
    }

    void resize(int newSize)
    {
        if(newSize < 0)
            throw SizeException();

        if(newSize == size)
        {
            return;
        }

        T* newMas = new T[newSize];
        for(int i = 0; i < std::min(size, newSize); i++)
        {
            newMas[i] = mas[i];
        }

        mas = newMas;
        delete [] newMas;
        size = newSize;
    }

    void addElem(T elem)
    {
        resize(size + 1);
        mas[size - 1] = elem;
    }

    void removeElem(int index)
    {
        if(size < index || index < 0)
            throw IndexException();

        T* newMas = new T[size - 1];

        int helpIndex = 0;
        for(int i = 0; i < size - 1; i++)
        {
            if(index == i)
            {
                helpIndex = 1;
            }
            newMas[i] = mas[i + helpIndex];
        }
        mas = newMas;
        delete [] newMas;
        size--;
    }
};
#endif