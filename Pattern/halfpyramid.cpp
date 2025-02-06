#include <iostream>

using namespace std;

void righthalfpyramid(int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <=i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void lefthalfpyramid(int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            if(j < n - i)
            {
                cout << " ";
            }
            else
            {
                cout << "*";
            }
        }
        cout << endl;
    }
}
int main()
{
    int choice;
    cout << "enter choice: 1. right half pyramid" << endl << "2. left half pyramid" << endl;
    cin >> choice;
    if(choice == 1)
    {
        int rows;
        cout << "enter no of rows" << endl;
        cin >> rows;
        righthalfpyramid(rows);
    }
    else if(choice == 2)
    {
        int rows;
        cout << "enter no of rows" << endl;
        cin >> rows;
        lefthalfpyramid(rows);
    }
    else
    {
        cout << "invalid choice" << endl;
    }
    return 0;
}