#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int choice;
    cout << "enter what to calculate: 1 for simple interest, 2 for compound interest" << endl;
    cin >> choice;
    cout << endl;
    if(choice == 1)
    {
        float principal, rate, time;
        cout << "enter principal" << endl;
        cin >> principal;
        cout << "enter rate" << endl;
        cin >> rate;
        cout << "enter time" << endl;
        cin >> time;
        cout << "simple interest:" << (principal * rate * time) / 100 << endl;
        cout << "total amount:" << principal + (principal * rate * time) / 100 << endl;
    }
    else
    {
        float principal, rate, time;
        cout << "enter principal" << endl;
        cin >> principal;
        cout << "enter rate" << endl;
        cin >> rate;
        cout << "enter time" << endl;
        cin >> time;
        cout << "compound interest:" << principal * (pow((1 + rate / 100), time) - 1) << endl;
        cout << "total amount:" << principal * pow((1 + rate / 100), time) << endl;
    }
    return 0;
}