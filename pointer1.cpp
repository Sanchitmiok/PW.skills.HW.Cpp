// Write a program to print the address of an integer variable whose value is input by the
// user.
#include<iostream>
using namespace std;
int main(){
int a=2;

int *add=&a;
cout<<add<<" "<<*add<<endl;

    return 0;
}