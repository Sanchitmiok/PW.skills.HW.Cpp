#include<bits/stdc++.h>
#include<string>
using namespace std;
int main(){
string str("sanchitmishra");int vowel=0;int consonent=0;
 
for(int i=0;i<13;i++){
   if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ) {
         vowel++;
   }else consonent++;
}
cout<<"Vowel = "<<vowel<<" Consonent = "<<consonent;

    return 0;
}
