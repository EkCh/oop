#pragma once
#include "animal_atd.h"
#include <fstream>
namespace animals {

    class node
    {
    public:
        animal* an;
        node* next;

        bool add_node(std::ifstream& ifst);
        bool out_node(std::ofstream& ofst);
        bool out_node_fish(std::ofstream& ofst);
        ~node();
    };

    struct container
    {
    public:
        long size;
        node* head;

        void in(std::ifstream& ifst);
        void out(std::ofstream& ofst);
        void output_fish(std::ofstream& ofst);
        void clear();

        container();
        ~container();
    };
} // end animals namespace
