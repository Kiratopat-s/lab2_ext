#include <stdio.h>
#include <windows.h>
#include <tchar.h>
#include <stdlib.h>
#include <process.h>

int main(){
	STARTUPINFO si,si2;
	PROCESS_INFORMATION pi,pi2;
	TCHAR name[] = _T("lab2_2c1.exe");
	TCHAR name2[] = _T("lab2_2c2.exe");

	ZeroMemory(&si,sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi,sizeof(pi));
	ZeroMemory(&si2,sizeof(si2));
	si2.cb = sizeof(si2);
	ZeroMemory(&pi2,sizeof(pi2));

    if(!CreateProcess(NULL,name,
		NULL,NULL,FALSE,0,NULL,NULL,&si,&pi)){
			fprintf(stderr,"Create process failed.\n");
			return -1;
	}
    if(!CreateProcess(NULL,name2,
		NULL,NULL,FALSE,0,NULL,NULL,&si2,&pi2)){
			fprintf(stderr,"Create process failed.\n");
			return -1;
	}

	//Parent Process
	printf("Before going into the wait state...\n");
	printf("Process A\n");
    for(int i=0;i<10;i++){
        printf("A:%d\n",i);
        Sleep(1000);
	}

	WaitForSingleObject(pi.hProcess,INFINITE);
	WaitForSingleObject(pi2.hProcess,INFINITE);

	printf("Child process has terminated\n");
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
	CloseHandle(pi2.hProcess);
	CloseHandle(pi2.hThread);
	int x;
	scanf("%d",&x);
	return 0;
}
