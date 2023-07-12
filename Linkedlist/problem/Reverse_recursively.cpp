#include <iostream>
using namespace std;
class Node
{
public:
     int value;
     Node *Add;
};
class LL
{
public:
     Node *head;

public:
     LL()
     {
          head = nullptr;
     }
     void Add_tail(int val)
     {
          Node *newnode = new Node;
          newnode->value = val;
          newnode->Add = nullptr;
          if (head == nullptr)
          {
               head = newnode;
          }
          else
          {
               Node *current = head;
               while (current->Add != nullptr)
               {
                    current = current->Add;
               }
               current->Add = newnode;
          }
     }
     void Display()
     {
          Node *current = head;
          while (current != nullptr)
          {
               cout << current->value << "->";
               current = current->Add;
          }
          cout << "NULL"<<endl;
     }
     
};
Node*Reverse_list(Node* &head){
     Node*current = head;
     Node*Prev = nullptr;
     while(current){
          Node*next=current->Add;
          current->Add=Prev;
          Prev=current;
          current=next;
     }
     return Prev;
}
//function
Node* reversed_recursive(Node* &head){
     if(head==nullptr || head->Add==nullptr) return head;
     Node* newnode=reversed_recursive(head->Add);
     head->Add->Add=head;
     head->Add=nullptr;
     return newnode;
}


int main()
{
     LL ll;
     ll.Add_tail(1);
     ll.Add_tail(2);
     ll.Add_tail(3);
     ll.Add_tail(4);
     ll.Add_tail(5);
     ll.Add_tail(6);
     ll.Display();  
     ll.head=reversed_recursive(ll.head);
     ll.Display();
     return 0;
}
