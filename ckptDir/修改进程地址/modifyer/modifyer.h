
// modifyer.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CmodifyerApp:
// �йش����ʵ�֣������ modifyer.cpp
//

class CmodifyerApp : public CWinAppEx
{
public:
	CmodifyerApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CmodifyerApp theApp;