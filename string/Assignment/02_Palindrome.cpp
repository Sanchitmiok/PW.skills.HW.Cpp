#include<bits/stdc++.h>
#include<string>
using namespace std;
int main(){
string str("redder");
int size=str.length();
int flag = 0;
for(int i=0,j=size-1;i<=j;i++,j--){
    if(str[i]!=str[j]) flag=-1;
}
if(flag==0) cout<<"given string is Palindrome \n";
else cout << "given string is not palindrome";
    return 0;
}
