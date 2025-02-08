#include <iostream>
#include <vector>

using namespace std;

void primerange(int x, int y)
{
    int flag = 0;
    for(int i = x; i <= y; i++)
    {
        if(i == 0 || i == 1)
        {
            cout << i << " is not a prime number" << endl;
            continue;
        }
        else
        {
            for(int j = 2; j <=i/2; j++)
            {
                if(i%j == 0)
                {
                    flag = 0;
                    break;
                }
                else
                {
                    flag = 1;
                }
            }
            if(flag == 1)
            {
                cout << i << endl;
            }
        }

    }
}

bool isPrime(int n)
{
    int flag = 0;
    if(n == 0 || n == 1)
    {
        return false;
    }
    else
    {
        for(int i = 2; i <= n/2; i++)
        {
            if(n%i == 0)
            {
                flag = 0;
                break;
            }
            else
            {
                flag = 1;
            }
        }
        if(flag == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

void addPrime(int n)
{
    int sum = 0;
    if(isPrime(n) && isPrime(n-2))
    {
        cout << n << "is a prime number" <<  "and is sum of 2 prime nos : " << n-2 << " + 2" << endl;
    }
    else
    {
        cout << n << "is not a sum of 2 prime number" << endl;
    }
}

int recursionsum(int n)
{
    if(n == 0)
    {
        return 0;
    }
    else if(n == 1)
    {
        return 1;
    }
    else
    {
        return n + recursionsum(n-1);
    }
}

vector<int> multiply(long int n, vector<int> digits) 
{ 
  
    // Initialize carry 
    long int carry = 0; 
  
    // One by one multiply n with 
    // individual digits of res[] 
    for (long int i = 0; i < digits.size(); i++) { 
        long int result  
          = digits[i] * n + carry; 
  
        // Store last digit of 'prod' in res[] 
        digits[i] = result % 10; 
  
        // Put rest in carry 
        carry = result / 10; 
        cout << "carry: " << carry << endl;
        cout << "result: " << result << endl;
        cout << "digits[i]: " << digits[i] << endl;
    } 
  
    // Put carry in res and increase result size 
    while (carry) { 
        digits.push_back(carry % 10); 
        carry = carry / 10; 
        cout << "carry: " << carry << endl;
        cout << "digits: " << digits.size() << endl;
    } 
  
    return digits; 
} 
  
// Function to recursively calculate the 
// factorial of a large number 
vector<int> factorialRecursiveAlgorithm( 
  long int n) 
{ 
    if (n <= 2) { 
        return multiply(n, { 1 }); 
    } 
  
    return multiply( 
      n, factorialRecursiveAlgorithm(n - 1)); 
} 

void stringrecursion(string s, int size)
{
    if(size == 0)
    {
        return;
    }
    cout << s[size-1];
    stringrecursion(s, size-1);
}

int powerrecursion(int n, int m)
{
    if(m == 0)
    {
        return 1;
    }
    else
    {
        return n * powerrecursion(n, m-1);
    }
}
void print()
{
    cout << "Hello World" << endl;
    cout << "wfvihw" << endl;
}

template <typename T, typename... Types>
void print(T var1, Types... var2)
{
    cout << var1 << endl;
    print(var2...);
}
int main()
{
    int choice;
    cout << "Enter your choice: 1.primerange" << endl << "2.isPrime" << endl << "3.addPrime" << endl << "4.recursionsum" << endl << "5.factorialRecursiveAlgorithm" << endl;
    cout << "6.stringrecursion" << endl << "7.powerrecursion" << endl << "8.print" << endl;
    cin >> choice;
    vector<int> result;
    if (choice == 1)
    {
        int x, y;
        cout << "Enter the range: ";
        cin >> x >> y;
        primerange(x, y);
    }
    else if (choice == 2)
    {
        int n;
        cout << "Enter the number: ";
        cin >> n;
        if (isPrime(n))
        {
            cout << n << " is a prime number" << endl;
        }
        else
        {
            cout << n << " is not a prime number" << endl;
        }
    }
    else if (choice == 3)
    {
        int m;
        cout << "Enter the number: ";
        cin >> m;
        addPrime(m);
    }
    else if (choice == 4)
    {
        int o;
        cout << "Enter the number: ";
        cin >> o;
        cout << "Sum of first " << o << " natural numbers is " << recursionsum(o) << endl;
    }
    else if (choice == 5)
    {
        long int p;
        cout << "Enter the number: ";
        cin >> p;
        result = factorialRecursiveAlgorithm(p);
        cout << result.size() << endl;
        for (int i = result.size() - 1; i >= 0; i--) 
        {
            cout << result[i]; 
        }
        cout << endl;
    }
    else if (choice == 6)
    {
        string q;
        cout << "Enter the string: ";
        cin >> q;
        stringrecursion(q, q.size());
        cout << endl;
    }
    else if (choice == 7)
    {
        int r, s;
        cout << "Enter the number and power: ";
        cin >> r >> s;
        cout << r << " raised to the power " << s << " is " << powerrecursion(r, s) << endl;
    }
    else if (choice == 8)
    {
        print("Hello", "World", "How", "are", "you");
    }
    else
    {
        cout << "Invalid choice" << endl;
    }
    return 0;
}