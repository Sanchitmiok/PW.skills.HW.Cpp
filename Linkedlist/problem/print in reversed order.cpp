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
void print_in_reversed_order(Node*head){
         
          if(!head) return ;

          print_in_reversed_order(head->Add);
          cout<<head->value<<" ";
     }
  


int main()
{
     LL ll;
     ll.Add_tail(1);
     ll.Add_tail(1);
     ll.Add_tail(1);
     ll.Add_tail(2);
     ll.Add_tail(4);
     ll.Add_tail(4);
     ll.Display();  
     print_in_reversed_order(ll.head);
     
     return 0;
}
