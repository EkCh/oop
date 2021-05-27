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

	bool node::out_node_fish(ofstream& ofst)
	{
		an->output_fish(ofst);
		return true;
	}

	void container::output_fish(ofstream& ofst)
	{
		ofst << "Only fish. " << endl;

		node* curNode = head;
		int i = 0;

		for (int i = 0; i < size; i++)
		{
			curNode = head;
			for (int j = 0; j < i; j++)
			{
				curNode = curNode->next;
			}
			curNode->out_node_fish(ofst);
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

	node* container::get_node(int index)
	{
		node* returnNode = head;

		for (int i = 0; i < index; i++)
		{
			returnNode = returnNode->next;
		}

		return returnNode;
	}

	void container::swap(int index_first, int index_second)
	{
		node* temp = new node;

		temp->an = get_node(index_first)->an;
		get_node(index_first)->an = get_node(index_second)->an;
		get_node(index_second)->an = temp->an;

	}

	void container::sort()
	{
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = i + 1; j < size; j++)
			{
				if (get_node(i)->an->compare(get_node(j)->an))
				{
					swap(i, j);
				}
			}
		}
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