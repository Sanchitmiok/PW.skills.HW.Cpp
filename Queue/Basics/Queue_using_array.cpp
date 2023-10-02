#include<iostream>
using namespace std;
class queue{
    int arr[10];
    int front_idx=0 , rear_idx = -1;
    int capacity=10;
    public:
    void enqueue(int data){
        if(rear_idx + 1 == capacity){
            cout<<"No more space availble for insertion of element "<<data<<endl; 
            return ;
        }
        rear_idx++;
        arr[rear_idx] = data;
    }
    void dequeue(){
        if(rear_idx < front_idx){
            cout<<"No more element is present in queue"<<endl;
            return ;
        }else{
            front_idx++;
        }
    }
    bool isFull(){
        return rear_idx + 1 == capacity;
    }
    bool isEmpty(){
        return rear_idx < front_idx ;
    }
    int size(){
        return rear_idx - front_idx + 1;
    }
    int front(){
        if(isEmpty()) return -1;
        else return arr[front_idx];
    }
};
int main()
{   
 queue qu;
    return 0;
}
