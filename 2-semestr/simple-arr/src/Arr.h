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
    Arr(): size(0), mas(new T[0]){}

    explicit Arr(int size): size(size), mas(new T[size]){}

    Arr(int size, const T& init): size(size), mas(new T[size])
    {
        for(int i = 0; i < size; i++)
        {
            mas[i] = init;
        }
    }

    Arr(const Arr& other): size(other.size), mas(new T[other.size])
    {
        for(int i = 0; i < other.size; i++)
        {
            this->mas[i] = other.mas[i];
        }
    }

    Arr(Arr&& other) noexcept: mas(other.mas), size(other.size)
    {
        other.mas = nullptr;
        other.size = 0;
    }

    ~Arr()
    {
        if(mas != nullptr)
        {
            delete [] mas;
        }
    }

    Arr& operator=(const Arr& other)
    {
        if(this != &other)
        {
            if(mas != nullptr)
            {
                delete[] mas;
            }
            size = other.size;
            mas = new T[size];
            for(int i = 0; i < other.size; i++)
            {
                this->mas[i] = other.mas[i];
            }
        }
        return *this;
    }

    Arr& operator=(Arr&& other) noexcept
    {
        if (this != &other)
        {
            if(mas != nullptr)
            {
                delete[] mas;
            }
            mas = other.mas;
            size = other.size;
            other.mas = nullptr;
            other.size = 0;
        }
        return *this;
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

    [[nodiscard]] int getSize() const
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
