// CSystemDlg.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication4.h"
#include "afxdialogex.h"
#include "CSystemDlg.h"
#include"CHILD_DLOG_ADDSTUDENT.h"
#include"REPAIR.h"


// CSystemDlg 对话框

IMPLEMENT_DYNAMIC(CSystemDlg, CDialogEx)

CSystemDlg::CSystemDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_SYSTEM, pParent)
	, find(_T(""))
{

}

CSystemDlg::~CSystemDlg()
{
}

void CSystemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, list);
	CString rFilepath;
	//设置ListCtrl风格
	DWORD dwStyle = list.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;	//选中某行使整行高亮（只适用与report风格的ListCtrl） 
	dwStyle |= LVS_EX_GRIDLINES;	   //网格线（只适用与report风格的ListCtrl） 
	list.SetExtendedStyle(dwStyle); //设置扩展风格 

	list.InsertColumn(0, TEXT("学号"), 0, 150);//第0列，宽度是100个像素
	list.InsertColumn(1, TEXT("姓名"), 0, 150);//第一列
	list.InsertColumn(2, TEXT("院系"), 0, 200);//第二列
	list.InsertColumn(3, TEXT("宿舍楼栋号"), 0, 150);//第三列
	list.InsertColumn(4, TEXT("宿舍号"), 0, 150);//第四列
	list.InsertColumn(5, TEXT("联系方式"), 0, 220);//第五列
	list.InsertColumn(6, TEXT("卫生情况"), 0, 150);//第五列
	list.InsertColumn(7, TEXT("缴费状态"), 0, 150);//第五列
	DDX_Text(pDX, IDC_EDIT2, find);
	isopen = false;
	return;
}


BEGIN_MESSAGE_MAP(CSystemDlg, CDialogEx)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CSystemDlg::OnLvnItemchangedList1)
	ON_BN_CLICKED(IDC_BUTTON1, &CSystemDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CSystemDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON5, &CSystemDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON7, &CSystemDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON4, &CSystemDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON6, &CSystemDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON2, &CSystemDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CSystemDlg 消息处理程序


void CSystemDlg::OnLvnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	
	*pResult = 0;
}


void CSystemDlg::UpdataList()
{
	list.DeleteAllItems();//将列表行全部清空
	CString str;
	for (int i = 0; i < datainterface.sd.size(); i++) {
		str.Format(TEXT("%d"), datainterface.sd[i].studentid);
		list.InsertItem(i, str);
		// 姓名设置
		CString name = CString(datainterface.sd[i].studentname.c_str());
		list.SetItemText(i, 1, name);
		// 院系设置
		CString dept = CString(datainterface.sd[i].studepartment.c_str());
		list.SetItemText(i, 2, dept);
		// 宿舍楼栋号设置
		CString building = CString(datainterface.sd[i].buildingnum.c_str());
		list.SetItemText(i, 3, building);
		// 宿舍号设置
		CString room = CString(datainterface.sd[i].roomid.c_str());
		list.SetItemText(i, 4, room);
		// 联系方式设置
		CString contact = CString(datainterface.sd[i].stucontact.c_str());
		list.SetItemText(i, 5, contact);
		// 联系方式设置
		CString cresult = CString(datainterface.sd[i].checkresult.c_str());
		list.SetItemText(i, 6, cresult);
		// 联系方式设置
		CString frees = CString(datainterface.sd[i].freestatus.c_str());
		list.SetItemText(i, 7, frees);
		
	}

}

void CSystemDlg::OnBnClickedButton1()//按钮的响应函数
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
		strFilePath = fileDlg.GetPathName();
		datainterface.Open(strFilePath);
		isopen = true;
		UpdataList();
	}
}


void CSystemDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	
	UINT i;
	i = MessageBox(_T("确定要退出宿舍管理系统吗？"), _T("提示"), MB_YESNO | MB_ICONQUESTION);
	if (i == IDYES)
	{
		CDialogEx::OnOK();
		REPAIR repair;
		repair.DoModal();
		
	}
	else {
		return;
	}

}


void CSystemDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	if (isopen) {
		int index = list.GetSelectionMark();/*CString str;
		str.Format(TEXT("%d"), index);    判断删除的是哪一行，什么都不选删的是-1
		MessageBox(str);*/
		if (index > -1) {
			UINT i;
			i = MessageBox(_T("确定要删除该学生信息吗？"), _T("提示"), MB_YESNO | MB_ICONQUESTION);
			if (i == IDYES)
			{
				datainterface.Del(index);
				UpdataList();
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
	else {
		MessageBox(TEXT("请先打开文件"), TEXT("提示"));
	}
}


void CSystemDlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	if (isopen) {
		// 直接通过控件ID获取编辑框内容（使用自定义ID "find"）
		CString findText;
		if (!GetDlgItemText(IDC_EDIT2_find , findText)) { // 使用自定义ID
			MessageBox(TEXT("获取输入框失败，请检查ID"), TEXT("错误"));
			return;
		}

		// 验证输入是否为空
		if (findText.IsEmpty()) {
			MessageBox(TEXT("请输入学号"), TEXT("提示"));
			return;
		}

		// 验证输入是否为有效数字
		int studentId = _ttoi(findText);
		CString strId;
		strId.Format(TEXT("%d"), studentId);

		if (strId != findText) {
			MessageBox(TEXT("请输入有效的数字学号"), TEXT("提示"));
			return;
		}

		// 执行查找
		studentdorm foundStudent = datainterface.Find(studentId);

		// 处理查找结果
		if (foundStudent.studentid == -1) {
			MessageBox(TEXT("未找到该学生"), TEXT("查找结果"));
			return;
		}

		// 转换 string 到 CString
		CString name = foundStudent.studentname.c_str();
		CString dept = foundStudent.studepartment.c_str();
		CString building = foundStudent.buildingnum.c_str();
		CString room = foundStudent.roomid.c_str();
		CString contact = foundStudent.stucontact.c_str();
		CString check = foundStudent.checkresult.c_str();
		CString free = foundStudent.freestatus.c_str();

		// 构建结果消息
		CString msg;
		msg.Format(
			TEXT("查找成功：\n\n学号：%d\n姓名：%s\n院系：%s\n宿舍楼栋号：%s\n宿舍号：%s\n联系方式：%s\n卫生情况：%s\n缴费状态：%s"),
			foundStudent.studentid, name, dept, building, room, contact,check,free);

		MessageBox(msg, TEXT("查找结果"));
	}
	else {
		MessageBox(TEXT("请先打开文件"), TEXT("提示"));
	}
}


void CSystemDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	if (isopen) {
		CHILD_DLOG_ADDSTUDENT dlg;
		if (IDOK == dlg.DoModal()) //弹出模式对话框
		{   //atoi把CString转成int
			studentdorm sd(atoi(dlg.studentid), dlg.studentname.GetBuffer(),
				dlg.studepartment.GetBuffer(), dlg.buildingnum.GetBuffer(),
				dlg.roomid.GetBuffer(), dlg.stucontact.GetBuffer(),
				dlg.checkresult.GetBuffer(), dlg.freestatus.GetBuffer());
			datainterface.Add(sd);
			UpdataList();

		}
	}
	else {
		MessageBox(TEXT("请先打开文件"), TEXT("提示"));

	}
}


void CSystemDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	if (isopen) {
		int index = list.GetSelectionMark();
		if (index > -1) {
			CHILD_DLOG_ADDSTUDENT dlg;
			CString str;
			str.Format(TEXT("%d"), datainterface.sd[index].studentid);
			dlg.studentid = str;
			str.Format(TEXT("%s"), datainterface.sd[index].studentname.c_str());
			dlg.studentname = str;
			str.Format(TEXT("%s"), datainterface.sd[index].studepartment.c_str());
			dlg.studepartment = str;
			str.Format(TEXT("%s"), datainterface.sd[index].buildingnum.c_str());
			dlg.buildingnum = str;
			str.Format(TEXT("%s"), datainterface.sd[index].roomid.c_str());
			dlg.roomid = str;
			str.Format(TEXT("%s"), datainterface.sd[index].stucontact.c_str());
			dlg.stucontact = str;
			str.Format(TEXT("%s"), datainterface.sd[index].checkresult.c_str());
			dlg.checkresult = str;
			str.Format(TEXT("%s"), datainterface.sd[index].freestatus.c_str());
			dlg.freestatus = str;
			if (IDOK == dlg.DoModal()) //弹出模式对话框
			{   //atoi把CString转成int
				studentdorm sd(atoi(dlg.studentid), dlg.studentname.GetBuffer(), 
					dlg.studepartment.GetBuffer(), dlg.buildingnum.GetBuffer(), 
					dlg.roomid.GetBuffer(), dlg.stucontact.GetBuffer(),
					dlg.checkresult.GetBuffer(), dlg.freestatus.GetBuffer());
				datainterface.Amend(index, sd);
				UpdataList();
			}
		}
		else {
			MessageBox(TEXT("请先点击列表选择需要修改的记录"), TEXT("提示"));
		}
	}
	else {
		MessageBox(TEXT("请先打开文件"), TEXT("提示"));
	}
}


void CSystemDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码

	if (isopen) {
		if (datainterface.Save(strFilePath))
			MessageBox(TEXT("已保存！"), TEXT("提示"));
		else
			MessageBox(TEXT("保存失败！"), TEXT("提示"));
	}
	else {
		MessageBox(TEXT("请先打开文件"), TEXT("提示"));
	}
}
