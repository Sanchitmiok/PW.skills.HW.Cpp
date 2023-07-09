#include <iostream>
#include <string>
using namespace std;
class student
{
    string name;
    string roll_num;
    string phone_num;

public:
    //constructor
    student(string input1,string input2,string input3){
        name = input1;
        roll_num = input2;
        phone_num = input3;
    }
    //functions
    string get_name()
    {
        return name;
    }
    string get_roll()
    {
        return roll_num;
    }
    string get_phone()
    {
        return phone_num;
    }
};
int main()
{
    student bhola("Bhola pandit","2K22/A7/028301","9xx91xx018");
    
    cout << "full name " << bhola.get_name() <<endl<< "roll num is " << bhola.get_roll() << endl;
    cout << "Bhola's phone number is  " <<"'"<< bhola.get_phone()<<"'";

    return 0;
}
