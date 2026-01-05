#include "pch.h"
#include "studentrepair.h"

studentrepair::studentrepair()
{
}

studentrepair::studentrepair(int roomid, string repaircontent, string status)
{
	this->m_roomid = roomid;
	this->m_repaircontent = repaircontent;
	this->m_status = status;
}

void studentrepair::Load(ifstream& in)
{

	in >> m_roomid;
	in >> m_repaircontent;
	in >> m_status;
}

void studentrepair::repairSave(ofstream& out)
{
	out << m_roomid<< "\t";
	out << m_repaircontent << "\t";
	out << m_status << "\n";
}
