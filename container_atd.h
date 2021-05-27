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
        ~node();
    };

    struct container
    {
    public:
        long size;
        node* head;


        void in(std::ifstream& ifst);
        void out(std::ofstream& ofst);
        void clear();
        node* get_node(int index);
        void swap(int index_first, int index_second);
        void sort();

        container();
        ~container();
    };
} // end animals namespace
