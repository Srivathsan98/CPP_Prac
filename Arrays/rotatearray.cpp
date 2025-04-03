#include <iostream>
#include <algorithm>

using namespace std;

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
    int d;
    cout << "Enter the number of positions to rotate: ";
    cin >> d;
    d = d % n; // To handle cases where d > n
    rotate(arr, arr + d, arr + n); // Rotate the array
    cout << "The rotated array is: ";
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    // reverse(arr, arr + n); // Reverse the entire array
    // cout << "The reversed1 array is: ";
    // for(int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    // reverse(arr, arr + d); // Reverse the first d elements
    // cout << "The reversed2 array is: ";
    // for(int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    // reverse(arr + d, arr + n); // Reverse the remaining n - d elements
    // cout << "The rotated array is: ";
    // for(int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    return 0;
}