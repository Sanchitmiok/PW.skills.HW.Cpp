Node *merge_two_sorted_LL(Node *head1, Node *head2)
{
     Node *next1 = head1;
     Node *next2 = head2;
     Node *Dummy = new Node;
     Node *current = Dummy;
     while (next1 != NULL && next2 != NULL)
     {
          if (next1->value <= next2->value)
          {
               current->Add = next1;
               next1 = next1->Add;
          }
          else
          {
               current->Add = next2;
               next2 = next2->Add;
          }
          current = current->Add;
     }
     if (next1 == NULL)
          current->Add = next2;
     else
          current->Add = next1;
     return Dummy->Add;
}
