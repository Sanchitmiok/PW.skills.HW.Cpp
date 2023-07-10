#include <iostream>
using namespace std;
class Node
{
public:
     int val;
     Node *next;
};
class linkedlist
{
private:
     Node *head;

public:
     linkedlist()
     {
          head = nullptr;
     }
     void insertAthead(int value)
     {
          Node *newnode = new Node;
          newnode->val = value;
          newnode->next = head;
          head = newnode;
     }
     void insertAttail(int value)
     {
          Node *newnode = new Node;
          newnode->val = value;
          newnode->next = nullptr;
          if (head == nullptr)
          {
               head = newnode;
          }
          else
          {
               Node *current = head;
               while (current->next != nullptr)
               {
                    current = current->next;
               }
               current->next = newnode;
          }
     }
     void insertAtkth(int value, int position)
     {

          if (position <= 0)
          {
               insertAthead(value);
          }
          else
          {
               Node *newnode = new Node;
               newnode->val = value;
               Node *current = head;
               Node *prev = nullptr;
               int count = 0;
               while (current != nullptr && count < position)
               {
                    prev = current;
                    current = current->next;

                    count++;
               }
               newnode->next = current;
               prev->next = newnode;
          }
     }
     void deleteAthead()
     {
          if (head != nullptr)
          {
               Node *temp = head;
               head = head->next;
               delete temp;
          }
     }
     void deleteAttail()
     {
          if (head == nullptr)
          {
               return;
          }
          if (head->next == nullptr)
          {
               delete head;
               head = nullptr;
               return;
          }
          Node *current = head;
          Node *previous = nullptr;
          while (current->next != nullptr)
          {
               previous = current;
               current = current->next;
          }
          previous->next = nullptr;
          delete current;
     }
     void deleteAtKth(int position)
     {
          if (position <= 0 && head == nullptr)
          {
               deleteAthead();
          }
          else
          {
               Node *current = head;
               Node *Previous = nullptr;
               int count = 0;
               while (count < position && current != nullptr)
               {
                    Previous = current;
                    current = current->next;
                    count++;
               }
               if (current != nullptr)
               {
                    Previous->next = current->next;
                    delete current;
               }
          }
     }
  
   
     void print()
     {

          Node *current = head;
          while (current != nullptr)
          {
               cout << current->val;
               current = current->next;
               cout << "  ";
          }
          cout << endl;
     }
};

int main()
{
     linkedlist myslist;
     myslist.insertAthead(2);
     myslist.print();
     myslist.insertAthead(1);
     myslist.print();
     myslist.insertAttail(5);
     myslist.print();
     myslist.insertAtkth(10, 2);
     myslist.print();
     myslist.deleteAthead();
     myslist.print();
     myslist.deleteAttail();
     myslist.print();
     myslist.insertAtkth(26, 1);
     myslist.insertAthead(6);
     myslist.insertAttail(9);
     myslist.print();
     myslist.deleteAtKth(3);
     myslist.print();

     return 0;
}
