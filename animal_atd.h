#pragma once
#include <string>
#include <fstream>
using namespace std;

namespace animals 
{
    class animal
    {
    public:
        std::string name; 
        long age;

        virtual ~animal() {};
        static animal* In(std::ifstream& ifst);
        virtual void Input(std::ifstream& ifst) = 0;
        virtual void Output(std::ofstream& ofst) = 0;
        virtual int NameSize();
        bool Compare(animal* other);
        virtual void OutFish(std::ofstream& ofst);

    };
} // end animals namespac

