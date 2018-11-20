#include "iostream"
#include "windows.h"
#include <tlhelp32.h>

int GetPorcess(WCHAR* exeName)
{
	int target=0;
	PROCESSENTRY32 pe32;
	pe32.dwSize=sizeof(pe32);
	HANDLE hProcessSnap=::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);
	if(hProcessSnap==INVALID_HANDLE_VALUE)
	{
		printf("CreateToolhelp32Snapshot调用失败!\n");
		return NULL;
	}
	//遍历进程快照。轮流显示每个进程的信息
	BOOL bMore=::Process32First(hProcessSnap,&pe32);
	while(bMore)
	{
		/*printf("进程名称：%s\n",pe32.szExeFile);
		printf("进程ID号：%u\n\n",pe32.th32ProcessID);*/
		if(::wcscmp(pe32.szExeFile,exeName)==0)
		{
          target=pe32.th32ProcessID;
		  break;
		}
		bMore=::Process32Next(hProcessSnap,&pe32);
	}
	//清除snapshot对象
	::CloseHandle(hProcessSnap);
	return target;

}