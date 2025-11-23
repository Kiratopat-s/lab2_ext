#include <stdio.h>
#include <malloc.h>

char *st;

void clear(){
    int ch;
    while(((ch=getchar())!='\n')&&(ch!=EOF));
}

int main(){
  int a,b,c;
  st = (char *)malloc(256);
  printf("Please enter your name:");
  fgets(st,256,stdin);
  printf("Your name is:%s\n",st);
  printf("Please enter a value for A:");
  scanf("%d",&a);
  printf("Please enter a value for B:");
  scanf("%d",&b);

  c = a+b;

  printf("a+b=%d\n",c);
  printf("Press ENTER to continue");
  clear();
  fgets(st,256,stdin);
  free(st);
  return 0;
}