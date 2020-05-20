#pragma once


// CBwpCarrierCfgDlg dialog

class CBwpCarrierCfgDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CBwpCarrierCfgDlg)

public:
	CBwpCarrierCfgDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CBwpCarrierCfgDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BWP_CARR_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
