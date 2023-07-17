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
bool Palindrome_cheaking(NODE *head)
{
     if (head == nullptr || head->next == nullptr)
          return true;
     NODE *slow = head;
     NODE *fast = head;
     while (fast->next != nullptr && fast->next->next != nullptr)
     {
          slow = slow->next;
          fast = fast->next->next;
     }
     NODE *current = slow->next;
     NODE *next = nullptr;
     NODE *prev = nullptr;
     while (current != nullptr)
     {
          next = current->next;
          current->next = prev;
          prev = current;
          current = next;
     }
     NODE *firsthalf = head;
     NODE *secondhalf = prev;
     while (secondhalf != nullptr)
     {
          if (firsthalf->value != secondhalf->value)
          {
               return false;
          }
          firsthalf = firsthalf->next;
          secondhalf = secondhalf->next;
     }
     return true;
}

int main()
{
     Linkedlist ll;
     ll.insertAthead(2);
     ll.insertAthead(1);
     ll.insertAthead(1);
     ll.insertAthead(2);

     bool Founded_node = Palindrome_cheaking(ll.head);
     if (Founded_node)
     {
          cout << "yes its a palindrome";
     }
     else
          cout << "No ";
     return 0;
}
