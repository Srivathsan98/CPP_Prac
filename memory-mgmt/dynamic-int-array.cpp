/*No std::vector. Implement push_back, pop_back, resize (double capacity), operator[], destructor. Must manually new/delete.
create a class with constructor and destructor. constructor does new and destructor delete.
give a default size and if ther is a new entry detected and greater than size then resize automatically to 2x
push elements into array using pushback and pop out the element using pop back*/
#include <iostream>

class DynamicIntArray
{
public:
    DynamicIntArray()
    {
        size = 0;
        capacity = 4;
        arr = new int[capacity];
    }
    ~DynamicIntArray()
    {
        delete[] arr;
    }
    void push_back(int value)
    {
        if(size >= capacity)
        {
            resize();
        }
        arr[size] = value;
        size++;
    }
    void pop_back()
    {
        if(size > 0)
        {
            size--;
        }
    }
    void resize()
    {
        capacity *= 2;
        int* arr2 = new int[capacity];
        for(int i = 0; i < size; i++)
        {
            arr2[i] = arr[i];
        }
        delete[] arr;
        arr = arr2;
    }
    int arrsize()
    {
        return size;
    }
    int& operator[](int index)
    {
        if(index >= 0 && index < size)
        {
            return arr[index];
        }
        else
        {
            throw std::out_of_range("index out of range");
        }
    }
private:
    int* arr;
    int size;
    int capacity;
};  
int main()
{
    DynamicIntArray dyintarr;

    dyintarr.push_back(1);
    dyintarr.push_back(2);
    dyintarr.push_back(3);
    dyintarr.push_back(4);

    std::cout << "Size: " << dyintarr.arrsize() << std::endl;
    for(int i = 0; i < dyintarr.arrsize(); i++)
    {
        std::cout << "Element at" << i << "is" << dyintarr[i] << " " << std::endl;
    }
    dyintarr.pop_back();
    std::cout << "Size: " << dyintarr.arrsize() << "after pop" << std::endl;
    for(int i = 0; i < dyintarr.arrsize(); i++)
    {
        std::cout << "Element at" << i << "is" << dyintarr[i] << " " << std::endl;
    }

    dyintarr.push_back(5);
    std::cout << "Size: " << dyintarr.arrsize() << "after push" << std::endl;
    for(int i = 0; i < dyintarr.arrsize(); i++)
    {
        std::cout << "Element at" << i << "is" << dyintarr[i] << " " << std::endl;
    }
    dyintarr.push_back(6);
    std::cout << "Size: " << dyintarr.arrsize() << "after push" << std::endl;
    for(int i = 0; i < dyintarr.arrsize(); i++)
    {
        std::cout << "Element at" << i << "is" << dyintarr[i] << " " << std::endl;
    }
    dyintarr[2] = 10;
    std::cout << "Size: " << dyintarr.arrsize() << "after push" << std::endl;
    for(int i = 0; i < dyintarr.arrsize(); i++)
    {
        std::cout << "Element at" << i << "is" << dyintarr[i] << " " << std::endl;
    }
    return 0;
}