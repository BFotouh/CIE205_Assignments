#include "BTree.h"

#include <iostream>
using namespace std;

// Utility Functions - Recursive Functions --------------------------

// Given functions

// Insert an integer key in a binary search tree.
// [Note]: subRoot is passed by ref because 
//         the new node may be inserted in the subRoot (if subRoot is empty nullptr)
void BTree::rec_insertBT(Node*& subRoot, int key)
{
	if (subRoot == nullptr)
		subRoot = new Node(key); // this line is why we pass subRoot by reference (subRoot = something)
	else if (subRoot->getdata() < key)
	{

		//recursively call insert for the right subtree
		rec_insertBT(subRoot->getright(), key);

		// ************************   VERY IMPORTANT NOTE  *************************** //

		// Node* & Node::getright();   VS   Node* Node::getright();

		// Notice that function rec_insertBST(Node *& subRoot, int key);
		// takes it 1st parameter (the pointer) by REFERENCE
		// For the above call of the function to be syntactically correct, 
		// we have declared function Node::getright() is as:  
		//		Node* & Node::getright(); (see Node class)
		//i.e. it returns a Node pointer but by reference (not by value)

		// Why wouldn't it work if it is return by value ???
		//		if Node::getright() was declared as  
		//		Node* Node::getright();			
		//		i.e. it returns "right" pointer (return by value)
		//		in this case, the returned pointer is called rvale (right-value)
		//		rvalue in C++ cannot be passed by ref to a function and
		//		cannot be used at the left of assignment statement		

		// What should I do if function getright must return by value ???
		//		IF for any reason, getright in your code MUST return by value 
		//		so the previous code line  rec_insertBST(subRoot->getright(), key); is a syntax error
		//		To solve the problem is this case 
		//		we should 
		//			1- store it in temp, 
		//			2- pass the temp to the function, 
		//			3- set the right of subRoot with this temp (after calling the fn because it may be changed inside it - by ref)
		//	Here is the code in this case to perform the same task
				/*
				Node * tmp = subRoot->getright();
				rec_insertBST(tmp, key);
				subRoot->setright(tmp);
				*/
				//	So to avoid all this mess, all what you need is to declare getright as:
				//		Node* & Node::getright();
				//	NOT as:
				//		Node*  Node::getright();


				// Remember: rvalue is some expression that is not stored in memory with a specific name
				// hence, you can't reach it by a name beyond the line that contains it 
				// like (x + 9): x is stored in memory, but (x + 9) returns a temp result that is not stored in memory with a name
				// same case for: subRoot->getright() --> if it returns an rvalue (or temp result without a name) of the "right"
	}
	else
	{
		// recursive call on left
		rec_insertBT(subRoot->getleft(), key);
	}
}

//* print the tree with inorder traversal.
void BTree::rec_inorder_traverse(Node* subRoot)
{
	if (subRoot == nullptr) return;
	rec_inorder_traverse(subRoot->getleft());
	cout << subRoot->getdata() << " ";
	rec_inorder_traverse(subRoot->getright());
}

//* print the tree with preorder traversal.
void BTree::rec_preorder_traverse(Node* subRoot)
{
	if (subRoot == nullptr) return;
	cout << subRoot->getdata() << "  ";
	rec_preorder_traverse(subRoot->getleft());
	rec_preorder_traverse(subRoot->getright());
}

//* print the tree with postorder traversal.
void BTree::rec_postorder_traverse(Node* subRoot)
{
	if (subRoot == nullptr) return;
	rec_postorder_traverse(subRoot->getleft());
	rec_postorder_traverse(subRoot->getright());
	cout << subRoot->getdata() << "  ";
}

//* Deletes all the nodes in the tree.
// [Note]: subRoot is passed by ref because 
//         after deleting subRoot node we will make it point to nullptr (change subRoot)
void BTree::rec_destroy_tree(Node*& subRoot)
{
	if (subRoot != nullptr)
	{
		// recursive call on left
		rec_destroy_tree(subRoot->getleft());

		// recursive call on right
		rec_destroy_tree(subRoot->getright());

		delete subRoot;
		subRoot = nullptr; // this line is why we pass subRoot by reference (subRoot = something)
	}
}

//Functions to be implemented by student

//* return a pointer to the node that hold the maximum value in binary search tree of the passed subRoot.
Node* BTree::rec_find_max(Node* subRoot)
{
	//TO DO
	return nullptr; // should be changed
}
//* return a pointer to the node that hold the minimum value in binary search tree of the passed subRoot.
Node* BTree::rec_find_min(Node* subRoot)
{
	//TO DO
	return nullptr; // should be changed
}
//* return the depth of binary search tree of the passed subRoot.
int BTree::rec_max_depth(Node* subRoot)
{
	//TO DO
	return 0; // should be changed
}


BTree::BTree()
{
	root = nullptr;
}


BTree::~BTree()
{
	destroy_tree();
}

// Public Functions ---------------------------------

// Given functions
void BTree::insertBT(int key) // not const
{
	// not const because rec_insertBST takes the root by reference, so may change it
	rec_insertBT(root, key);
}
void BTree::inorder_traverse() const
{
	rec_inorder_traverse(root);
}
void BTree::preorder_traverse() const
{
	rec_preorder_traverse(root);
}
void BTree::postorder_traverse() const
{
	rec_postorder_traverse(root);
}
void BTree::destroy_tree() // not const
{
	// not const because rec_destroy_tree takes the root by reference, so may change it
	rec_destroy_tree(root);
}

// Functions to be implemented by student
Node* BTree::find_max() const // return a pointer to the node that hold the maximum value in binary search tree.
{
	//TO DO
	return nullptr; // should be changed
}
Node* BTree::find_min() const // return a pointer to the node that hold the minimum value in binary search tree.
{
	//TO DO
	return nullptr; // should be changed
}
int BTree::max_depth() const
{
	//TO DO
	return 0; // should be changed
}

/////////////////////////////// 4 ////////////////////////
int BTree::rec_CountGreater(Node*& subRoot, int num)
{
	int count = 0;
	if (subRoot != nullptr)
	{
		if (subRoot->getdata() > num)
			count++;
		count += rec_CountGreater(subRoot->getright(), num);

		count += rec_CountGreater(subRoot->getleft(), num);
	}
	return count;
}

int BTree::CountGreater(int num)
{
	return rec_CountGreater(root, num);
}


int BTree::rec_CountSmaller(Node*& subRoot, int num)
{
	int count = 0;
	if (subRoot != nullptr)
	{
		if (subRoot->getdata() < num)
			count++;
		count += rec_CountSmaller(subRoot->getright(), num);

		count += rec_CountSmaller(subRoot->getleft(), num);
	}
	return count;
}

int BTree::CountSmaller(int num)
{
	return rec_CountSmaller(root, num);
}


void BTree::rec_Autumn(Node*& subRoot)
{
	if (subRoot == nullptr)
		return;
	else if (subRoot->getleft() == nullptr && subRoot->getright() == nullptr)
	{
		delete subRoot;
		subRoot = nullptr;
		return;
	}
	// recursive call on left
	rec_Autumn(subRoot->getleft());

	// recursive call on right
	rec_Autumn(subRoot->getright());
}


void BTree::Autumn()
{
	rec_Autumn(root);
}


void BTree::rec_OneChild(Node*& subRoot)
{
	if (subRoot == nullptr)
		return;
	else if ((subRoot->getleft() != nullptr && subRoot->getright() == nullptr) || (subRoot->getleft() == nullptr && subRoot->getright() != nullptr))
	{
		if (subRoot->getleft() != nullptr && subRoot->getright() == nullptr)
		{
			subRoot->setdata(subRoot->getleft()->getdata());
			delete subRoot->getleft();
			subRoot->setleft(nullptr);
		}
		if (subRoot->getleft() == nullptr && subRoot->getright() != nullptr)
		{
			subRoot->setdata(subRoot->getright()->getdata());
			delete subRoot->getright();
			subRoot->setright(nullptr);
		}
		return;
	}
	else
	{
		// recursive call on left
		rec_OneChild(subRoot->getleft());

		// recursive call on right
		rec_OneChild(subRoot->getright());
	}
}


void BTree::OneChild()
{
	rec_OneChild(root);
}




////////////////////////////////////////////////////////////////////////////////
/////////////////////// ASSIGNMENT FUCTIONS ////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

int BTree::rec_CountNodes(Node* subRoot)
{
	int count = 0;
	if (subRoot != nullptr)
	{
		if (subRoot->getdata() != NULL)
			count++;
		count += rec_CountNodes(subRoot->getright());

		count += rec_CountNodes(subRoot->getleft());
	}
	return count;
}

int BTree::CountNodes() const
{
	return rec_CountNodes(root);
}

////////////////////////////////////////////////////////////////////////////////


int  BTree::rec_numLeaves(Node* subRoot)
{
	int count = 0;
	if (subRoot != nullptr)
	{
		if (subRoot->getleft() == nullptr && subRoot->getright() == nullptr)
			count++;

		count += rec_numLeaves(subRoot->getleft());

		count += rec_numLeaves(subRoot->getright());
	}
	return count;
}

int BTree::numLeaves() const
{
	return rec_numLeaves(root);
}

////////////////////////////////////////////////////////////////////////////////


int BTree::rec_numNOneChild(Node* subRoot)
{
	int count = 0;
	if (subRoot != nullptr)
	{
		if ((subRoot->getleft() != nullptr && subRoot->getright() == nullptr) || (subRoot->getleft() == nullptr && subRoot->getright() != nullptr))
			count++;

		count += rec_numNOneChild(subRoot->getleft());

		count += rec_numNOneChild(subRoot->getright());
	}
	return count;
}

int BTree::numNOneChild() const
{
	return rec_numNOneChild(root);
}

////////////////////////////////////////////////////////////////////////////////


int BTree::maxNumNodes(int a, int b)
{
	return ((a > b) ? a : b);
}

int BTree::rec_TreeHeight(Node* subRoot)
{
	int count = 0, len_left = 0, len_right = 0, long_path = 0;
	if (subRoot != nullptr)
	{
		if (subRoot->getleft() != nullptr && subRoot->getright() != nullptr)
			count++;

		len_left = rec_TreeHeight(subRoot->getleft());

		len_right = rec_TreeHeight(subRoot->getright());
		
		return 1 + maxNumNodes(len_left, len_right);
	}
	return count;
}

int BTree::TreeHeight() const
{
	return rec_TreeHeight(root);
}

////////////////////////////////////////////////////////////////////////////////


bool BTree::rec_CheckBalance(Node* subRoot)
{
	int count = 0, len_left = 0, len_right = 0;
	if (subRoot != nullptr)
	{
		len_left = rec_TreeHeight(subRoot->getleft());

		len_right = rec_TreeHeight(subRoot->getright());

		if (abs(len_left - len_right) <= 1 && rec_CheckBalance(subRoot->getleft()) && rec_CheckBalance(subRoot->getright()))
			return true;
	}
	else
		return true;
	return false;
}

bool BTree::CheckBalance() const
{
	return rec_CheckBalance(root);
}

////////////////////////////////////////////////////////////////////////////////