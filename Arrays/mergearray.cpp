#include <iostream>
#include <algorithm>

using namespace std;

void mergearray(int arr1[], int arr2[], int n)
{
    int arr3[2*n];
    for(int i = 0; i < n; i++)
    {
        arr3[i] = arr1[i];
    }
    for(int i = 0; i < n; i++)
    {
        arr3[n+i] = arr2[i];
    }
    sort(arr3, arr3+2*n);
    for(int i = 0; i < 2*n; i++)
    {
        cout << arr3[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the size of the arrays: ";
    cin >> n;
    int arr1[n], arr2[n];
    cout << "Enter the elements of the first array: ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    cout << "Enter the elements of the second array: ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr2[i];
    }
    mergearray(arr1, arr2, n);
    return 0;
}