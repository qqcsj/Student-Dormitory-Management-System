#pragma once
#include"studentrepair.h"
class repairinterface
{
public:

	bool repairopen(CString RFilepath);
	void AddRepair(studentrepair repair);
	void AmendRepair(int index,studentrepair myrepairs);//删除学生,删除哪个学号的
	bool repairSave(CString RFilepath);
	studentrepair Findrepair(int findrepair);//查找学生,根据学号来查找

	void Delrepair(int index1);//删除学生,删除哪个学号的
	vector< studentrepair>repairs;
	
};

