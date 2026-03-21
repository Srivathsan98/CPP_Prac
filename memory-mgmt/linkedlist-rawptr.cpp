/*linked list with insert, delete, reverse — using raw pointers only. No smart pointers*/
#include <iostream>

struct Node
{
    int data;
    Node* next;
};
void insertNode(Node*& head, int data)
{
    Node* newNode = new Node{data, head};
    head = newNode;
}

void deleteNode(Node*& head, int data)
{
    Node* current = head;
    Node* previous = nullptr;

    if(current != nullptr && current->data == data)
    {
        head = current->next;
        delete current;
        return;
    }
    while(current != nullptr && current->data != data)
    {
        previous = current;
        current = current->next;
    }

    if(current == nullptr)
    {
        return;
    }

    previous->next = current->next;
    delete current;
}

void reverseNode(Node*& head)
{
    Node* previous = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while(current != nullptr)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    head = previous;
}

void displayNode(Node* head)
{
    Node* temp = head;
    while(temp != nullptr)
    {
        std::cout << temp->data << "-> ";
        temp = temp->next;
    }
    std::cout << "nullptr" << std::endl;
}
int main()
{
    Node* head = nullptr;

    insertNode(head, 10);
    insertNode(head, 20);
    insertNode(head, 30);
    insertNode(head, 40);

    std::cout << "Original List: ";
    displayNode(head);

    deleteNode(head, 20);
    std::cout << "After Deletion: ";
    displayNode(head);

    reverseNode(head);
    std::cout << "After Reversal: ";
    displayNode(head);

    Node* current = head;
    while(current != nullptr)
    {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;

    return 0;

}