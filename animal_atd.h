#pragma once
#include <string>
#include <fstream>
namespace animals {

    class animal
    {
    public:
        std::string name;    // название

        virtual ~animal() {};
        static animal* in(std::ifstream& ifst);
        virtual void input(std::ifstream& ifst) = 0;
        virtual void output(std::ofstream& ofst) = 0;
        virtual int name_size();
        bool compare(animal* other);
    };

} // end animals namespac

