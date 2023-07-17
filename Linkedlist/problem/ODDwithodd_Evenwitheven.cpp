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

NODE* rearange_oddwithodd_and_evenwitheven(NODE*head){
     NODE*Oddhead=head;
     NODE*Oddtail=head;
     NODE*Evenhead=head->next;
     NODE*Eventail=head->next;
     while(Eventail!=nullptr && Eventail->next!=nullptr){
          Oddtail->next=Eventail->next;//update the odd list to the next node after the even node
          Oddtail=Oddtail->next;//update the odd tai
          Eventail->next=Oddtail->next;// update the even list to add new node
          Eventail=Eventail->next;//update the even tail
     }
     Oddtail->next=Evenhead;
     return Oddhead;

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
     rearange_oddwithodd_and_evenwitheven(ll.head);
     ll.display();

     return 0;
}
