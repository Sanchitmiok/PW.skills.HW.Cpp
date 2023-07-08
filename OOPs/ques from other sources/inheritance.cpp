#include <iostream>
#include <string>
using namespace std;
class person
{
protected:
    string name;
    string adress;

public:
    void set_name(string Name)
    {
        name = Name;
    }
    void set_add(string add)
    {
        adress = add;
    }
    string get_name()
    {
        return name;
    }
    string get_add()
    {
        return adress;
    }
};
class employee:public person{
    int emp_id;
    public:
    void set_id(int x){
        emp_id=x;
    }
    int get_id(){
        return emp_id;
    }

};
int main()
{
    employee emp;
    emp.set_name("Sanchit");
    emp.set_add("Dholakpur");
    emp.set_id(420);
    cout<<"Employee name is "<<emp.get_name()<<endl;
    cout<<"Employee address is "<<emp.get_add()<<endl;
    cout<<"Employee ID is "<<emp.get_id();

    return 0;
}
