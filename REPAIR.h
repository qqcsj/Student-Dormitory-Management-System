#pragma once
#include "afxdialogex.h"
#include "studentdorm.h"  
#include"repairinterface.h"
// REPAIR 对话框

class REPAIR : public CDialogEx
{
	DECLARE_DYNAMIC(REPAIR)

public:
	REPAIR(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~REPAIR();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	
	CString roomid;//维修宿舍号
	CString content;//故障描述
	CString status;//状态
	repairinterface rinterface;
	CListCtrl repairlist;
	CString rFilepath;
	void updatelist();
	//void RefreshRepairList(const std::vector<studentrepair>& repairs);
	afx_msg void OnBnClickedOk6();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedOk7();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedOk2();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedOk4();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
};
