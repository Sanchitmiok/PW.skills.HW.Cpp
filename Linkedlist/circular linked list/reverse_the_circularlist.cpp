#include <iostream>
using namespace std;
class Node
{
public:
    int value;
    Node *next;
    Node(int val)
    {
        value = val;
        next = nullptr;
    }
};
class Circular_list
{
public:
    Node *head;
    Circular_list()
    {
        head = nullptr;
    }
    void Insert_at_head(int val)
    {
        Node *new_node = new Node(val);
        if (head == nullptr)
        {
            head = new_node;
            head->next = head;
        }
        else
        {
            // when their is at least on node
            Node *tail = head;
            while (tail->next != head)
            {
                tail = tail->next;
            }
            new_node->next = head;
            tail->next = new_node;
            head = new_node;
        }
    }
    void Insert_at_tail(int val)
    {
        Node *new_node = new Node(val);
        if (head == nullptr)
        {
            head = new_node;
            head->next = head;
        }
        else
        {
            Node *tail = head;
            while (tail->next != head)
            {
                tail = tail->next;
            } // we are pointing the last node of list
            tail->next = new_node;
            new_node->next = head;
            tail = new_node;
        }
    }
    void Display()
    {
        if (head == nullptr)
            return;
        Node *tail = head; // 1 2 3 4 1
        do
        {
            cout << tail->value << "->";
            tail = tail->next;
        } while (tail != head);
        cout << tail->value << endl;
    }
};
Node* reverse(Node* &head) {
    if (head == nullptr)
        return nullptr;

    Node* current = head;
    Node* prev = nullptr;
    Node* next = nullptr;

    do {
        next = current->next;    // Store the next node
        current->next = prev;    // Reverse the 'next' pointer
        prev = current;          // Move 'prev' one step forward
        current = next;          // Move 'current' one step forward
    } while (current != head);

    head = prev;    // Update the new head of the reversed list
    return head;
}

int main()
{
    Circular_list ca;
    ca.Insert_at_tail(1);
    ca.Insert_at_tail(2);
    ca.Insert_at_tail(3);
    ca.Insert_at_tail(4);
    cout << "First circular list is ->" << endl;
    ca.Display();
    ca.head=reverse(ca.head);
    cout<<"After reversing "<<endl;
    ca.Display();

    return 0;
}
