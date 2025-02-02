#include <iostream>

using namespace std;

float farenheitToClecious(float farenheit)
{
    return (farenheit - 32) * 5 / 9;
}
float celciusToFarenheit(float celcius)
{
    return (celcius * 9 / 5) + 32;
}
int main()
{
    int choice;
    cout << "enter what to convert: 1 for farenheit to celcius, 2 for celcius to farenheit" << endl;
    cin >> choice;
    cout << endl;
    float temp;
    if(choice == 1)
    {
        cout << "enter tempreature in farenheit" << endl;
        cin >> temp;
        cout << temp <<" temp in celcius:" << farenheitToClecious(temp) << endl;
        cout << endl;
    }
    else
    {
        cout << "enter tempreature in celcius" << endl;
        cin >> temp;
        cout << temp <<" temp in farenheit:" << celciusToFarenheit(temp) << endl;
        cout << endl;
    }
    return 0;
}