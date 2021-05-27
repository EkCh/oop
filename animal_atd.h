#pragma once
#include <string>
#include <fstream>
namespace animals {
	
    class animal
    {
    public:
        std::string name;    // название
        long age;

        virtual ~animal() {};
        static animal* in(std::ifstream& ifst);
        virtual void input(std::ifstream& ifst) = 0;
        virtual void output(std::ofstream& ofst) = 0;
    };

} // end animals namespac

