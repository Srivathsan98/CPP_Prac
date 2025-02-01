#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
int count = 0;

/*
this is a recursion function
so first we pass string to the function
then we take out the first occuring character in the string and then do a recursion on all the other characters till end
so for example
string = abcd
intially prefix is empty. then we perform the substr function and start spliutting the prefix and remaining string
so now remaining is bcd and prefix is a
then remaining is performed a recursion now
prefix is b and remaining is cd
then c is prefix and remaining is d
then there is no prefix so string is abcd
now next
it will take d and remaining is c so abdc
then go a step back and take c for prefix this gives ac as prefix and bd as rem
this gives acbd and acdb
*/
void printCombinations(string str, string prefix)
{
    cout << "String: " << str << " Prefix: " << prefix << endl;
    if(str.length() == 0)
    {
        cout << prefix << endl;
    }
    else
    {
        for(int i = 0; i < str.length(); i++)
        {
            string rem = str.substr(0, i) + str.substr(i + 1);
            cout << "Rem: " << rem << endl;
            printCombinations(rem, prefix + str[i]);
        }
        count++;
        cout << "Count: " << count << endl;
    }
    
}

int main()
{
    // string myGraphJson = "{\"kind\":{\"graph\":true},"
    //     "\"nodes\":[{\"id\":\"1\"},{\"id\":\"2\"}],"
    //     "\"edges\":[{\"from\":\"1\",\"to\":\"2\"}]}";
    // cout << myGraphJson;
    string str;
    cout << endl;
    cout << "Enter a string: ";
    cin >> str;
    printCombinations(str, "");
    return 0;
}

/*flow
printCombinations("abcd", "")
│
├── Take 'a' → Remaining "bcd"
│   ├── Take 'b' → Remaining "cd"
│   │   ├── Take 'c' → Remaining "d"
│   │   │   ├── Take 'd' → Remaining ""
│   │   │   │   ├── Print "abcd"
│   │   │   ├── Take 'd' → Remaining "c"
│   │   │   │   ├── Print "abdc"
│   │
│   ├── Take 'c' → Remaining "bd"
│   │   ├── Take 'b' → Remaining "d"
│   │   │   ├── Take 'd' → Remaining ""
│   │   │   │   ├── Print "acbd"
│   │   │   ├── Take 'd' → Remaining "b"
│   │   │   │   ├── Print "acdb"
│   │
│   ├── Take 'd' → Remaining "bc"
│   │   ├── Take 'b' → Remaining "c"
│   │   │   ├── Take 'c' → Remaining ""
│   │   │   │   ├── Print "adbc"
│   │   ├── Take 'c' → Remaining "b"
│   │   │   ├── Take 'b' → Remaining ""
│   │   │   │   ├── Print "adcb"
│
├── Take 'b' → Remaining "acd"
│   ├── Take 'a' → Remaining "cd"
│   │   ├── Take 'c' → Remaining "d"
│   │   │   ├── Take 'd' → Remaining ""
│   │   │   │   ├── Print "bacd"
│   │   │   ├── Take 'd' → Remaining "c"
│   │   │   │   ├── Print "badc"
│   │
│   ├── Take 'c' → Remaining "ad"
│   │   ├── Take 'a' → Remaining "d"
│   │   │   ├── Take 'd' → Remaining ""
│   │   │   │   ├── Print "bcad"
│   │   ├── Take 'd' → Remaining "a"
│   │   │   ├── Take 'a' → Remaining ""
│   │   │   │   ├── Print "bcda"
│
├── Take 'c' → Remaining "abd"
│   ├── Take 'a' → Remaining "bd"
│   │   ├── Take 'b' → Remaining "d"
│   │   │   ├── Take 'd' → Remaining ""
│   │   │   │   ├── Print "cabd"
│   │   ├── Take 'd' → Remaining "b"
│   │   │   ├── Take 'b' → Remaining ""
│   │   │   │   ├── Print "cadb"
│
├── Take 'd' → Remaining "abc"
│   ├── Take 'a' → Remaining "bc"
│   │   ├── Take 'b' → Remaining "c"
│   │   │   ├── Take 'c' → Remaining ""
│   │   │   │   ├── Print "dabc"
│   │   ├── Take 'c' → Remaining "b"
│   │   │   ├── Take 'b' → Remaining ""
│   │   │   │   ├── Print "dacb"
│   ├── Take 'b' → Remaining "ac"
│   │   ├── Take 'a' → Remaining "c"
│   │   │   ├── Take 'c' → Remaining ""
│   │   │   │   ├── Print "dbac"
│   │   ├── Take 'c' → Remaining "a"
│   │   │   ├── Take 'a' → Remaining ""
│   │   │   │   ├── Print "dbca"
*/