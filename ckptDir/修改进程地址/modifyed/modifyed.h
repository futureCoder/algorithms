
// modifyed.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CmodifyedApp:
// �йش����ʵ�֣������ modifyed.cpp
//

class CmodifyedApp : public CWinAppEx
{
public:
	CmodifyedApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CmodifyedApp theApp;