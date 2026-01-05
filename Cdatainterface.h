#pragma once
#include"studentdorm.h"
class Cdatainterface
{
public:
	bool Open(CString FilePath);//判断文件是否打开成功
	void Add(studentdorm mysd);//添加学生
	void Del(int index);//删除学生,删除哪个学号的
	void Amend(int studentid, studentdorm mysd);//改学号，用新的把旧的覆盖掉
	studentdorm Find(int find);//查找学生,根据学号来查找
	bool Save(CString FilePath);
	vector<studentdorm>sd;
};

