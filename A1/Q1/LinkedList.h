#ifndef _LINKEDLIST
#define _LINKEDLIST

#include "Node.h"


template <typename T>
class LinkedList
{
private:
	Node<T>* Head;	//Pointer to the head of the list
	//You can add tail pointer too (depending on your problem)
	int count;	//Number of nodes in the list
public:
	int level;

	LinkedList()
	{
		count = 0;
		level = 0;
		Head = nullptr;
	}

	//List is being desturcted ==> delete all items in the list
	~LinkedList()
	{
		DeleteAll();
	}
	////////////////////////////////////////////////////////////////////////
	/*
	* Function: PrintList.
	* prints the values of all nodes in a linked list.
	*/
	void PrintList()	const
	{
		cout << "\nList Level " << level << " has " << count << " nodes";
		cout << "\nprinting list contents:\n\n";
		Node<T>* p = Head;

		while (p)
		{
			cout << "[ " << p->getItem() << " ]";
			cout << "--->";
			p = p->getNext();
		}
		cout << "*\n";
	}
	////////////////////////////////////////////////////////////////////////
	/*
	* Function: InsertBeg.
	* Creates a new node and adds it to the beginning of a linked list.
	*
	* Parameters:
	*	- data : The value to be stored in the new node.
	*/
	void InsertBeg(const T& data)
	{
		Node<T>* R = new Node<T>(data);
		R->setNext(Head);
		Head = R;
		count++;

	}
	////////////////////////////////////////////////////////////////////////
	/*
	* Function: DeleteAll.
	* Deletes all nodes of the list.
	*/
	void DeleteAll()
	{
		Node<T>* P = Head;
		while (Head)
		{
			P = Head->getNext();
			delete Head;
			Head = P;
		}
		count = 0;
		level = 0;
	}



	////////////////     Requirements   ///////////////////
	//
	// Implement the following member functions


	//[1]InsertEnd 
	//inserts a new node at end if the list
	/*
	* Function: InsertEnd.
	* Creates a new node and adds it to the End of a linked list.
	*
	* Parameters:
	*	- data : The value to be stored in the new node.
	*/
	void InsertEnd(const T& nom, const T& denom)
	{
		Node<T>* P = Head;
		if (!P)
		{
			Node<T>* R = new Node<T>(nom, denom);
			Head = R;
		}
		else
		{
			while (P->getNext())
			{
				P = P->getNext();
			}
			Node<T>* R = new Node<T>(nom, denom);
			P->setNext(R);
		}
		count++;
	}

	//[2]Find 
	//searches for a given value in the list, returns true if found; false otherwise.
	bool Find(T Value)
	{
		Node<T>* P = Head;
		while (P)
		{
			P = P->getNext();
			if (P->getItem == Value)
			{
				return true;
			}
		}
		return false;
	}

	//[3]CountOccurance
	//returns how many times a certain value appeared in the list
	int CountOccurance(const T& value)
	{
		int cvalue = 0;
		Node<T>* P = Head;
		while (P)
		{
			P = P->getNext();
			if (P->getItem == value)
			{
				cvalue++;
			}
		}
		return cvalue;
	}

	//[4] DeleteFirst
	//Deletes the first node in the list
	void DeleteFirst()
	{
		Node<T>* P = Head;
		Head = Head->getNext();
		delete P;
		count--;
	}

	//[5] DeleteLast
	//Deletes the last node in the list
	void DeleteLast()
	{
		Node<T>* P = Head;
		if (!P)
		{
			Head->setNext(nullptr);
		}
		else
		{
			while (P->getNext()->getNext())
			{
				P = P->getNext();
			}
			delete P->getNext();
			P->setNext(nullptr);
		}
		count--;
	}

	//[6] DeleteNode
	//deletes the first node with the given value (if found) and returns true
	//if not found, returns false
	//Note: List is not sorted
	bool DeleteNode(const T& value)
	{
		Node<T>* P = Head;
		if (!P)
		{
			return false;
		}
		else if (P->getItem() == value)
		{
			Node<T>* R = P->getNext();
			delete P;
			Head = R;
			count--;
			return true;
		}
		else if (!P->getNext())
		{
			if (P->getItem() == value)
			{
				Node<T>* R = P->getNext();
				delete P;
				Head = R;
				count--;
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			while (P)
			{
				if (P->getNext()->getItem() == value)
				{
					Node<T>* R = P->getNext();
					P->setNext(P->getNext()->getNext());
					delete R;
					count--;
					return true;
				}
				P = P->getNext();
			}
			return false;
		}
	}

	//[7] DeleteNodes
	//deletes ALL node with the given value (if found) and returns true
	//if not found, returns false
	//Note: List is not sorted
	bool DeleteNodes(const T& value)
	{
		Node<T>* nxP = Head;
		nxP = nxP->getNext();
		Node<T>* prP = Head;
		if (!prP)
		{
			return false;
		}
		else if (!nxP)
		{
			if (prP->getItem() == value)
			{
				delete nxP;
				count--;
				Head = nullptr;
				return true;
			}
			else
				return false;
		}
		else
		{
			while (nxP)
			{
				if (nxP->getItem() == value)
				{
					prP->setNext(nxP->getNext());
					delete nxP;
					count--;
					nxP = prP->getNext();
				}
				else
				{
					if (prP->getItem() == value)
					{
						delete prP;
						count--;
						prP = nxP;
						nxP = prP->getNext();
						Head = prP;
					}
					else
					{
						nxP = prP->getNext()->getNext();
						prP = prP->getNext();
					}
				}
			}
			return true;
		}
	}

	//[8]Merge
	//Merges the current list to another list L by making the last Node in the current list 
	//point to the first Node in list L
	void Merge(const LinkedList& L)
	{
		Node<T>* crL = Head;
		Node<T>* neL = L.Head;
		while (neL->getNext())
		{
			InsertEnd(neL->getItem());
			neL = neL->getNext();
		}
	}

	//[9] Reverse
	//Reverses the linked list (without allocating any new Nodes)
	void Reverse()
	{

	}

	//[10] Extend One level
	bool ExtendOne()
	{
		if (level == 0)
		{
			InsertEnd(0, 1);
			InsertEnd(1, 1);
			level++;
			return true;
		}
		if (level > 0)
		{
			Node<T>* prP = Head;
			Node<T>* crP = Head->getNext();
			if (!prP)
			{
				return false;
			}
			else if (!crP)
			{
				return false;
			}
			while (crP)
			{
				if (prP->getDenom() + crP->getDenom() <= level + 1)
				{
					T n, d;
					n = prP->getNom() + crP->getNom();
					d = prP->getDenom() + crP->getDenom();
					Node<T>* nn = new Node<T>(n, d);
					nn->setNext(crP);
					prP->setNext(nn);
					count++;
					prP = prP->getNext()->getNext();
					crP = crP->getNext();
				}
				else
				{
					prP = prP->getNext();
					crP = crP->getNext();
				}
			}
			level++;
			return true;
		}
	}

	//[11] Extend n levels
	bool Extendn(int n)
	{
		if (n > level)
		{
			for (int i = level; i < n; i++)
			{
				ExtendOne();
			}
			return true;
		}
		else
		{
			bool check = false;
			while (!check)
			{
				cout << "Error! number of levels in the list is larger than your input." << endl;
				cout << "Enter the correct number or enter -1 to cancel: ";
				cin >> n;
				if (n > level)
				{
					check = true;
					for (int i = level; i < n; i++)
					{
						ExtendOne();
					}
					return true;
				}
				else if (n == -1)
				{
					return false;
				}
			}	
		}
	}


	//[10] Shrink One level
	bool ShrinkOne()
	{
		if (level == 0)
		{
			return false;
		}
		if (level > 0)
		{
			Node<T>* prP = Head;
			Node<T>* crP = Head->getNext();
			if (!prP)
			{
				return false;
			}
			else if (!crP)
			{
				return false;
			}
			while (crP)
			{
				if (crP->getDenom() == level)
				{
					prP->setNext(crP->getNext());
					delete crP;
					crP = prP->getNext();
					count--;
				}
				else
				{
					prP = prP->getNext();
					crP = crP->getNext();
				}
			}
			level--;
			return true;
		}
	}


	//[11] Shrink n levels
	bool Shrinkn(int n)
	{
		if ((level-n) > 0)
		{
			for (int i = 0; i < n; i++)
			{
				ShrinkOne();
			}
			return true;
		}
		else if ((level - n) == 0)
		{
			DeleteAll();
		}
		else
		{
			cout << "\nError! list doesn't contain that much of levels yet." << endl;
		}
	}
};

#endif	
