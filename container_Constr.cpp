#include <fstream>
#include "container_atd.h"
using namespace std;
namespace animals {

	node::~node() {}

	bool node::add_node(ifstream& ifst)
	{
		an = animal::in(ifst);

		if (an == NULL)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	void container::in(ifstream& ifst)
	{
		while (!ifst.eof())
		{
			node* tmpNode = new node;
			if (tmpNode->add_node(ifst))
			{
				size++;
				if (head != NULL)
				{
					tmpNode->next = head;
					head = tmpNode;
				}
				else
				{
					tmpNode->next = NULL;
					head = tmpNode;
				}
			}
		}
	}

	bool node::out_node(ofstream& ofst)
	{
		an->output(ofst);
		return true;
	}

	void container::out(ofstream& ofst)
	{
		ofst << "Container contains " << size << " elements. " << endl;
		node* curNode = head;
		int i = 0;

		while (curNode != NULL)
		{
			ofst << i << ": ";
			curNode->out_node(ofst);
			curNode = curNode->next;
			i++;
		}
	}

	// Очистка контейнера от элементов
	void container::clear()
	{
		node* curNode;
		curNode = head;
		while (curNode != NULL)
		{
			node* temp = curNode->next;
			delete curNode;
			curNode = temp;
		}
		head = NULL;
		size = 0;
	}

	container::container()
	{
		size = 0;
		head = NULL;
	}

	container::~container()
	{
		clear();
	}
} // end animals namespace