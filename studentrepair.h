#pragma once
#include"studentdorm.h"
#include "Cdatainterface.h"

class studentrepair
{
public:
	studentrepair();
	studentrepair(int roomid, string repaircontent, string status);
	void Load(ifstream&in);
	void repairSave(ofstream& out);
	int m_roomid;
	string m_repaircontent;
	string m_status;
};

