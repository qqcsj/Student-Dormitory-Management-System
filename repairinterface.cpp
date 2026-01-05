#include "pch.h"
#include "repairinterface.h"
#include<sstream>

bool repairinterface::repairopen(CString RFilepath)
{
	ifstream in(RFilepath,ios::in);
	if (in.is_open()) {
		int num;//有多少行数据
		in >> num;
		for (int i = 0; i < num; i++) {
			studentrepair myrepairs;
			myrepairs.Load(in);
			repairs.push_back(myrepairs);
		}
		return true;
	}
	return false;
}

void repairinterface::AddRepair(studentrepair repair)
{
	repairs.push_back(repair);
}

void repairinterface::AmendRepair(int index, studentrepair myrepairs)
{
	if (index >= 0 && index < repairs.size())
	     repairs[index] = myrepairs;
}




bool repairinterface::repairSave(CString RFilepath)
{
	ofstream out(RFilepath, ios::out);
	if (out.is_open())
	{
		out << repairs.size() << endl;
		for (int i = 0; i < repairs.size(); i++) {
			repairs[i].repairSave(out);
		}
		out.close();
		return true;
	}
	return false;
}

studentrepair repairinterface::Findrepair(int findrepair)
{
	for (int i = 0; i < repairs.size(); i++) {
		if (repairs[i].m_roomid == findrepair) {
			return repairs[i];

		}
	}
	return studentrepair(-1, "", "");
	
}

void repairinterface::Delrepair(int index1)
{
	repairs.erase(repairs.begin() + index1);
}

