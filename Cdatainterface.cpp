#include "pch.h"
#include "Cdatainterface.h"

bool Cdatainterface::Open(CString FilePath)
{
	ifstream in(FilePath,ios::in);
	if (in.is_open()) {
		int num;//记录有多少条数据
		in >> num;
		for (int i = 0; i < num; i++) {
			studentdorm mysd;
			mysd.load(in);
			sd.push_back(mysd);
		}
		return true;
	}


	return false;
}

void Cdatainterface::Add(studentdorm mysd)
{
	sd.push_back(mysd);

}

void Cdatainterface::Del(int index)
{
	sd.erase(sd.begin()+index);

}

void Cdatainterface::Amend(int index, studentdorm mysd)
{
	sd[index] = mysd;

}

studentdorm Cdatainterface::Find(int find)
{
	for (int i = 0; i < sd.size(); i++) {
		if (sd[i].studentid == find) {
			return sd[i];
			
		}
	}
	return studentdorm(-1, "", "", "", "", "","","");
}

bool Cdatainterface::Save(CString FilePath)
{
	ofstream out(FilePath,ios::out);
	if (out.is_open())
	{
		out << sd.size() << endl;
		for (int i = 0; i < sd.size(); i++) {
			sd[i].Save(out);
		}
		out.close();
		return true;
	}
	return false;
}
