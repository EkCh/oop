#include <fstream>
#include <iostream>
#include "fish_atd.h"
using namespace std;

namespace animals 
{
	// Ввод параметров 
	void fish::Input(ifstream& ifst)
	{
		string tmp_name = "";
		int hab = 0;
		long tmp_age = 0;

		ifst >> tmp_name;
		if (ifst.fail())
		{
			cout << "Error! Unexpected end of input!" << endl;
			exit(1);
		}
		name = tmp_name;

		ifst >> hab;
		if (ifst.fail())
		{
			cout << "Error! Unexpected end of input!" << endl;
			exit(1);
		}
		if (hab < 0 || hab > 2)
		{
			cout << "Error! The range is <0-2>!" << endl;
			exit(1);
		}
		h = habitat(hab);

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
	void fish::Output(ofstream& ofst)
	{
		ofst << "It is fish: " << name << ", it lives in ";
		switch (h) {
		case RIVER:
			ofst << "river" << endl;
			break;
		case SEA:
			ofst << "sea" << endl;
			break;
		case LAKE:
			ofst << "lake" << endl;
			break;
		}
		ofst << "Age: " << age << endl;
		ofst << "Name size: " << NameSize() << endl;

	}
	fish::~fish() {}

	void fish::OutFish(std::ofstream& ofst)
	{
		Output(ofst);
	}

} // end animals namespace