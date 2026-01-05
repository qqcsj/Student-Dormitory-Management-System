// REPAIRadd.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication4.h"
#include "afxdialogex.h"
#include "REPAIRadd.h"


// REPAIRadd 对话框

IMPLEMENT_DYNAMIC(REPAIRadd, CDialogEx)

REPAIRadd::REPAIRadd(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_REPAIRADD, pParent)
	, m_roomid(_T(""))
	, m_repaircontent(_T(""))
	, m_status(_T(""))
{

}

REPAIRadd::~REPAIRadd()
{
}

void REPAIRadd::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_roomid);
	DDX_Text(pDX, IDC_EDIT3, m_repaircontent);
	//  DDX_Control(pDX, IDC_COMBO1, m_status);
	//  DDX_CBString(pDX, IDC_COMBO1, status);
	DDX_CBString(pDX, IDC_COMBO1, m_status);
}


BEGIN_MESSAGE_MAP(REPAIRadd, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &REPAIRadd::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &REPAIRadd::OnBnClickedButton2)
	ON_CBN_SELCHANGE(IDC_COMBO1, &REPAIRadd::OnCbnSelchangeCombo1)
END_MESSAGE_MAP()


// REPAIRadd 消息处理程序

void REPAIRadd::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);//把编辑的信息绑定到变量上面
	if (m_roomid == TEXT("") || m_repaircontent == TEXT("") || m_status == TEXT(""))
	{
		MessageBox(TEXT("您有输入为空，请补充完整"), TEXT("提示"));
	}
	else {
		OnOK();//退出对话框
		return;
	}
}

void REPAIRadd::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
}

void REPAIRadd::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
}
