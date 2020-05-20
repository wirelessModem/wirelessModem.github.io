#pragma once


// CSsbCfgDlg dialog

class CSsbCfgDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSsbCfgDlg)

public:
	CSsbCfgDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CSsbCfgDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SSB_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
