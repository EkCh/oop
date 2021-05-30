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
        void Multimethod(animal* other, ofstream& ofst);
        void MMBird(ofstream& ofst);
        void MMFish(ofstream& ofst);
        void MMBeast(ofstream& ofst);
        ~fish();
    };
} // end animals namespace
