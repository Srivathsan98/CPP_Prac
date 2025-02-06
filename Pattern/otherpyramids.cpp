#include <iostream>

using namespace std;


void invertedpyramid1(int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            cout << " ";
        }
        for(int j = 0; j < 2*(n-i)-1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void invertedpyramid2(int n)
{
    for (int i = n; i > 0; i--)
    {
        for (int j=i; j > 0; j--)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void trianglepyramid(int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n-i-1; j++)
        {
            cout << " ";
        }
        for(int j = 0; j < 2*i+1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void diamondpyramid(int n)
{
    trianglepyramid(n);
    // invertedpyramid1(n);
    for(int i = 1; i < n ; i++)
    {
        for(int j = 0; j < i; j++)
        {
            cout << " ";
        }
        for(int j = 0; j < 2*(n-i)-1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void hollowpyramid(int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            cout << " ";
        }
        for(int j = 0; j < 2*(n-i)-1; j++)
        {
            if(j == 0 || j == 2*(n-i)-2 || i == 0)
                cout << "*";
            else
                cout << " ";
            // cout << "*";
        }
        cout << endl;
    }
}

void hollowdiamondpyramid(int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n-i-1; j++)
        {
            cout << " ";
        }
        for(int j = 0; j < 2*i+1; j++)
        {
            if(j == 0 || j == 2*i)
                cout << "*";
            else
                cout << " ";
            // cout << "*";
        }
        cout << endl;
    }
    for(int i = 1; i < n ; i++)
    {
        for(int j = 0; j < i; j++)
        {
            cout << " ";
        }
        for(int j = 0; j < 2*(n-i)-1; j++)
        {
            if(j == 0 || j == 2*(n-i)-2)
                cout << "*";
            else
                cout << " ";
            // cout << "*";
        }
        cout << endl;
    }


}

void pascaltriangle(int n)
{
    int coef = 1;
    for(int i = 0; i < n; i++)
    {
        for(int j = 1; j <= n-i; j++)
        {
            cout << " ";
        }
        for(int j = 0; j <= i; j++)
        {
            if(j == 0 || i == 0)
                coef = 1;
            else
                coef = coef * (i-j+1)/j;
            cout << coef << " ";
        }
        cout << endl;
    }
}
int main()
{
    int choice;
    cout << "enter choice: 1. inverted pyramid1" << endl << "2. inverted pyramid2" << endl << "3. triangle pyramid" << endl << "4. diamond pyramid" << endl << "5. hollow pyramid" << endl;
    cout << "6. hollow diamond pyramid" << endl << "7. pascal triangle" << endl;
    cin >> choice;
    if(choice == 1)
    {
        int rows;
        cout << "enter no of rows" << endl;
        cin >> rows;
        invertedpyramid1(rows);
    }
    else if(choice == 2)
    {
        int rows;
        cout << "enter no of rows" << endl;
        cin >> rows;
        invertedpyramid2(rows);
    }
    else if(choice == 3)
    {
        int rows;
        cout << "enter no of rows" << endl;
        cin >> rows;
        trianglepyramid(rows);
    }
    else if(choice == 4)
    {
        int rows;
        cout << "enter no of rows" << endl;
        cin >> rows;
        diamondpyramid(rows);
    }
    else if(choice == 5)
    {
        int rows;
        cout << "enter no of rows" << endl;
        cin >> rows;
        hollowpyramid(rows);
    }
    else if(choice == 6)
    {
        int rows;
        cout << "enter no of rows" << endl;
        cin >> rows;
        hollowdiamondpyramid(rows);
    }
    else if(choice == 7)
    {
        int rows;
        cout << "enter no of rows" << endl;
        cin >> rows;
        pascaltriangle(rows);
    }
    else
    {
        cout << "invalid choice" << endl;
    }
    return 0;
}