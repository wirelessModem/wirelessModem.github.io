#pragma once


// CnrUePrachCfgDlg dialog

class CnrUePrachCfgDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CnrUePrachCfgDlg)

public:
	CnrUePrachCfgDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CnrUePrachCfgDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_UEPRACH_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
