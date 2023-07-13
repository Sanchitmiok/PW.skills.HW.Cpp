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
bool Cheak_linkedlist(Node* head1,Node* head2){
     Node*next1 = head1;
     Node*next2 = head2;
     while(next1!=NULL && next2!=NULL){
          if(next1->value!=next2->value){
               return false;
          }
          next1=next1->Add;next2=next2->Add;

     }
     return (next1==NULL && next2==NULL);

}


int main()
{
     LL ll1;
     ll1.Add_tail(1);
     ll1.Add_tail(2);
     ll1.Add_tail(3);
     
     LL ll2;
     ll2.Add_tail(1);
     ll2.Add_tail(2);
     ll2.Add_tail(3);
     ll2.Add_tail(5);
     ll1.Display();
     ll2.Display();
     cout<<Cheak_linkedlist(ll1.head,ll2.head);

     return 0;
}
