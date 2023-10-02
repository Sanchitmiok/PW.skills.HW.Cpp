#include<iostream>
using namespace std;
class Node{
    int data;
    Node* add; 
    public: 
    Node(int val){
        data = val;
        add = NULL;
    } 
    friend class queue;
};
class queue{
    Node* head;
    Node* tail;
    int size;
    public:
    queue(){
        head = NULL;
        tail = NULL;
        size = 0;
    }
   void enqueue(int val) {
        if(this->head == NULL){
            Node*new_node = new Node(val);
            this->head = this->tail = new_node;
        }
        else {
            Node* new_node = new Node(val);
            this->tail->add = new_node;
            this->tail = new_node;
        }
        size++;
    }
    int dequeue(){
        if(this->head == NULL){
            return -1;
        }else if(this->head == this->tail) {
            int temdata = this->head->data;
            Node*temp = this->head;
            this->head = this->tail = NULL;
            delete temp;
            size--;
            return temdata;
        }else{
        int tempdata = this->head->data;
        Node* temp = this->head;
        this->head = this->head->add;
        delete temp;
         size--;
        return tempdata;
        }
       
    }
    bool isEmpty(){
        return this->head==NULL;
    }
    int front(){
        if(this->head==NULL) return -1;
        else return this->head->data;
    }
    int Size(){
        return size;
    }

};
int main()
{   
    queue qu;
       
    return 0;
}
