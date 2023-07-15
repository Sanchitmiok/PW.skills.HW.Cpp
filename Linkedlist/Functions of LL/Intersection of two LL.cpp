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
// Function
Node* intersection_of_twolist(Node*head1,Node*head2)
{
     Node*add1=head1;
     Node*add2=head2;
     if(head1==NULL && head2==NULL ) return NULL;
     while(add1!=NULL && add2!=NULL && add1 != add2){
          add1=add1->Add;
          add2=add2->Add;
          if(add1==add2) return add1;
          if(add1==NULL) add1=head2;
          if(add2==NULL) add2=head1;
     }
     return add1;
}
int main()
{
     LL ll;
     ll.Add_tail(1);
     ll.Add_tail(2);
     ll.Add_tail(3);
     ll.Add_tail(4);
     ll.Add_tail(5);
     LL ll1;
     ll1.Add_tail(8);
     ll1.Add_tail(7);
     ll1.head->Add->Add=ll.head->Add->Add->Add;
     ll.Display();
     ll1.Display();
     Node*val=intersection_of_twolist(ll.head,ll1.head);
     cout<<val->value;

     return 0;
}
