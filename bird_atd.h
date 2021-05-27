#pragma once
#include <fstream>
#include "animal_atd.h"

namespace animals {
    class bird : public animal
    {
        enum migr { MIGRANT, NONMIGRANT };

    public:
        migr m; // перелетность

        void input(std::ifstream& ifst);
        void output(std::ofstream& ofst);
        ~bird();
    };
} // end animals namespace