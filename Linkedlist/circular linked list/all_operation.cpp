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
    void Insert_after_value(int search, int val)
    {
        Node *new_node = new Node(val);
        if (head == nullptr)
            return;
        else
        {
            Node *current = head;
            while (current->value != search)
            {
                current = current->next;
            } // we are pointing the search value
            Node *temp = current->next;
            current->next = new_node;
            new_node->next = temp;
        }
    }
    void delete_at_head()
    {
        if (head == nullptr)
            return;
        // when their is more than one node
        Node *current = head;
        Node *tail = head;
        while (tail->next != head)
        {
            tail = tail->next;
        } // now we are on last node
        tail->next = current->next;
        head = head->next;
        delete current;
    }
    void delete_at_tail()
    {
        if (head == nullptr)
            return;
        if (head->next == head)
        {
            delete head;
        }
        else
        {
            Node *tail = head;
            while (tail->next->next != head)
            {
                tail = tail->next;
            } // we are pointing on second last node
            Node *temp = tail->next;
            tail->next = head;
            delete temp;
        }
    }
    void delete_node_of_value(int search){
        if(head==nullptr) return ;
        else if(head->value==search){
            delete head;
        }
        else{
            Node*current = head;
            while(current->next->value!=search){
                       current=current->next;
            }// we are pointing the node before the node we have to deleted
            Node*temp = current->next;
            current->next=temp->next;
            delete temp;
        }
    }
    int count_node(){
        Node*tail = head;
        if(head==nullptr) return 0;//1 2 3 4 5 6
        int count = 1;
       while(tail->next!=head){
        tail=tail->next;
        count++;
       }
       return count;
        


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
        cout << tail->value<<endl;
    }
};
int main()
{
    Circular_list cll;
    cll.Display();
    cll.Insert_at_head(4);
    cll.Insert_at_head(3);
    cll.Insert_at_head(2);
    cll.Insert_at_head(1);
    cll.Insert_at_tail(5);        // 1 2 3 4 5
    cll.Insert_after_value(3, 6); // 1 2 3 6 4 5
    cll.delete_at_head();         // 2 3 6 4 5
    cll.delete_at_tail();// 2 3 6 4 
    cll.delete_node_of_value(4);// 2 3 6
    cll.Display();
    cout<<"Length of list "<<cll.count_node();

    return 0;
}
