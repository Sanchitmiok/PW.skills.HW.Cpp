#include<iostream>
using namespace std;
class rectangle{
    float length,breath;
    public:
    void get(float a,float b){
        length=a;
        breath=b;
    }
    float area(){
        return length*breath;
    }
    float peri(){
        return 2*(length+breath);
    }
};
int main(){
    rectangle rec1;
    rec1.get(4.5,5);
    cout<<"Area of the rectangle is ->>"<<rec1.area()<<endl;
    cout<<"Perimeter of rectangle is ->>"<<rec1.peri();
    return 0;
}

