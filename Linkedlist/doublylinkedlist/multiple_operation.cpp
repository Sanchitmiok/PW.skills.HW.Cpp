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
    if (k <= 0)
    {
        Insert_at_tail(val); // Insert at the tail for invalid k values
        return;
    }

    Node *new_node = new Node(val);
    if (head == nullptr)
    {
        head = tail = new_node;
        return;
    }

    int length = 1;
    Node *ptr = head;
    while (ptr->next != nullptr)
    {
        length++;
        if (length == k)
        {
            new_node->prev = ptr;
            new_node->next = ptr->next;
            if (ptr->next)
            {
                ptr->next->prev = new_node;
            }
            else
            {
                tail = new_node;
            }
            ptr->next = new_node;
            return;
        }
        ptr = ptr->next;
    }

    // If k is greater than the length of the list, insert at the tail
    tail->next = new_node;
    new_node->prev = tail;
    tail = new_node;
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
          else
          {
               tail = ptr->prev;
          }

          delete ptr;
     }
     void Reverse()
     {
          if(head==nullptr || head->next==nullptr) return ;//no need to do anything
          Node*current=head;
          while(current!=nullptr){
               Node*prev=current->prev;// 1 2 3 4 -> 4 3 2 1
               Node*next=current->next;
               current->next=prev;
               current->prev=next;
               current=next;

          }
          Node*temp=head;
          head=tail;
          tail=temp;
          return ;
     }
     bool IsPalindrome(){
          // eliminating case
          if(head==nullptr || head->next==nullptr){
               return true ; 
          }// 1 2 3 2 1
          Node*first=head;
          Node*last=tail;
          while(last->prev!=first && first!=last){
               if(first->value!=last->value){
                    return false;
               }
               last=last->prev;
               first=first->next;
          }
          return true;

     }
void Delete_Node_whose_neighbourIssame(){
     // edge case
     if(head==nullptr || head->next==nullptr || head->next->next==nullptr) return ;
     // when their is more than 2 nodes
     Node* current = head->next;
     while(current->next!=nullptr){
          if(current->next->value == current->prev->value){
               Node*temp = current;
               current=current->next;
               temp->next->prev=temp->prev;
               temp->prev->next=temp->next;
               delete temp;
          }
          current=current->next;
     }
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
     dll.Insert_at_tail(2); // 2 1 2
     dll.display();
     dll.Insert_at_tail(1); // 2 1 2 1
     dll.display();
     dll.Delete_Node_whose_neighbourIssame();
     dll.display();
    
     return 0;
}
