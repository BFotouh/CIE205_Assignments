#ifndef _NODE
#define _NODE

#include <iostream>
#include <string>
using namespace std;

//First let's declare a single node in the list
template<typename T>
class Node
{
private:
	string item;	// A data item (can be any complex sturcture)
	T nom;
	T denom;
	Node<T>* next;	// Pointer to next node
public:

	Node() //default constructor
	{
		next = nullptr;
	}

	Node(T n, T den) //non-default constructor
	{
		nom = n;
		denom = den;
		item = to_string(nom) + "/" + to_string(denom);
		next = nullptr;

	}

	void setItem(T n, T den)
	{
		nom = n;
		denom = den;
		item = to_string(nom) + "/" + to_string(denom);
	} // end setItem

	void setNext(Node<T>* nextNodePtr)
	{
		next = nextNodePtr;
	} // end setNext

	string getItem() const
	{
		return item;
	} // end getItem

	T getNom() const
	{
		return nom;
	} // end getnom

	T getDenom() const
	{
		return denom;
	} // end getdenom

	Node<T>* getNext() const
	{
		return next;
	}
}; // end Node

#endif	
