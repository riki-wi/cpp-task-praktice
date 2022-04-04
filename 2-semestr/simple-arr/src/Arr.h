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
    Arr()
    {
        this->size = 0;
        this->mas = new T[size];
    }

    explicit Arr(int size)
    {
        this->size = size;
        this->mas = new T[size];
    }

    Arr(int size, const T& init)
    {
        this->size = size;
        this->mas = new T[size];
        for(int i = 0; i < size; i++)
        {
            mas[i] = init;
        }
    }

    Arr(const Arr& other)
    {
        this->size = other.size;
        this->mas = new T[other.size];

        for(int i = 0; i < other.size; i++)
        {
            this->mas[i] = other.mas[i];
        }
    }

    ~Arr()
    {
        delete [] this->mas;
    }

    T& operator[](int index)
    {
        if(index < 0 || size <= index)
            throw IndexException();
        return mas[index];
    }

    const T& operator[](int index) const
    {
        if(index < 0 || size <= index)
            throw IndexException();
        return mas[index];
    }

    T getElement(int index) const
    {
        if(index < 0 || size <= index)
            throw IndexException();
        return mas[index];
    }

    int getSize() const
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

        int min = size < newSize ?  size : newSize;
        T* newMas = new T[newSize];
        for(int i = 0; i < min; i++)
        {
            newMas[i] = mas[i];
        }
        delete [] mas;
        mas = newMas;
        size = newSize;
    }

    void addElem(const T& elem)
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
        delete [] mas;
        mas = newMas;
        size--;
    }
};
#endif
