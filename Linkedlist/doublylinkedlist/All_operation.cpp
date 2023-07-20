#include <iostream>
using namespace std;
class Node
{
public:
     int value;
     Node *next;
     Node *prev;
     Node(int val)
     {
          value = val;
          next = nullptr;
          prev = nullptr;
     }
};
class DoublyLinkedlist
{
public:
     Node *head;
     Node *tail;
     DoublyLinkedlist()
     {
          head = nullptr;
          tail = nullptr;
     }

     void Insert_at_head(int val)
     {
          Node *new_node = new Node(val);
          if (head == nullptr)
          {
               tail = head = new_node;
          }
          else
          {
               head->prev = new_node;
               new_node->next = head;
               head = new_node;
          }
     }
     void Insert_at_tail(int val)
     {
          Node *new_node = new Node(val);
          if (head == nullptr)
          {
               head = tail = new_node;
          }
          else
          {
               tail->next = new_node;
               new_node->prev = tail;
               tail = new_node;
          }
     }
     int length()
     {
          Node *ptr = head;

          int len = 0;
          while (ptr != nullptr)
          {
               ptr = ptr->next;
               len++;
          }
          return len;
     }
     void Insert_at_kth(int val, int k)
     {
          Node *new_node = new Node(val);
          if (head == nullptr)
          {
               head = tail = new_node;
          }
          int x = k % length();
          Node *ptr = head;
          while (x > 1)
          {
               ptr = ptr->next;
               x--;
          }
          // ptr point to the node to be deleted
          ptr->prev->next = new_node;
          ptr->next->prev = new_node;
          new_node->next = ptr->next;
          new_node->prev = ptr->prev;
          free(ptr);
     }
     void delete_from_head()
     {
          if (head == nullptr)
               return;
          Node *ptr = head;
          head = head->next;
          head->prev = nullptr;
          free(ptr);
     }
     void delete_from_tail()
     {
          if (tail == nullptr)
          {
               return;
          }
          Node *ptr = tail;
          tail = tail->prev;
          tail->next = nullptr;
          delete ptr;
     }
     void delete_from_position(int k)
     {
          if (k <= 0 || head == nullptr)
               return;
          if (k == 1)
          {
              delete_from_head();
              return;
          }
          Node *ptr = head;
          while (k > 1)
          {
               k--;
               ptr = ptr->next;
          }
          if (ptr == nullptr)
               return; // k is bigger then length of list
          ptr->prev->next = ptr->next;
          if (ptr->next)
          {
               ptr->next->prev = ptr->prev;
          }
          else{
               tail=ptr->prev;
          }

               delete ptr;
     }

     void display()
     {
          Node *curr = head;
          while (curr != nullptr)
          {
               cout << curr->value << " ";
               curr = curr->next;
          }
          cout << endl;
     }
};

int main()
{
     DoublyLinkedlist dll;
     dll.Insert_at_head(1); // 1
     dll.display();
     dll.Insert_at_head(2); // 2 1
     dll.display();
     dll.Insert_at_tail(3); // 2 1 3
     dll.display();
     dll.Insert_at_tail(4); // 2 1 3 4
     dll.display();
     dll.Insert_at_kth(5, 3); // 2 1 5 4
     dll.display();
     dll.delete_from_position(3); // 2 1 4
     dll.display();
     return 0;
}
