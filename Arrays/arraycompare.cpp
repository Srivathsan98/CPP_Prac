#include <iostream>

using namespace std;

bool arraycompare(int arr1[], int arr2[], int n)
{
    for(int i = 0; i < n; i++)
    {
        if(arr1[i] != arr2[i])
        {
            return false;
        }
    }
    return true;
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
    if(arraycompare(arr1, arr2, n))
    {
        cout << "The arrays are equal" << endl;
    }
    else
    {
        cout << "The arrays are not equal" << endl;
    }
    return 0;
}