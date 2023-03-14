#include <iostream>
#include <string>
using namespace std;
void analyise(string *s ){
  int cnt=0;
  char Firstchar = (*s)[0];
  char Lastchar= (*s)[s->length()-1];
  for(int i=0;i<s->length();i++){
    if((*s)[i]=='t'||(*s)[i]=='T'){
        cnt++;
    }
  }
  cout<<"First character = "<<Firstchar<<endl;
  cout<<"Last character = "<<Lastchar<<endl;
  cout<<"The number of time t used is "<<cnt<<endl;

    
}
using namespace std;

int main()
{
    string s;
    cout<<"Pls enter the string :";
    cin >> s;
    analyise(&s);
     return 0;
}
