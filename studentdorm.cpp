#include "pch.h"
#include "studentdorm.h"

studentdorm::studentdorm()
{
}

studentdorm::studentdorm(int studentid1, string studentname1, string studepartment1, string buildingnum1, string roomid1, string stucontact1, string checkresult1, string freestatus1)
{
	studentid = studentid1;
	roomid = roomid1;
	studentname = studentname1;
	buildingnum = buildingnum1;
	studepartment = studepartment1;
	stucontact = stucontact1;
	checkresult = checkresult1;
	freestatus = freestatus1;
}

void studentdorm::load(ifstream& in)
{
	in >> studentid;
	in >> studentname;
	in >> studepartment;
	in >> buildingnum;
	in >> roomid;
	in >> stucontact;
	in >> checkresult;
	in >> freestatus;
}

void studentdorm::Save(ofstream& out)
{
	out << studentid << "\t";
	out << studentname << "\t";
	out << studepartment << "\t";
	out << buildingnum<< "\t";
	out << roomid << "\t";
	out << stucontact << "\t";
	out << checkresult << "\t";
	out << freestatus << "\n";
}


