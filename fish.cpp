#include <fstream>
#include "fish_atd.h"
using namespace std;
namespace animals {
	// Ввод параметров 
	void fish::input(ifstream& ifst)
	{
		string tmp_name = "";
		int hab = 0;
		ifst >> tmp_name >> hab;
		h = habitat(hab);
		name = tmp_name;
	}
	// Вывод параметров 
	void fish::output(ofstream& ofst)
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
	}
	fish::~fish() {}
} // end animals namespace