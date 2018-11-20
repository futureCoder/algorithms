
// modifyerDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "modifyer.h"
#include "modifyerDlg.h"
#include "processHelper.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CmodifyerDlg �Ի���




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


// CmodifyerDlg ��Ϣ�������

BOOL CmodifyerDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
 UpdateData(false);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CmodifyerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CmodifyerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
	
}

// �޸��ڴ��ַ 975313
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
