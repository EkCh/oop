#include <fstream>
#include "beast_atd.h"
using namespace std;

namespace animals 
{
	// Ввод параметров 
	void beast::input(ifstream& ifst)
	{
		string tmp_name = "";
		int prf = 0;
		ifst >> tmp_name >> prf;
		p = pref(prf);
		name = tmp_name;
	}
	// Вывод параметров 
	void beast::output(ofstream& ofst)
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
	beast::~beast() {}
} // end animals namespace