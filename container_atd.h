#pragma once
#include "animal_atd.h"
#include <fstream>
namespace animals 
{
    class node
    {
    public:
        animal* an;
        node* next;

        bool AddNode(std::ifstream& ifst);
        bool OutNode(std::ofstream& ofst);
        bool OutNodeFish(std::ofstream& ofst);
        ~node();
    };

    struct container
    {
    public:
        long size;
        node* head;

        void In(std::ifstream& ifst);
        void Out(std::ofstream& ofst);
        void OutFish(std::ofstream& ofst);
        void Clear();
        node* GetNode(int index);
        void Swap(int index_first, int index_second);
        void Sort();

        container();
        ~container();
    };
} // end animals namespace
