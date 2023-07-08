#include <iostream>
using namespace std;
class Bank_account
{
private:
    int account_no;
    float balance=0;

public:   
    Bank_account(int acc_num): account_no(acc_num),balance(0.f){}      
    
    int deposite(int y){
        balance+=y;
    }
    int withdrawal(int amount){
        if(balance-amount >=0){
            balance-=amount;
        } else cout<<"insufficient balancce";
       
    }
    void show_balance(){
        cout<<" your account no. "<<account_no<<endl;
        cout<<"Remain balance is "<<balance;
        
    }
};
int main()
{
    Bank_account acc1(2020);
    acc1.deposite(2990);
    acc1.deposite(91909);
    acc1.withdrawal(2893);
    acc1.deposite(67291);
    acc1.show_balance();


    return 0;
}
