int Find_length(Node *head)
{
     Node *next = head;
     int length = 0;
     while (next->Add != NULL)
     {
          length++;
          next = next->Add;
     }
     return length;
}
void delete_kth_from_endOFlist(Node *head, int k)
{
     Node *next = head;
     int count = Find_length(head) - k + 1;
     if (count <= 0)
     {
          return;
     }
     while (next != 0 && count > 1)
     {
          next = next->Add;
          count--;
     }
     next->Add = next->Add->Add;
}
