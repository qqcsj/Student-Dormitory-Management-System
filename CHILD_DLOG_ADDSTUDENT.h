#pragma once
#include "afxdialogex.h"


// CHILD_DLOG_ADDSTUDENT 对话框

class CHILD_DLOG_ADDSTUDENT : public CDialogEx
{
	DECLARE_DYNAMIC(CHILD_DLOG_ADDSTUDENT)

public:
	CHILD_DLOG_ADDSTUDENT(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CHILD_DLOG_ADDSTUDENT();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHILD_DIALOG_ADDSTUDENT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnEnChangeEdit5();
	afx_msg void OnEnChangeEdit6();
//	CString studentid;
	CString studentname;
	CString studepartment;
	CString buildingnum;
	CString roomid;
	CString stucontact;
	afx_msg void OnBnClickedButton1();
//	int studentid;
	CString studentid;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnEnChangeEdit4();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEdit8();
	afx_msg void OnEnChangeEdit7();
	CString checkresult;
	CString freestatus;
};
