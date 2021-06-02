#include <fstream>
#include "animal_atd.h"
#include "fish_atd.h"
#include "bird_atd.h"
#include "beast_atd.h"

using namespace std;
namespace animals 
{
	// Ââîä ïàðàìåòðîâ èç ôàéëà
	animal* animal::In(ifstream& ifst)
	{
		animal* an;
		int k;
		ifst >> k;
		
		if (ifst.fail())
		{
			cout << "Error! Wrong key input!" << endl;
			exit(1);
		}
		
		if ((k < 0) || (k > 2))
		{
			cout << "Error! The key range is <0-2>!" << endl;
			exit(1);
		}
		
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

		an->Input(ifst);
		return an;
	}

	int animal::NameSize()
	{
		return (name.size());
	}

	bool animal::Compare(animal* other)
	{
		return NameSize() < other->NameSize();
	}

	void animal::OutFish(std::ofstream& ofst)
	{
		ofst << endl; // ïóñòàÿ ñòðîêà
	}
} // end animals namespace
