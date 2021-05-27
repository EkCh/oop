#include <fstream>
#include "bird_atd.h"
using namespace std;
namespace animals {
	// Ввод параметров 
	void bird::input(ifstream& ifst)
	{
		string tmp_name = "";
		int mgr = 0;
		ifst >> tmp_name >> mgr;
		m = migr(mgr);
		name = tmp_name;
	}
	// Вывод параметров 
	void bird::output(ofstream& ofst)
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
		ofst << "Name size: " << name_size() << endl;
	}
	bird::~bird() {}
} // end animals namespace