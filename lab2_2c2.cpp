#include <stdio.h>
#include <windows.h>
int main(){
    printf("Process C\n");
    for(int i=0;i<10;i++){
        printf("C:%d\n",i);
        Sleep(1000);
    }    
    return 0;
}