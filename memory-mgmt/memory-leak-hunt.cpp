/*doouble delete, missing delete, dangling and functions to fix them*/
#include <iostream>


void danglingpointer()
{
    int* ptr = new int(5);
    std::cout << "value is " << *ptr << std::endl;
    delete ptr;
    std::cout << "value post delete is " << *ptr << std::endl;    
}
void missingdelete()
{
    int* ptr = new int(10);
    std::cout << "value is " << *ptr << std::endl;
    int* arr = new int[5]{10, 20, 30, 40, 50};
    std::cout << "[Missing delete[]] arr[0]: " << arr[0] << "\n";
}
void doubledelete()
{
    int* pre = new int (15);
    std::cout << "value is " << *pre << std::endl;
    delete pre;

    std::cout << "value in double delete is " << *pre << std::endl;
    delete pre;
}

void fixdanglingpointer()
{
    int* ptr = new int(20);
    std::cout << "value is " << *ptr << std::endl;
    delete ptr;
    ptr = nullptr;
    if(ptr)
    {
        std::cout << "value post delete is " << *ptr << std::endl;    
    }
    else
    {
        std::cout << "pointer is null, cannot dereference" << std::endl;
    }
}

void fixmissingdelete()
{
    int* ptr = new int(25);
    std::cout << "value is " << *ptr << std::endl;
    delete ptr;
    ptr = nullptr;
    int* arr = new int[5]{10, 20, 30, 40, 50};
    std::cout << "[Fix delete[]] arr[0]: " << arr[0] << "\n";
    delete[] arr;
    arr = nullptr;
}
void fixdoubledelete()
{
    int* pre = new int (30);
    std::cout << "value is " << *pre << std::endl;
    delete pre;
    pre = nullptr;

    if(pre)
    {
        std::cout << "value in double delete is " << *pre << std::endl;
        delete pre;
    }
    else
    {
        std::cout << "pointer is null, cannot dereference or delete" << std::endl;
    }
}
int main()
{
    // std::cout << "Dangling pointer example: " << std::endl;
    // danglingpointer();

    // std::cout << "Missing delete example: " << std::endl;
    // missingdelete();

    // std::cout << "Double delete example: " << std::endl;
    // doubledelete();

    std::cout << "Fixing dangling pointer example: " << std::endl;
    fixdanglingpointer();

    std::cout << "Fixing missing delete example: " << std::endl;
    fixmissingdelete();

    std::cout << "Fixing double delete example: " << std::endl;
    fixdoubledelete();

    return 0;
}