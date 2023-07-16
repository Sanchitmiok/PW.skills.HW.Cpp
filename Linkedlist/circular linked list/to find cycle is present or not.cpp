#include <iostream>
using namespace std;
class NODE
{
public:
     int value;
     NODE *next;
};
class Linkedlist
{
public:
     NODE *head;

public:
     Linkedlist()
     {
          head = NULL;
     }
     void insertAthead(int value)
     {
          NODE *newnode = new NODE;
          newnode->value = value;
          newnode->next = head;
          head = newnode;
     }
     void display()
     {
          NODE *Next = head;
          while (Next != NULL)
          { 
               cout << Next->value << "->";
               Next = Next->next;
          }
          cout << "NULL";
     }
};
NODE* Cycle_inLL(NODE* head){
     if(!head || !head->next ){
          return nullptr;
     }
     NODE*slow = head;
     NODE*fast= head;
     bool hascycle=false;
     while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
          if(slow==fast){
               hascycle= true;
               break;
          }
        
     }// till here we have found either cycle is present or not
     if(hascycle){// to found the starting point of cycle
          slow=head;
          while(slow!=fast){
               slow=slow->next;
               fast=fast->next;
          }
          return slow;

     }else{
     return nullptr;}
}
int main()
{
     Linkedlist ll;
     ll.insertAthead(2);
     ll.insertAthead(1);
     ll.insertAthead(5);
     ll.insertAthead(9);
ll.head->next->next->next=ll.head->next->next;     
     NODE*Founded_node=Cycle_inLL(ll.head);
     if(Founded_node){
          cout<<"Cycle is present at "<<Founded_node->value;
     }else cout<<"No cycle is present";
     return 0;
}
