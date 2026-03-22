/*Build a simple observer pattern: one Subject, multiple Observers held via shared_ptr. Subject notifies all. Observers auto-cleanup.*/

#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
class Observer
{
public:
    virtual ~Observer() = default;
    virtual void update(const std::string& message) = 0;
};

class Subject
{
private:
    std::vector<std::weak_ptr<Observer>> observers;
public:
    void attach(std::weak_ptr<Observer> observer)
    {
        observers.push_back(observer);
    }

    void detach(std::weak_ptr<Observer> observer)
    {
        observers.erase(std::remove_if(observers.begin(), observers.end(), [&observer](const std::weak_ptr<Observer>& o)
        {
            return o.lock() == observer.lock();
        }), observers.end());
    }

    void notify(const std::string& message)
    {
        observers.erase(std::remove_if(observers.begin(), observers.end(), [](const std::weak_ptr<Observer>& wkptr)
        {
            return wkptr.expired();
        }), observers.end());

        for(const auto& weakObserver : observers)
        {
            if(auto observer = weakObserver.lock())
            {
                observer->update(message);
            }
        }
    }
};

class ConcreteObserver : public Observer
{
private:
    std::string name;
public:
    ConcreteObserver(const std::string& name) : name(name)
    {
    }

    void update(const std::string& message) override
    {
        std::cout << name << " received message: " << message << std::endl;
    }

    ~ConcreteObserver()
    {
        std::cout << name << " is being destroyed." << std::endl;
    }   
};

int main()
{
    Subject subject;

    std::shared_ptr<Observer> observer1 = std::make_shared<ConcreteObserver>("Observer 1");
    std::shared_ptr<Observer> observer2 = std::make_shared<ConcreteObserver>("Observer2");
    std::shared_ptr<Observer> observer3 = std::make_shared<ConcreteObserver>("Observer3");
    std::shared_ptr<Observer> observer4 = std::make_shared<ConcreteObserver>("Observer4");

    subject.attach(observer1);
    subject.attach(observer2);
    subject.attach(observer3);

    subject.notify("1st notification");

    std::cout << "Resetting observer1..." << std::endl;
    observer1.reset();

    subject.notify("2nd notification");

    std::cout << "detaching observer2..." << std::endl;
    subject.detach(observer2);

    subject.notify("3rd notification");

    subject.attach(observer4);
    subject.notify("4th notification");

    observer2.reset();
    subject.notify("5th notification");

    std::cout << "Main function is ending..." << std::endl;
    return 0;
}