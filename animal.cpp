#include <fstream>
#include "animal_atd.h"
#include "fish_atd.h"
#include "bird_atd.h"
#include "beast_atd.h"

using namespace std;
namespace animals {
	// Ввод параметров из файла
	animal* animal::in(ifstream& ifst)
	{
		animal* an;
		int k;
		ifst >> k;
		switch (k)
		{
		case 1:
			an = new fish;
			break;
		case 2:
			an = new bird;
			break;
		case 3:
			an = new beast;
			break;
		default:
			return 0;
		}

		an->input(ifst);
		return an;
	}

	int animal::name_size()
	{
		return (name.size());
	}

	bool animal::compare(animal* other)
	{
		return name_size() < other->name_size();
	}

	void animal::output_fish(std::ofstream& ofst)
	{
		ofst << endl; // пустая строка
	}

} // end animals namespace