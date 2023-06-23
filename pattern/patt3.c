#include<stdio.h>
int main(){
  printf("order-> ");
  int n;
  scanf("%d",&n);
  int i=n;
  for(int i=1;i<=2*n-1;i++){
    int COL=i>n?2*n-i:i;
    int space = n- COL;
      for(int s=1;s<=space;s++){
        printf(" ");
      }
    for(int j=1;j<=COL;j++){    
      printf("* ");
    } printf("\n");
  }  
  return 0;
}
// order-> 5
//     *
//    * *
//   * * *
//  * * * *
// * * * * *
//  * * * *
//   * * *
//    * *
//     *
