#include <fstream>
#include <iostream>
#include "bird_atd.h"
using namespace std;

namespace animals 
{
	// Ввод параметров 
	void bird::Input(ifstream& ifst)
	{
		string tmp_name = "";
		int mgr = 0;
		long tmp_age = 0;

		ifst >> tmp_name;
		if (ifst.fail())
		{
			cout << "Error! Unexpected end of input!" << endl;
			exit(1);
		}
		name = tmp_name;

		ifst >> mgr;
		if (ifst.fail())
		{
			cout << "Error! Unexpected end of input!" << endl;
			exit(1);
		}
		if (mgr < 0 || mgr > 1)
		{
			cout << "Error! The range is <0-1>!" << endl;
			exit(1);
		}
		m = migr(mgr);
		
		ifst >> tmp_age;
		if (ifst.fail())
		{
			cout << "Error! Unexpected end of input!" << endl;
			exit(1);
		}
		if (tmp_age < 0)
		{
			cout << "Error! Age can not be negative!" << endl;
			exit(1);
		}
		age = tmp_age;
	}

	// Вывод параметров 
	void bird::Output(ofstream& ofst)
	{
		ofst << "It is bird: " << name << ", it is ";
		switch (m) {
		case MIGRANT:
			ofst << "migrant" << endl;
			break;
		case NONMIGRANT:
			ofst << "nonmigrant" << endl;
			break;
		}
		ofst << "Age: " << age << endl;
		ofst << "Name size: " << NameSize() << endl;
	}

	bird::~bird() {}
} // end animals namespace