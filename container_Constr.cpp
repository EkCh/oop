#include <fstream>
#include "container_atd.h"
using namespace std;

namespace animals 
{
	node::~node() {}

	bool node::AddNode(ifstream& ifst)
	{
		an = animal::In(ifst);

		if (an == NULL)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	void container::In(ifstream& ifst)
	{
		while (!ifst.eof())
		{
			node* tmpNode = new node;
			if (tmpNode->AddNode(ifst))
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

	bool node::OutNode(ofstream& ofst)
	{
		an->Output(ofst);
		return true;
	}

	void container::Out(ofstream& ofst)
	{
		ofst << "Container contains " << size << " elements. " << endl;
		node* curNode = head;
		int i = 0;

		while (curNode != NULL)
		{
			ofst << i << ": ";
			curNode->OutNode(ofst);
			curNode = curNode->next;
			i++;
		}
	}

	bool node::OutNodeFish(ofstream& ofst)
	{
		an->OutFish(ofst);
		return true;
	}

	void container::OutFish(ofstream& ofst)
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
			curNode->OutNodeFish(ofst);
		}

	}

	// Очистка контейнера от элементов
	void container::Clear()
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

	node* container::GetNode(int index)
	{
		node* returnNode = head;

		for (int i = 0; i < index; i++)
		{
			returnNode = returnNode->next;
		}

		return returnNode;
	}

	void container::Swap(int index_first, int index_second)
	{
		node* temp = new node;

		temp->an = GetNode(index_first)->an;
		GetNode(index_first)->an = GetNode(index_second)->an;
		GetNode(index_second)->an = temp->an;

	}

	void container::Sort()
	{
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = i + 1; j < size; j++)
			{
				if (GetNode(i)->an->Compare(GetNode(j)->an))
				{
					Swap(i, j);
				}
			}
		}
	}

	void container::Multimethod(ofstream& ofst)
	{
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = i + 1; j < size; j++)
			{
				GetNode(i)->an->Multimethod(GetNode(j)->an, ofst);
				GetNode(i)->OutNode(ofst);
				GetNode(j)->OutNode(ofst);
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
		Clear();
	}
} // end animals namespace