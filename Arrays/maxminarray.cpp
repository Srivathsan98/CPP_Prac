#include <iostream>

using namespace std;

std::pair<int, int> maxminarray(int arr[], int n)
{
    int max, min;
    max = arr[0];
    min = arr[0];
    for(int i = 0; i < n; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
        if(arr[i] < min)
        {
            min = arr[i];
        }
    }
    return {max, min};
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
    std::pair<int, int> result = maxminarray(arr, n);
    cout << "The maximum element of the array is: " << result.first << endl;
    cout << "The minimum element of the array is: " << result.second << endl;
    return 0;
}