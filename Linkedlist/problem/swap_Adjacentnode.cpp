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
          cout << "NULL" << endl;
     }
};
NODE*Swap_adjacent(NODE* &head){
     //base case
     if(head==nullptr || head->next==nullptr){
          return head;
     }
     NODE*secondnode=head->next;
     head->next=Swap_adjacent(secondnode->next);
     secondnode->next=head;
     return secondnode;
}
int main()
{
     Linkedlist ll;
     ll.insertAthead(8);
     ll.insertAthead(7);
     ll.insertAthead(6);
     ll.insertAthead(5);
     ll.insertAthead(4);
     ll.insertAthead(3);
     ll.insertAthead(2);
     ll.insertAthead(1);
     ll.display();
     ll.head = Swap_adjacent(ll.head);
     ll.display();

     return 0;
}
