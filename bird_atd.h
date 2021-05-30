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
        ~bird();
    };
} // end animals namespace