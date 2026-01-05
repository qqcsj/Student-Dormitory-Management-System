#pragma once
#include "afxdialogex.h"


// REPAIRadd 对话框

class REPAIRadd : public CDialogEx
{
	DECLARE_DYNAMIC(REPAIRadd)

public:
	REPAIRadd(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~REPAIRadd();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_REPAIRADD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_roomid;
	CString m_repaircontent;
//	CComboBox m_status;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnCbnSelchangeCombo1();
//	CString status;
	CString m_status;
};
