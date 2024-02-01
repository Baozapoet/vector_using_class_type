#include <iostream>
#include <initializer_list>
#include <limits.h>
using namespace std;

template <typename T>
class vector
{
private:
    T *data;
    size_t capacity;
    size_t size;

public:
    vector() : data(nullptr), capacity(0), size(0) {}
    vector(size_t initCapacity) : data(new T[initCapacity]), capacity(initCapacity), size(0) {}
    vector(std::initializer_list<T> init_list) : size(init_list.size()), data(new T[size]) {
        size_t i = 0;
        for (const auto& item : init_list) {
            data[i++] = item;
        }
    }
    ~vector() { delete[] data; }
    T& operator[](size_t index)
    {
        return data[index];
    }
    void push_back(const T& x)
    {
        if (data == nullptr)
        {
            capacity = 1;
            data = new T[capacity];
        }
        else
        {
            if (size >= capacity)
            {
                capacity *= 2;
                T* newdata = new T[capacity];
                for (size_t i = 0; i < size; i++)
                {
                    newdata[i] = data[i];
                }
                delete[] data;
                data = newdata;
            }
        }
        data[size++] = x;
    }
    void pop_back()
    {
        if (size > 0)
            size--;
        else
            cout << "Vector is empty \n";
    }
    size_t get_size()
    {
        return size;
    }
    size_t get_capacity()
    {
        return capacity;
    }
    bool isEmpty()
    {
        return size == 0;
    }
    size_t max_size()
    {
        return LONG_MAX * 2;
    }
    T& at(size_t index)
    {
        return data[index];
    }
    void resize(size_t newsize)
    {
        if (newsize >= capacity)
        {
            capacity = newsize + 1;
            T* newdata = new T[capacity];
            for (size_t i = 0; i < size; i++)
            {
                newdata[i] = data[i];
            }
            delete[] data;
            data = newdata;
        }
        else
        {
            if (newsize > size)
            {
                for (size_t i = size; i < newsize; i++)
                {
                    data[i] = 0;
                }
            }
        }
        size = newsize;
    }
    void insert(size_t index, T x)
    {
        if (index > size) return;
        if (size == capacity)
        {
            capacity += 1;
        }
        for (size_t i = size; i > index; i--)
        {
            data[i] = data[i-1]; 
        }
        size += 1;
        data[index] = x;
    }
    void erase(size_t index)
    {
        for (size_t i = index; i < size; i++)
        {
            data[i] = data[i+1];
        }
        
        size -= 1;
    }
};

int main()
{
    vector<int> a = {1,2,3,4,5};
    for (size_t i = 0; i < a.get_size(); i++)
    {
        cout << a[i] << " ";
    }
    a.push_back(1.1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4.4);
    a.insert(1,7);
    for (size_t i = 0; i < a.get_size(); i++)
    {
        cout << a[i] << " ";
    }
    cout<<endl;
    a.erase(3);
    for (size_t i = 0; i < a.get_size(); i++)
    {
        cout << a[i] << " ";
    }
    cout<<endl;
    return 0;
}