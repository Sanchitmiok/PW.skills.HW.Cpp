#include<iostream>
#include<string>
using namespace std;
int main()  { 
   int number=43;int n=43;
   int num[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
   string symbol[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
   string result="";
   for(int i=0;i<sizeof(num)/sizeof(num[0]);i++){
      while(number >= num[i]){
         result+=symbol[i];
         number-=num[i];
      }
   }
   cout<<"Roman of "<<n<<" is "<< result;
      return 0;}
