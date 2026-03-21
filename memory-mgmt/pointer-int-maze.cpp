#include <iostream>


int findsum(int* arr, int size)
{
    int sum = 0;
    std::cout << "Address of arr: " << arr << std::endl;
    std::cout << "Value at arr: " << *arr << std::endl;
    for(int i = 0; i < size; i++)
    {
        // sum += arr[i];
        sum += *(arr + i);
    }
    return sum;
}

int maxval(int* arr, int size)
{
    // int max = arr[0];
    int max = *arr;
    // for(int i = 1; i < size; i++)
    // {
    //     if(arr[i] > max)
    //     {
    //         max = arr[i];
    //     }
    // }
    for(int i = 1; i < size; i++)
    {
        if(*(arr + i) > max)
        {
            max = *(arr + i);
        }
    }
    return max;
}
void reversalarray(int* arr, int size)
{
    // for(int i = 0; i < size / 2; i++)
    // {
    //     int temp = arr[i];
    //     arr[i] = arr[size - i - 1];
    //     arr[size - i - 1] = temp;
    // }
    int* left = arr;
    int* right = arr + size - 1;
    while(left < right)
    {
        int temp = *left;
        *left = *right;
        *right = temp;
        left++;
        right--;
    }
}
int main()
{
    int a[10] = {1,2,3,46,5,6,7,8,9,10};
    int size = 10;

    int* ptr = a;

    int sum = findsum(ptr, size);
    int max = maxval(ptr, size);
    reversalarray(ptr, size);

    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Max: " << max << std::endl;
    std::cout << "Reversed array: ";
    // for(int i = 0; i < size; i++)
    // {
    //     std::cout << ptr[i] << " ";
    // }
    for(int* p = ptr; p < ptr + 10; p++)
        std::cout << *p << " ";
    std::cout << std::endl;
    return 0;

}