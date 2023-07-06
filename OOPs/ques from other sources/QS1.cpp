#include<iostream>
#include<string>
#include<cstring>
using namespace std;
class student{
   
   string name;
   int age;
   public:
   void setage(int x){
    age=x;
   }
   void setname(const string &n){
    name=n;
    
   }int getage(){
     return age;
   }
    string getname(){
    return name;
    
   }
   
   
};
int main(){
    student s1,s2;
    s1.setage(20);
    s2.setage(22);
    s1.setname("Sanchit");
    s2.setname("Mishra");
    cout<<"Name is ->"<<s1.getname()<<"   age is "<<s1.getage()<<endl;
    cout<<"Name id ->"<<s2.getname()<<"   age is "<<s2.getage();
    
  

    return 0;
}
