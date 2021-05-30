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
        
        virtual void Multimethod(animal* other, ofstream& ofst) = 0;
        virtual void MMBird(ofstream& ofst) = 0;
        virtual void MMFish(ofstream& ofst) = 0;
        virtual void MMBeast(ofstream& ofst) = 0;
    };
} // end animals namespac

