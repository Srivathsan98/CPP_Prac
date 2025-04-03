#include <iostream>
#include <algorithm>
using namespace std;


void findduplicates(int arr[], int n)
{
    cout << "The duplicate elements in the array are: ";
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == arr[i+1])
        {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

void removeduplicates(int arr[], int n)
{
    int arr2[n];
    for(int i = 0; i < n; i++)
    {
        if(arr[i] != arr[i+1])
        {
            arr2[i] = arr[i];
        }
        else
        {
            arr2[i] = 0;
        }
    }
    cout << "The array after removing duplicates is: ";
    for(int i = 0; i < n; i++)
    {
        if(arr2[i] != 0)
        {
            cout << arr2[i] << " ";
        }
    }
    cout << endl;
}

void removeoccurence(int arr[], int n, int x)
{
    int arr2[n];
    for(int i = 0; i < n; i++)
    {
        if(arr[i] != x)
        {
            arr2[i] = arr[i];
        }
        else
        {
            arr2[i] = 0;
        }
    }
    cout << "The array after removing " << x << " is: ";
    for(int i = 0; i < n; i++)
    {
        if(arr2[i] != 0)
        {
            cout << arr2[i] << " ";
        }
    }
    cout << endl;
}
int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    cout << "The sorted array is: ";
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    findduplicates(arr, n);
    removeduplicates(arr, n);
    int x;
    cout << "Enter the element to remove: ";
    cin >> x;
    removeoccurence(arr, n, x);
    return 0;
}