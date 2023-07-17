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

NODE* Rotate_the_list(NODE *head, int k)
{
     if (head == nullptr || head->next == nullptr || k == 0)
          return nullptr;
     NODE *Current = head;
     int len = 1;
     while(Current->next!=nullptr){
          len++;
          Current=Current->next;
     }
     Current->next=head;// connect the last node to the first node
     int x = len - k;//we  need to update current upta x times
     Current=head;
     while(x>1){
          Current=Current->next;
         x--;
     }
     NODE *newhead = Current->next;//new head of list
     Current->next = nullptr;// free the length - kth element from cycle
     return newhead;
     
}

int main()
{
     Linkedlist ll;
     ll.insertAthead(2);
     ll.insertAthead(3);
     ll.insertAthead(1);
     ll.insertAthead(7);
     ll.display();
     ll.head=Rotate_the_list(ll.head,2);//update new head of list
     ll.display();

     return 0;
}
