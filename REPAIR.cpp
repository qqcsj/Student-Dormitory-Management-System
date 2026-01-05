// REPAIR.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication4.h"
#include "afxdialogex.h"
#include "REPAIR.h"
#include"CSystemDlg.h"
#include"repairinterface.h"
#include"studentrepair.h"
#include"REPAIRadd.h"

// REPAIR 对话框

IMPLEMENT_DYNAMIC(REPAIR, CDialogEx)

REPAIR::REPAIR(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

REPAIR::~REPAIR()
{
}

void REPAIR::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_REPAIRS, repairlist);
	//设置ListCtrl风格
	DWORD dwStyle = repairlist.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;	//选中某行使整行高亮（只适用与report风格的ListCtrl） 
	dwStyle |= LVS_EX_GRIDLINES;	   //网格线（只适用与report风格的ListCtrl） 
	repairlist.SetExtendedStyle(dwStyle); //设置扩展风格 

	repairlist.InsertColumn(0, TEXT("宿舍号"), 0, 150);//第0列，宽度是100个像素
	repairlist.InsertColumn(1, TEXT("故障描述"), 0, 400);//第一列
	repairlist.InsertColumn(2, TEXT("维修状态"), 0, 200);//第二列

	/*status.AddString(_T("待处理"));
	status.AddString(_T("处理中"));
	status.AddString(_T("已完成"));
	status.SetCurSel(0);*/

	

 // 除非将焦点设置到控件，否则返回 TRUE
	return;
}


BEGIN_MESSAGE_MAP(REPAIR, CDialogEx)
	//ON_BN_CLICKED(IDOK6, &REPAIR::OnBnClickedOk6)
	ON_BN_CLICKED(IDOK, &REPAIR::OnBnClickedOk)
	//ON_BN_CLICKED(IDOK7, &REPAIR::OnBnClickedOk7)
	ON_BN_CLICKED(IDC_BUTTON3, &REPAIR::OnBnClickedButton3)
	//ON_BN_CLICKED(IDOK2, &REPAIR::OnBnClickedOk2)
	ON_BN_CLICKED(IDC_BUTTON1, &REPAIR::OnBnClickedButton1)
	//ON_BN_CLICKED(IDOK4, &REPAIR::OnBnClickedOk4)
	ON_BN_CLICKED(IDCANCEL, &REPAIR::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON4, &REPAIR::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &REPAIR::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &REPAIR::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON2, &REPAIR::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON7, &REPAIR::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &REPAIR::OnBnClickedButton8)
END_MESSAGE_MAP()


// REPAIR 消息处理程序

void REPAIR::updatelist()
{
	repairlist.DeleteAllItems();
	CString str1;
	for (int i = 0; i < rinterface.repairs.size(); i++) {
		str1.Format(TEXT("%d"), rinterface.repairs[i].m_roomid);
		repairlist.InsertItem(i, str1);
		repairlist.SetItemText(i, 1, rinterface.repairs[i].m_repaircontent.c_str());
		repairlist.SetItemText(i, 2, rinterface.repairs[i].m_status.c_str());
	}

}

void REPAIR::OnBnClickedOk6()
{
	// TODO: 在此添加控件通知处理程序代码
	
}

void REPAIR::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}

void REPAIR::OnBnClickedOk7()
{
	// TODO: 在此添加控件通知处理程序代码
}

void REPAIR::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	// 设置过滤器   
	TCHAR szFilter[] = _T("文本文件(*.txt)|*.txt|所有文件(*.*)|*.*||");
	// 构造打开文件对话框   
	CFileDialog fileDlg(TRUE, _T("txt"), NULL, 0, szFilter, this);
	//做了一个过滤，只能打开文本文件（txt)

	// 显示打开文件对话框   
	if (IDOK == fileDlg.DoModal())
	{
		// 如果点击了文件对话框上的“打开”按钮，则将选择的文件路径显示到编辑框里   
		rFilepath = fileDlg.GetPathName();
		rinterface.repairopen(rFilepath);

		updatelist();
	}
}

void REPAIR::OnBnClickedOk2()
{
	// TODO: 在此添加控件通知处理程序代码
}

void REPAIR::OnBnClickedButton1()
{
	// TODO: 添加在此添加控件通知处理程序代码
	REPAIRadd rad2;
	if (IDOK == rad2.DoModal()) {
	 //弹出模式对话框
	 //atoi把CString转成int
			studentrepair myrepairs(atoi(rad2.m_roomid), rad2.m_repaircontent.GetBuffer(), 
				rad2.m_status.GetBuffer());
			rinterface.AddRepair(myrepairs);
			updatelist();

	}
	else {
		MessageBox(TEXT("请先打开文件"), TEXT("提示"));

	}
}

void REPAIR::OnBnClickedOk4()
{
	// TODO: 在此添加控件通知处理程序代码
}

void REPAIR::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}

void REPAIR::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	int index2 = repairlist.GetSelectionMark();
	if (index2 > -1) {
		REPAIRadd radd;
		CString str;
		str.Format(TEXT("%d"), rinterface.repairs[index2].m_roomid);
		radd.m_roomid = str;
		str.Format(TEXT("%s"), rinterface.repairs[index2].m_repaircontent.c_str());
		radd.m_repaircontent = str;
		str.Format(TEXT("%s"), rinterface.repairs[index2].m_status.c_str());
		radd.m_status = str;
		if (IDOK == radd.DoModal()) //弹出模式对话框
		{   //atoi把CString转成int
			studentrepair repairs(atoi(radd.m_roomid), radd.m_repaircontent.GetBuffer(), 
				radd.m_status.GetBuffer());
			rinterface.AmendRepair(index2, repairs);
			updatelist();
		}
	}
	else {
		MessageBox(TEXT("请先点击列表选择需要修改的记录"), TEXT("提示"));
	}
}

void REPAIR::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	CString findText;
	if (!GetDlgItemText(IDC_EDIT7, findText)) { // 使用自定义ID
		MessageBox(TEXT("未检查到维修宿舍填报，请输入维修宿舍号！"), TEXT("错误"));
		return;
	}
	// 验证输入是否为空
	if (findText.IsEmpty()) {
		MessageBox(TEXT("请输入学号号"), TEXT("提示"));
		return;
	}
	// 验证输入是否为有效数字
	int roomId = _ttoi(findText);
	CString strId;
	strId.Format(TEXT("%d"),roomId);

	if (strId != findText) {
		MessageBox(TEXT("请输入有效的维修宿舍号"), TEXT("提示"));
		return;
	}
	// 执行查找
	studentrepair foundrepair = rinterface.Findrepair(roomId);
	// 处理查找结果
	if (foundrepair.m_roomid== -1) {
		MessageBox(TEXT("未找到该维修宿舍记录"), TEXT("查找结果"));
		return;
	}
	// 转换 string 到 CString
	CString rcontent = foundrepair.m_repaircontent.c_str();
	CString rstatus = foundrepair.m_status.c_str();
	// 构建结果消息
	CString msg;
	msg.Format(
		TEXT("查找成功：\n\n宿舍号：%d\n故障描述：%s\n维修状态：%s"),
		foundrepair.m_roomid,rcontent,rstatus);
	MessageBox(msg, TEXT("查找结果"));
}

void REPAIR::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码	
	if (rinterface.repairSave(rFilepath))
		MessageBox(TEXT("已保存！"), TEXT("提示"));
	else
		MessageBox(TEXT("保存失败！"), TEXT("提示"));
}

void REPAIR::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	MessageBox(TEXT("您已退出宿舍管理系统，再见！"), TEXT("温馨提示"));
	EndDialog(0);
}

void REPAIR::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	
}

void REPAIR::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	int index1 = repairlist.GetSelectionMark();
	/*CString str;
	str.Format(TEXT("%d"), index);    判断删除的是哪一行，什么都不选删的是-1
	MessageBox(str);*/
	if (index1 > -1) {
		UINT i;
		i = MessageBox(_T("确定要删除该学生信息吗？"), _T("提示"), MB_YESNO | MB_ICONQUESTION);
		if (i == IDYES)
		{
			rinterface.Delrepair(index1);
			updatelist();
			MessageBox(TEXT("删除成功！"), TEXT("提示"));
		}
		else {
			return;
		}

	}
	else {
		MessageBox(TEXT("请先点击列表选择需要删除的记录"), TEXT("提示"));
	}
}
