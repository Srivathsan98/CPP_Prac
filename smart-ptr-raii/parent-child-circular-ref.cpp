/*Create a parent/child tree that has a circular ref causing a leak*/
#include <iostream>
#include <memory>
#include <vector>

class Child;
class Parent
{
public:
    std::shared_ptr<Child> children;
    Parent()
    {
        std::cout << "Parent created" << std::endl;
    }
    ~Parent()
    {
        std::cout << "Parent destroyed" << std::endl;
    }
};

class Child
{
    public:
    // std::shared_ptr<Parent> parent;
    std::weak_ptr<Parent> parent;
    Child()
    {
        std::cout << "Child created" << std::endl;
    }
    ~Child()
    {
        std::cout << "Child destroyed" << std::endl;
    }
};

void create_leak()
{
    std::shared_ptr<Parent> p = std::make_shared<Parent>();
    std::shared_ptr<Child> c = std::make_shared<Child>();

    p->children = c;
    c->parent = p;
}
int main()
{
    // auto p = std::make_shared<Parent>();
    // auto c = std::make_shared<Child>();

    // p->children.push_back(c);
    // c->parent = p;

    std::cout << "Creating leak..." << std::endl;
    create_leak();
    std::cout << "Exiting main..." << std::endl;

    return 0;
}
