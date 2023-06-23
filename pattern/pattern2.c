// order-> 5
// * 
// * * 
// * * * 
// * * * * 
// * * * * * 
// * * * * 
// * * * 
// * * 
// * 

#include<stdio.h>
int main(){
  printf("order-> ");
  int n;
  scanf("%d",&n);
  int i=n;
   
    for(int ro=1;ro<=n;ro++){
      for(int col=1;col<=ro;col++){
        printf("* ");
      }printf("\n");
    }
   
   
    for(int ro=n+1;ro<2*n;ro++){
      for(int col=1;col<=(2*n)-ro;col++){
         printf("* ");
      }printf("\n");
    }
   
  
  return 0;
}
