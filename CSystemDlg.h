#pragma once
#include "afxdialogex.h"
#include "Cdatainterface.h"
#include"repairinterface.h"
#include"REPAIR.h"
// CSystemDlg 对话框

class CSystemDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSystemDlg)

public:
	CSystemDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CSystemDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SYSTEM };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLvnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
	CListCtrl list;
	Cdatainterface datainterface;
	repairinterface rinterface;
	CListCtrl repairlist;
	
	CString strFilePath;
	void UpdataList();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton7();
	bool isopen;
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton6();
	CString find;
	afx_msg void OnBnClickedButton2();
};
