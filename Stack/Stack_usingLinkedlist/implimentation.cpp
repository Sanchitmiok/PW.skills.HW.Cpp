#include <iostream>
using namespace std;
class Node
{
public:
    int value;
    Node *next;
    Node(int val) : value(val), next(NULL){};
};
class stack
{
private:
    Node *head;

public:
    stack() : head(NULL){};
    void push(int val)
    {
        Node *new_node = new Node(val);
        new_node->next = head;
        head = new_node;
    }
    int pop()
    {
        if (head == NULL)
        {
            cout << "underflow" << endl;
            return -1;
        }
        Node *temp = head;
        int value = head->value;
        head = head->next;
        delete temp;
        return value;
    }
    int top()
    {
        if (head == NULL)
        {
            cout << "Stack is empty: can't return top ";
        }
        else
            return head->value;
    }
    int Isempty()
    {
        return head == NULL;
    }
};
int main()
{
    stack st;
    st.push(2);
    st.push(4);
    st.push(8);
    st.push(9);

    return 0;
}
