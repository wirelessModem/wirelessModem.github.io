
// NRsystem_GUIDlg.h : header file
//

#pragma once
#include "afxcmn.h"
#include "BwpCarrierCfgDlg.h"
#include "CoresetSSCfgDlg.h"
#include "SsbCfgDlg.h"
#include "CnrUePrachCfgDlg.h"

#include "excel.h"

#include "afxwin.h"


// CNRsystem_GUIDlg dialog
class CNRsystem_GUIDlg : public CDialogEx
{
// Construction
public:
	CNRsystem_GUIDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_NRSYSTEM_GUI_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedgNbTx();
    afx_msg void OnBnClickedNrUeRx();
    afx_msg void OnBnClickedNrUeTx();
    afx_msg void OnBnClickedgNbRx();

    afx_msg void OnTcnSelchangeTabGnb(NMHDR *pNMHDR, LRESULT *pResult);
    afx_msg void OnBnClickedNbTxView();
    afx_msg void OnBnClickedUeRxView();


    CTabCtrl m_tab;

    int m_CurSelTab;
    CBwpCarrierCfgDlg m_bwpCarrCfg;
    CCoresetSSCfgDlg  m_coresetSSCfg;
    CSsbCfgDlg        m_ssbCfg;
    CDialogEx        *p_Dlg[4];

    CnrUePrachCfgDlg  m_nrUePrachCfg;



    
    CTabCtrl m_ueTab;
    CEdit m_NrStatusTxt;
    
    //CexcelAccess m_excelAccess;
};
