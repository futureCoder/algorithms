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
		printf("CreateToolhelp32Snapshot����ʧ��!\n");
		return NULL;
	}
	//�������̿��ա�������ʾÿ�����̵���Ϣ
	BOOL bMore=::Process32First(hProcessSnap,&pe32);
	while(bMore)
	{
		/*printf("�������ƣ�%s\n",pe32.szExeFile);
		printf("����ID�ţ�%u\n\n",pe32.th32ProcessID);*/
		if(::wcscmp(pe32.szExeFile,exeName)==0)
		{
          target=pe32.th32ProcessID;
		  break;
		}
		bMore=::Process32Next(hProcessSnap,&pe32);
	}
	//���snapshot����
	::CloseHandle(hProcessSnap);
	return target;

}