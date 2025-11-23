#include <stdio.h>
#include <windows.h>
#include <tchar.h>
#include <stdlib.h>
#include <process.h>

int main(){
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
//	TCHAR name[] = _T("c:\\windows\\system32\\notepad.exe");
	TCHAR name[] = _T("\"C:\\Program Files (x86)\\Microsoft\\Edge\\Application\\msedge.exe\" https://www.google.com");

	ZeroMemory(&si,sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi,sizeof(pi));

    printf("Before fork a child process...\n");

    if(!CreateProcess(NULL,name,
		NULL,NULL,FALSE,0,NULL,NULL,&si,&pi)){
			fprintf(stderr,"Create process failed.\n");
			return -1;
	}

	//Parent Process
	printf("Before going into the wait state...\n");
	printf("Process A\n");

	WaitForSingleObject(pi.hProcess,INFINITE);

	printf("Child process has terminated\n");
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
	return 0;
}
