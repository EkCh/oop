#include <fstream>
#include <iostream>
#include "beast_atd.h"
using namespace std;

namespace animals 
{
	// Ввод параметров 
	void beast::Input(ifstream& ifst)
	{
		string tmp_name = "";
		int prf = 0;

		ifst >> tmp_name;
		if (ifst.fail())
		{
			cout << "Error! Unexpected end of input!" << endl;
			exit(1);
		}
		name = tmp_name;

		ifst >> prf;
		if (ifst.fail())
		{
			cout << "Error! Unexpected end of input!" << endl;
			exit(1);
		}
		if (prf < 0 || prf > 2)
		{
			cout << "Error! The range is <0-2>!" << endl;
			exit(1);
		}
		p = pref(prf);
	}

	// Вывод параметров 
	void beast::Output(ofstream& ofst)
	{
		ofst << "It is beast: " << name << ", it is ";
		switch (p) {
		case PREDATOR:
			ofst << "predator" << endl;
			break;
		case HERBIVORE:
			ofst << "herbivore" << endl;
			break;
		case INSECTIVORE:
			ofst << "insectivore" << endl;
			break;
		}
	}

	void beast::Multimethod(animal* other, ofstream& ofst)
	{
		other->MMBeast(ofst);
	}
	void beast::MMBird(ofstream& ofst)
	{
		ofst << "Bird and beast" << endl;
	}
	void beast::MMFish(ofstream& ofst)
	{
		ofst << "Fish and beast" << endl;
	}
	void beast::MMBeast(ofstream& ofst)
	{
		ofst << "Beast and beast" << endl;
	}

	beast::~beast() {}
} // end animals namespace