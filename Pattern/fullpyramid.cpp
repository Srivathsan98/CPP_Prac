#include <iostream>

using namespace std;

void pattern1(int n)
{
    int counter = 1;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <=i; j++)
        {
            cout << counter << " ";
            counter++;
        }
        cout << endl;
    }
}
void pattern2(int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            cout << i+1 << " ";
        }
        cout << endl;
    }
}
void pattern3(int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j= 0; j <= i; j++)
        {
            cout << j+1;
        }
        cout << endl;
    }
}
int main()
{
    int choice;
    cout << "enter choice: 1. pattern1" << endl << "2. pattern2" << endl << "3. pattern3" << endl;
    cin >> choice;
    if(choice == 1)
    {
        int rows;
        cout << "enter no of rows" << endl;
        cin >> rows;
        pattern1(rows);
    }
    else if(choice == 2)
    {
        int rows;
        cout << "enter no of rows" << endl;
        cin >> rows;
        pattern2(rows);
    }
    else if(choice == 3)
    {
        int rows;
        cout << "enter no of rows" << endl;
        cin >> rows;
        pattern3(rows);
    }
    else
    {
        cout << "invalid choice" << endl;
    }
    return 0;

}