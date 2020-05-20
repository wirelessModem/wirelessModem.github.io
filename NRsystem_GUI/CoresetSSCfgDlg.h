#pragma once


// CCoresetSSCfgDlg dialog

class CCoresetSSCfgDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCoresetSSCfgDlg)

public:
	CCoresetSSCfgDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CCoresetSSCfgDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CORESETSS_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
