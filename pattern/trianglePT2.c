#include<stdio.h>
int main(){
  printf("Printer the order of pattern");
  int n;
  scanf("%d",&n);
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n-i+1;j++){
    printf("* ");
    }printf("\n");
  }
  return 0;
}
// Printer the pattern of order 5
// * * * * * 
// * * * * 
// * * * 
// * * 
// * 
