#pragma once
#include <string>
#include <fstream>
using namespace std;
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
<<<<<<< HEAD
        virtual int name_size();
        bool compare(animal* other);
=======
        virtual void output_fish(std::ofstream& ofst);
>>>>>>> new_output
    };

} // end animals namespac

