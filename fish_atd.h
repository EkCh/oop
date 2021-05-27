#include "animal_atd.h"
#include <fstream>
#pragma once
namespace animals {
    class fish : public animal
    {
        enum habitat { RIVER, SEA, LAKE };

    public:
        habitat h; // место проживания

        void input(std::ifstream& ifst);
        void output(std::ofstream& ofst);
        ~fish();
    };
} // end animals namespace
