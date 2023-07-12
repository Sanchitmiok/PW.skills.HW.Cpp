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
private:
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
   void delete_duplicate(){
     if(!head) return;
     Node*current=head;
     Node*temp;
     while(current->Add!=nullptr){
          if(current->value==current->Add->value){
          temp=current->Add;
          current->Add=current->Add->Add;
          delete temp;
          }else{
          current=current->Add;
          }
     }
   }
  
};


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
     ll.delete_duplicate();
     ll.Display();
     return 0;
}
