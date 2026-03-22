/*linked list with insert, delete, reverse — using smart pointers*/
#include <iostream>
#include <memory>
template<typename T>
struct Node
{
    T data;
    std::unique_ptr<Node<T>> next;

    Node(T value): data(value), next(nullptr) {}
};

template<typename T>
class LinkedList
{
private:
    std::unique_ptr<Node<T>> head;
public:
void insertNode(T value)
{
    auto newNode = std::make_unique<Node<T>>(value);
    if(!head)
    {
        head = std::move(newNode);
        return;
    }
    Node<T>* current = head.get();
    while(current->next)
    {
        current = current->next.get();
    }
    current->next = std::move(newNode);
}

void deleteByValue(T value)
{
    if(!head)
    {
        return;
    }
    if(head->data == value)
    {
        std::unique_ptr<Node<T>> temp = std::move(head);
        head = std::move(temp->next);
        return;
    }
    Node<T>* current = head.get();
    while(current->next && current->next->data != value)
    {
        current = current->next.get();
    }

    if(current->next)
    {
        std::unique_ptr<Node<T>> temp = std::move(current->next);
        current->next = std::move(temp->next);
    }
}

void reverseNode()
{
    std::unique_ptr<Node<T>> previous = nullptr;
    std::unique_ptr<Node<T>> current = std::move(head);

    while(current)
    {
        Node<T>* next_raw = current->next.release();
        current->next = std::move(previous);
        previous = std::move(current);
        current.reset(next_raw);
    }
    head = std::move(previous);
}

void displayNode() const
{
    Node<T>* current = head.get();
    while(current)
    {
        std::cout << current->data << (current->next ? "->" : "");
        current = current->next.get();
    }
    std::cout << std::endl;
}
};
int main()
{
    LinkedList<int> list;
    list.insertNode(1);
    list.insertNode(2);
    list.insertNode(3);
    list.insertNode(4);

    std::cout << "Original list: ";
    list.displayNode();

    list.deleteByValue(2);
    std::cout << "After deleting 2: ";
    list.displayNode();

    list.reverseNode();
    std::cout << "After reversing: ";
    list.displayNode();

    return 0;
}