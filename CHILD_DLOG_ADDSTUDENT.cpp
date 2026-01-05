// CHILD_DLOG_ADDSTUDENT.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication4.h"
#include "afxdialogex.h"
#include "CHILD_DLOG_ADDSTUDENT.h"


// CHILD_DLOG_ADDSTUDENT 对话框

IMPLEMENT_DYNAMIC(CHILD_DLOG_ADDSTUDENT, CDialogEx)

CHILD_DLOG_ADDSTUDENT::CHILD_DLOG_ADDSTUDENT(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CHILD_DIALOG_ADDSTUDENT, pParent)
	, studentid(_T(""))
	, studentname(_T(""))
	, studepartment(_T(""))
	, buildingnum(_T(""))
	, roomid(_T(""))
	, stucontact(_T(""))
	
	, checkresult(_T(""))
	, freestatus(_T(""))
{

}

CHILD_DLOG_ADDSTUDENT::~CHILD_DLOG_ADDSTUDENT()
{
}

void CHILD_DLOG_ADDSTUDENT::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_EDIT1, studentid);
	DDX_Text(pDX, IDC_EDIT3, studentname);
	DDX_Text(pDX, IDC_EDIT4, studepartment);
	DDX_Text(pDX, IDC_EDIT5, buildingnum);
	DDX_Text(pDX, IDC_EDIT6, roomid);
	DDX_Text(pDX, IDC_EDIT7, stucontact);
	//  DDX_Text(pDX, IDC_EDIT1, studentid);
	DDX_Text(pDX, IDC_EDIT1, studentid);
	DDX_Text(pDX, IDC_EDIT2, checkresult);
	DDX_Text(pDX, IDC_EDIT8, freestatus);
}


BEGIN_MESSAGE_MAP(CHILD_DLOG_ADDSTUDENT, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &CHILD_DLOG_ADDSTUDENT::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT3, &CHILD_DLOG_ADDSTUDENT::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT5, &CHILD_DLOG_ADDSTUDENT::OnEnChangeEdit5)
	ON_EN_CHANGE(IDC_EDIT6, &CHILD_DLOG_ADDSTUDENT::OnEnChangeEdit6)
	ON_BN_CLICKED(IDC_BUTTON1, &CHILD_DLOG_ADDSTUDENT::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CHILD_DLOG_ADDSTUDENT::OnBnClickedButton2)
	ON_EN_CHANGE(IDC_EDIT4, &CHILD_DLOG_ADDSTUDENT::OnEnChangeEdit4)
	ON_EN_CHANGE(IDC_EDIT2, &CHILD_DLOG_ADDSTUDENT::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT8, &CHILD_DLOG_ADDSTUDENT::OnEnChangeEdit8)
	ON_EN_CHANGE(IDC_EDIT7, &CHILD_DLOG_ADDSTUDENT::OnEnChangeEdit7)
END_MESSAGE_MAP()


// CHILD_DLOG_ADDSTUDENT 消息处理程序


void CHILD_DLOG_ADDSTUDENT::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CHILD_DLOG_ADDSTUDENT::OnEnChangeEdit3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CHILD_DLOG_ADDSTUDENT::OnEnChangeEdit5()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CHILD_DLOG_ADDSTUDENT::OnEnChangeEdit6()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CHILD_DLOG_ADDSTUDENT::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);//把编辑的信息绑定到变量上面
	if (studentid == TEXT("") || studentname == TEXT("") || studepartment == TEXT("")
		|| buildingnum == TEXT("") || roomid == TEXT("") || stucontact == TEXT(""))
	{
		MessageBox(TEXT("您有输入为空，请补充完整"),TEXT("提示"));
	}
	else {
		OnOK();//退出对话框
		return;
	}
}


void CHILD_DLOG_ADDSTUDENT::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	EndDialog(0);

}

void CHILD_DLOG_ADDSTUDENT::OnEnChangeEdit4()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

void CHILD_DLOG_ADDSTUDENT::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

void CHILD_DLOG_ADDSTUDENT::OnEnChangeEdit8()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

void CHILD_DLOG_ADDSTUDENT::OnEnChangeEdit7()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
