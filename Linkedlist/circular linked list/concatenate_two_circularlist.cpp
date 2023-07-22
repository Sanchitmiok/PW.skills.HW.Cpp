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
Node* concatenate(Node *head1, Node *head2)
{
    Node *current1 = head1;//gives current node of first list
    while (current1->next != head1)
    {
        current1 = current1->next;
    }//now current1 points the last node of list 1
    Node *current2 = head2;// give current node of second list
    while (current2->next != head2)
    {
        current2 = current2->next;
    }// now the current2 points the last node of list 2
    current1->next=head2;
    current2->next=head1;
    Node*head=head1;
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
    Circular_list cb;
    cb.Insert_at_tail(5);
    cb.Insert_at_tail(6);
    cb.Insert_at_tail(7);
    cb.Insert_at_tail(8);
    cout << "Second circular list is ->" << endl;
    cb.Display();
    Circular_list cc;
    concatenate(ca.head,cb.head);
    ca.Display();
    cb.Display();


    return 0;
}
