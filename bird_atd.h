#pragma once
#include <fstream>
#include "animal_atd.h"

namespace animals 
{
    class bird : public animal
    {
        enum migr { MIGRANT, NONMIGRANT };

    public:
        migr m; // перелетность

        void Input(std::ifstream& ifst);
        void Output(std::ofstream& ofst);
        void Multimethod(animal* other, ofstream& ofst);
        void MMBird(ofstream& ofst);
        void MMFish(ofstream& ofst);
        void MMBeast(ofstream& ofst);
        ~bird();
    };
} // end animals namespace