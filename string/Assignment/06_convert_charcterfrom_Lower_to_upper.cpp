#include<iostream>
#include<string>
using namespace std;
int main(){
    string str={"COnvert"};
    cout<<str<<endl;
    int size=str.length();
    for(int i=0;i<size;i++){  
        if(str[i]>='a' &&    str[i]<='z'){//condition for lower case
            str[i] = str[i]- 32;
        } else if(str[i]>='A' && str[i]<='Z'){
            str[i] = str[i] + 32;  // uper case condition 
        }
        
    }
   cout<<str;

    return 0;
}
