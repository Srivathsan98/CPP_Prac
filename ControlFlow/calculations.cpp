#include <iostream>
#include <cmath>

using namespace std;

int evenOdd(int num)
{
    if(num % 2 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int largest(int arr[], int n)
{
    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if(arr[i] > max)
            max = arr[i];
        
    }
    return max;
}
int vowel(char c)
{
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int leapyear(int year)
{
    if(year % 4 == 0)
    {
        if(year % 100 == 0)
        {
            if(year % 400 == 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return 0;
    }
}

int factorial(int num)
{
    if(num == 0)
    {
        return 1;
    }
    else
    {
        return num * factorial(num - 1);
    }
}

int reversenum(int num)
{
    int rev = 0;
    while(num != 0)
    {
        rev = rev * 10 + num % 10;
        cout << rev << endl;
        num = num / 10;
        cout << num << endl;
    }
    return rev;
}
int gcd(int a, int b)
{
    if(b == 0)
    {
        return a;
    }
    else
    {
        cout << endl;
        cout << a << " " << b << endl;
        cout << endl;
        return gcd(b, a % b);
        
    }
}
int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}
int palindrome(int num)
{
    int rev = reversenum(num);
    if(rev == num)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int prime(int n)
{
    if(n == 1)
    {
        return 0;
    }
    if(n == 2 || n == 3)
    {
        return 1;
    }
    for (int i = 2; i <= n/2; i++)
    {
        if((n % i) == 0)
        {
            return 0;
        }
    }
    return 1; 
}
void primeinterval(int a, int b)
{
    if(a > b)
    {
        cout << "invalid interval" << endl;
        return;
    }
    for (int i = a; i <= b; i++)
    {
        if(prime(i))
        {
            cout << i << " ";
        }
    }
    cout << endl;
}
int neonnum(int n)
{
    int sq = n * n;
    int sum = 0;
    while(sq != 0)
    {
        sum = sum + sq % 10;
        sq = sq / 10;
    }
    if(sum == n)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int armstrong(int n)
{
    int sum = 0;
    int temp = n;
    int size = log10(n) + 1;
    while(n != 0)
    {

        sum = sum + pow(n%10, size);
        n = n / 10;
    }
    if(sum == temp)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void armstronginterval(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if(armstrong(i))
        {
            cout << i << " ";
        }
    }
    cout << endl;
}
int fibonacci(int n)
{
    if(n == 0)
    {
        return 0;
    }
    if(n == 1)
    {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int fibonaccisum(int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + fibonacci(i);
    }
    return sum;
}

void divisors(int n)
{
    for (int i = 1; i <=n; i++)
    {
        if(n % i == 0)
        {
            cout << i << " ";
        }
    }
}

void calculation(int a, int b)
{
    cout << "enter type of operation to do: 1.addition" << endl << "2.subtraction" << endl << "3.multiplication" << endl << "4.division" << endl;
    int choice;
    cin >> choice;
    if(choice == 1)
    {
        cout << "addition:" << a + b << endl;
    }
    else if(choice == 2)
    {
        cout << "subtraction:" << a - b << endl;
    }
    else if(choice == 3)
    {
        cout << "multiplication:" << a * b << endl;
    }
    else if(choice == 4)
    {
        cout << "division:" << a / b << endl;
    }
    else
    {
        cout << "invalid choice" << endl;
    }
}
int main()
{
    int choice;
    cout << "enter what to calculate: 1.odd/even" << endl << "2.largest number" << endl << "3.vowel/consonant" << endl << "4.leap year" << endl << "5. factorial" << endl;
    cout << "6. reverse number" << endl << "7. gcd" << endl << "8. lcm" << endl << "9. palindrome" << endl << "10. prime" << endl << "11. prime interval" << endl;
    cout << "12. neon number" << endl << "13. armstrong number" << endl << "14. armstrong interval" << endl << "15. fibonacci" << endl << "16. fibonacci sum" << endl << "17. divisors" << endl;
    cout << "18. calculations" << endl;
    cin >> choice;
    cout << endl;

    if(choice == 1)
    {
        int num;
        cout << "enter number" << endl;
        cin >> num;
        if(evenOdd(num))
        {
            cout << num << " is even" << endl;
        }
        else
        {
            cout << num << " is odd" << endl;
        }
    }
    else if(choice ==2)
    {
        cout << "enter no of elements" << endl;
        int n;
        cin >> n;
        cout << "enter elements" << endl;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }   
        cout << "largest number:" << largest(arr, n) << endl;
    }
    else if(choice == 3)
    {
        char c;
        cout << "enter character" << endl;
        cin >> c;
        if(vowel(c))
        {
            cout << c << " is vowel" << endl;
        }
        else
        {
            cout << c << " is consonant" << endl;
        }
    }
    else if(choice == 4)
    {
        int year;
        cout << "enter year" << endl;
        cin >> year;
        if(leapyear(year))
        {
            cout << year << " is leap year" << endl;
        }
        else
        {
            cout << year << " is not leap year" << endl;
        }
    }
    else if(choice == 5)
    {
        int num;
        cout << "enter number" << endl;
        cin >> num;
        cout << "factorial of " << num << " is " << factorial(num) << endl;
    }
    else if(choice == 6)
    {
        int num;
        cout << "enter number" << endl;
        cin >> num;
        cout << "reverse of " << num << " is " << reversenum(num) << endl;
    }
    else if(choice == 7)
    {
        int a, b;
        cout << "enter two numbers" << endl;
        cin >> a >> b;
        cout << "gcd of " << a << " and " << b << " is " << gcd(a, b) << endl;
    }
    else if(choice == 8)
    {
        int a, b;
        cout << "enter two numbers" << endl;
        cin >> a >> b;
        cout << "lcm of " << a << " and " << b << " is " << lcm(a, b) << endl;
    }
    else if(choice == 9)
    {
        int num;
        cout << "enter number" << endl;
        cin >> num;
        if(palindrome(num))
        {
            cout << num << " is palindrome" << endl;
        }
        else
        {
            cout << num << " is not palindrome" << endl;
        }
    }
    else if(choice == 10)
    {
        int num;
        cout << "enter number" << endl;
        cin >> num;
        if(prime(num))
        {
            cout << num << " is prime" << endl;
        }
        else
        {
            cout << num << " is not prime" << endl;
        }
    }
    else if(choice == 11)
    {
        int a, b;
        cout << "enter two numbers" << endl;
        cin >> a >> b;
        primeinterval(a, b);
    }
    else if(choice == 12)
    {
        int num;
        cout << "enter number" << endl;
        cin >> num;
        if(neonnum(num))
        {
            cout << num << " is neon number" << endl;
        }
        else
        {
            cout << num << " is not neon number" << endl;
        }
    }
    else if(choice == 13)
    {
        int num;
        cout << "enter number" << endl;
        cin >> num;
        if(armstrong(num))
        {
            cout << num << " is armstrong number" << endl;
        }
        else
        {
            cout << num << " is not armstrong number" << endl;
        }
    }
    else if(choice == 14)
    {
        int n;
        cout << "enter number" << endl;
        cin >> n;
        armstronginterval(n);
    }
    else if(choice == 15)
    {
        int n;
        cout << "enter number" << endl;
        cin >> n;
        cout << "fibonacci series:" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << fibonacci(i) << " ";
        }
        cout << endl;
    }
    else if(choice == 16)
    {
        int n;
        cout << "enter number" << endl;
        cin >> n;
        cout << "sum of fibonacci series:" << fibonaccisum(n) << endl;
    }
    else if(choice == 17)
    {
        int n;
        cout << "enter number" << endl;
        cin >> n;
        cout << "divisors of " << n << " are:" << endl;
        divisors(n);
        cout << endl;
    }
    else if(choice == 18)
    {
        int a, b;
        cout << "enter two numbers" << endl;
        cin >> a >> b;
        calculation(a, b);
    }
    else
    {
        cout << "invalid choice" << endl;
    }
    return 0;
}