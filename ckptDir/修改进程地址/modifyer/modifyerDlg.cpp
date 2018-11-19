
// modifyerDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "modifyer.h"
#include "modifyerDlg.h"
#include "processHelper.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CmodifyerDlg 对话框




CmodifyerDlg::CmodifyerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CmodifyerDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_address=0;
}

void CmodifyerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX,IDC_EDIT_ADRESS,m_address);
}

BEGIN_MESSAGE_MAP(CmodifyerDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BTN_MODIFY, &CmodifyerDlg::OnBnClickedBtnModify)
END_MESSAGE_MAP()


// CmodifyerDlg 消息处理程序

BOOL CmodifyerDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
 UpdateData(false);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CmodifyerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CmodifyerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CmodifyerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
	
}

// 修改内存地址 975313
void CmodifyerDlg::OnBnClickedBtnModify()
{
	int a=20;
    UpdateData();
	int hProceID=GetPorcess(L"modifyed.exe");
    HANDLE hProcess=OpenProcess(PROCESS_ALL_ACCESS,FALSE,hProceID);
	if(hProcess==NULL)
	{
		AfxMessageBox(L" open process error");
		return;
	}

	MEMORY_BASIC_INFORMATION mbi;
	DWORD ret=::VirtualQueryEx(hProcess,(LPVOID)0xFFFFFFFF,&mbi,sizeof(mbi));
	LPVOID baseAdress= mbi.BaseAddress;
	//baseAdress=(LPVOID)m_address;
	DWORD test;
	//BOOL flag=ReadProcessMemory(hProcess,baseAdress,&a,4,&test);
	while(true)
	{
		//::VirtualQueryEx(hProcess,baseAdress,&mbi,sizeof(mbi));
		
		BOOL flag=ReadProcessMemory(hProcess,baseAdress,&a,4,&test);
		if(flag)
		{
			if(a==975313)
			{
				a=4567;
                WriteProcessMemory(hProcess,baseAdress,&a,4,&test);
				 AfxMessageBox(L"OK");
			}
		 
		}
		else
		{
			int* pint=(int*)baseAdress;
			pint--;
			baseAdress=pint;
		}
	}
	
}
