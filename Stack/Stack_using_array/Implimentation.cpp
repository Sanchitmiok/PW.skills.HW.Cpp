#include <iostream>
using namespace std;
const int MAX_SIZE = 1000;
class Stack
{
private:
    int array[MAX_SIZE];
    int top_idx = -1;

public:
    int Isfull()
    {
        return top_idx == MAX_SIZE - 1;
    }
    int Isempty()
    {
        return top_idx == -1;
    }
    void push(int val)
    {
        if (Isfull())
        {
            cout << "Overflow";
            return;
        }
        else
        {
            top_idx++;
            array[top_idx] = val;
        }
    }
    int pop()
    {
        if (Isempty())
        {
            cout << "Stack is empty:cannot be popped";
            return -1;
        }
        else
        {
            int temp = array[top_idx];
            top_idx--;
            return temp;
        }
    }
    int top()
    {
        if (Isempty())
        {
            cout << "Stack is empty: cannot return top ";
            return -1;
        }
        else
        {
            return array[top_idx];
        }
    }
};
int main()
{
    Stack st;
    st.push(5);
    st.push(4);
    st.push(3);
    st.push(8);
    cout << st.top() << endl; // return 8
    st.pop();   // 8 is popped
    cout << st.top() << endl; // we can se the top element is changed {return 3}
    st.pop();
    st.pop();
    st.pop();
    cout << st.top() << endl; // stack becomes empty
    cout<<st.Isempty()<<endl;//stack is empty {return 1}
    st.push(10);
    cout << st.top() << endl; //{return 10}
    cout << st.Isfull();// stack is not full yet{return 0}

    return 0;
}
