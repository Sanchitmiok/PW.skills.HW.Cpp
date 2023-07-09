#include<iostream>
#include<string>
using namespace std;
class books{
    string name;
    int id;
    public:
    books(){
        name="Gita";
        id=0;
    }
    public:
    string get_name(){
        return name;
    }
    int get_id(){
        return id;
    }
};
int main(){
    books book;
    cout<<"Name of the book is "<<book.get_name()<<endl;
    cout<<"Id of this book is "<<book.get_id();

    return 0;
}
