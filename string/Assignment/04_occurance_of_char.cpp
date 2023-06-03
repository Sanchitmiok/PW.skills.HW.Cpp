#include<bits/stdc++.h>
#include<string>
using namespace std;
int main(){
string str("Sanchit Mishra");
int size=str.length();
int count = 0;char CH='i';
for(int i=0;i<size;i++){
    if(CH==str[i]) count++;
}
cout<<"Count of char "<<CH<<" in "<<str<< " is "<<count;
    return 0;
}
