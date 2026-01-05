#pragma once
class studentdorm
{
public:
	studentdorm();
	studentdorm(int studentid1, string studentname1 , string studepartment1, string buildingnum1, string roomid1,string stucontact1, string checkresult1, string freestatus1);

	void load(ifstream& in);
	void Save(ofstream& out);
	int studentid;
	string studentname;
	string studepartment;
	string buildingnum;
	string roomid;
	string stucontact;
	string checkresult;
	string freestatus;
};

