
// NRsystem_GUIDlg.cpp : implementation file
//

#include "stdafx.h"
#include "NRsystem_GUI.h"
#include "NRsystem_GUIDlg.h"
#include "afxdialogex.h"

// includes Nr system libs' header files
#include "gNbIntf.h"
#include "nrUeIntf.h"
#include "nrBasicIntf.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();
    

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CNRsystem_GUIDlg dialog



CNRsystem_GUIDlg::CNRsystem_GUIDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_NRSYSTEM_GUI_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CNRsystem_GUIDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_TAB_GNB, m_tab);
    DDX_Control(pDX, IDC_TAB_UE, m_ueTab);
    DDX_Control(pDX, IDC_NR_Status, m_NrStatusTxt);
}

BEGIN_MESSAGE_MAP(CNRsystem_GUIDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDC_gNbTx, &CNRsystem_GUIDlg::OnBnClickedgNbTx)
    ON_BN_CLICKED(IDC_nrUeRx, &CNRsystem_GUIDlg::OnBnClickedNrUeRx)
    ON_BN_CLICKED(IDC_nrUeTx, &CNRsystem_GUIDlg::OnBnClickedNrUeTx)
    ON_BN_CLICKED(IDC_gNbRx, &CNRsystem_GUIDlg::OnBnClickedgNbRx)
    ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_GNB, &CNRsystem_GUIDlg::OnTcnSelchangeTabGnb)
END_MESSAGE_MAP()


// CNRsystem_GUIDlg message handlers

BOOL CNRsystem_GUIDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

    m_tab.InsertItem(0, _T("bwp&Carrier Cfg"));
    m_tab.InsertItem(1, _T("coreset&SS Cfg"));
    m_tab.InsertItem(2, _T("SSb Cfg"));

    m_bwpCarrCfg.Create(IDD_BWP_CARR_DLG, &m_tab);
    m_coresetSSCfg.Create(IDD_CORESETSS_DLG, &m_tab);
    m_ssbCfg.Create(IDD_SSB_DLG, &m_tab);

    //show range
    CRect rc;
    m_tab.GetClientRect(rc);
    rc.top += 20;

    m_bwpCarrCfg.MoveWindow(&rc);
    m_coresetSSCfg.MoveWindow(&rc);
    m_ssbCfg.MoveWindow(&rc);

    p_Dlg[0] = &m_bwpCarrCfg;
    p_Dlg[1] = &m_coresetSSCfg;
    p_Dlg[2] = &m_ssbCfg;

    p_Dlg[0]->ShowWindow(SW_SHOW);
    p_Dlg[1]->ShowWindow(SW_HIDE);
    p_Dlg[2]->ShowWindow(SW_HIDE);

    m_CurSelTab = 0;

    m_ueTab.InsertItem(0, _T("UE Tx Configuration"));

    CString str("NR system bring up!!!!");
    m_NrStatusTxt.SetWindowText(str);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CNRsystem_GUIDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CNRsystem_GUIDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CNRsystem_GUIDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CNRsystem_GUIDlg::OnTcnSelchangeTabGnb(NMHDR *pNMHDR, LRESULT *pResult)
{
    // TODO: Add your control notification handler code here
    p_Dlg[m_CurSelTab]->ShowWindow(SW_HIDE);
    m_CurSelTab = m_tab.GetCurSel();
    p_Dlg[m_CurSelTab]->ShowWindow(SW_SHOW);

    *pResult = 0;
}


void CNRsystem_GUIDlg::OnBnClickedgNbTx()
{
    //Nb Tx, gen transmission data files
    gNbTxMain();

    //nrUeRxMain();
}


void CNRsystem_GUIDlg::OnBnClickedNrUeRx()
{
    nrUeRxMain();
	//getTraceInfoPtr();
	int num=MultiByteToWideChar(0,0,getTraceInfoPtr(),-1,NULL,0);
	//CString str("NR system bring up!!!!");
	wchar_t *wide=new wchar_t[num];
	MultiByteToWideChar(0,0,getTraceInfoPtr(),-1,wide,num);
    m_NrStatusTxt.SetWindowText(wide);
	
}


void CNRsystem_GUIDlg::OnBnClickedNrUeTx()
{
    // TODO: Add your control notification handler code here
}


void CNRsystem_GUIDlg::OnBnClickedgNbRx()
{
    // TODO: Add your control notification handler code here
}


