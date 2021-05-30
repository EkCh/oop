#include <fstream>
#include "animal_atd.h"
#pragma once
namespace animals 
{
    class beast : public animal
    {
        enum pref { PREDATOR, HERBIVORE, INSECTIVORE };

    public:
        pref p;

        void Input(std::ifstream& ifst);
        void Output(std::ofstream& ofst);
        ~beast();
    };
} // end animals namespace