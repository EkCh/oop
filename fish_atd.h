#pragma once
#include "animal_atd.h"
#include <fstream>

namespace animals 
{
    class fish : public animal
    {
        enum habitat { RIVER, SEA, LAKE };

    public:
        habitat h; // место проживания

        void Input(std::ifstream& ifst);
        void Output(std::ofstream& ofst);
        void OutFish(std::ofstream& ofst);
        ~fish();
    };
} // end animals namespace
