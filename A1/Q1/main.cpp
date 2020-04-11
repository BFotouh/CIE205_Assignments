#include "LinkedList.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	LinkedList<int> L;	//create an object of class LinkedList
	
	// print the empty list
	cout << "1. Create an empty list: ";
	L.PrintList();


	//initialize the list with the first level
	cout << "\n2. Insert only one level in the list: ";
	L.ExtendOne();
	// print the first level list
	L.PrintList();


	// Extend the list by three levels
	cout << "\n3. Extend the list three levels higher: ";
	L.Extendn(4);
	// print the extended list
	L.PrintList();


	// Shrink the list by one level
	cout << "\n4. Shrink the list one level lower: ";
	L.ShrinkOne();
	// print the extended list
	L.PrintList();

	// Shrink the list by one level
	cout << "\n5. Shrink the list five levels lower: ";
	L.Shrinkn(5);
	// print the extended list
	L.PrintList();


	//initialize the list with the first level
	cout << "\n6. Delete the list: ";
	L.DeleteAll();
	// print the first level list
	L.PrintList();
	return 0;
}

