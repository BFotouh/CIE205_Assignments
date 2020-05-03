#include "Node.h"
#include <iostream>
using namespace std;

int CountNodes(Node* subRoot);
int  numLeaves(Node* subRoot);
int numNOneChild(Node* subRoot);
int maxNumNodes(int a, int b);
int TreeHeight(Node* subRoot);
bool CheckBalance(Node* subRoot);

int main(void)
{
	//build tree       8 
	//               /   \ 
	//              3     13
	//             / \   / 
	//            1   4 9
	// level 1
	Node* tree1 = new Node(8);

	// level 2
	tree1->setleft(new Node(3));
	tree1->setright(new Node(13));

	// level 3
	tree1->getleft()->setleft(new Node(1));
	tree1->getleft()->setright(new Node(3));

	tree1->getright()->setleft(new Node(9));

	//build tree       1 
	//               /    
	//              2     
	//             / \    
	//            4   5 
	// level 1
	Node* tree2 = new Node(1);

	// level 2
	tree2->setleft(new Node(2));


	// level 3
	tree2->getleft()->setleft(new Node(4));
	tree2->getleft()->setright(new Node(5));


	//build tree        2 
	//               /    \ 
	//              8      6
	//             / \    / \ 
	//            1   10 15  3
	//		     / \  
	//          12  1

	// level 1
	Node* tree3 = new Node(2);

	// level 2
	tree3->setleft(new Node(8));
	tree3->setright(new Node(6));

	// level 3
	tree3->getleft()->setleft(new Node(1));
	tree3->getleft()->setright(new Node(10));

	tree3->getright()->setleft(new Node(15));
	tree3->getright()->setright(new Node(3));

	// level 4
	tree3->getleft()->getleft()->setleft(new Node(12));
	tree3->getleft()->getleft()->setright(new Node(1));

	//==============================================================
	//							My Functions
	//==============================================================
	cout << "Tree 1:  " << endl;
	cout << "a) Number of nodes:  ";
	cout <<	CountNodes(tree1) << endl;

	cout << "b) Number of leaves:  ";
	cout << numLeaves(tree1) << endl;

	cout << "c) Number of nodes with only one child:  ";
	cout << numNOneChild(tree1) << endl;

	cout << "d) Height of the tree:  ";
	cout << TreeHeight(tree1) << endl;

	cout << "e) Is perfectly balanced?  ";
	cout << ((CheckBalance(tree1))? "Yes" : "No") << endl;
	cout << endl;

	///////////////////
	cout << "Tree 2:  " << endl;
	cout << "a) Number of nodes:  ";
	cout << CountNodes(tree2) << endl;

	cout << "b) Number of leaves:  ";
	cout << numLeaves(tree2) << endl;

	cout << "c) Number of nodes with only one child:  ";
	cout << numNOneChild(tree2) << endl;

	cout << "d) Height of the tree:  ";
	cout << TreeHeight(tree2) << endl;

	cout << "e) Is perfectly balanced?  ";
	cout << ((CheckBalance(tree2)) ? "Yes" : "No") << endl;
	cout << endl;

	//////////////////////////
	cout << "Tree 3:  " << endl;
	cout << "a) Number of nodes:  ";
	cout << CountNodes(tree3) << endl;

	cout << "b) Number of leaves:  ";
	cout << numLeaves(tree3) << endl;

	cout << "c) Number of nodes with only one child:  ";
	cout << numNOneChild(tree3) << endl;

	cout << "d) Height of the tree:  ";
	cout << TreeHeight(tree3) << endl;

	cout << "e) Is perfectly balanced?  ";
	cout << ((CheckBalance(tree3)) ? "Yes" : "No") << endl;
	cout << endl;

}


////////////////////////////////////////////////////////////////////////////////
/////////////////////// ASSIGNMENT FUCTIONS ////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

int CountNodes(Node* subRoot)
{
	int count = 0;
	if (subRoot != nullptr)
	{
		if (subRoot->getdata() != NULL)
			count++;
		count += CountNodes(subRoot->getright());

		count += CountNodes(subRoot->getleft());
	}
	return count;
}
////////////////////////////////////////////////////////////////////////////////
int  numLeaves(Node* subRoot)
{
	int count = 0;
	if (subRoot != nullptr)
	{
		if (subRoot->getleft() == nullptr && subRoot->getright() == nullptr)
			count++;

		count += numLeaves(subRoot->getleft());

		count += numLeaves(subRoot->getright());
	}
	return count;
}
////////////////////////////////////////////////////////////////////////////////
int numNOneChild(Node* subRoot)
{
	int count = 0;
	if (subRoot != nullptr)
	{
		if ((subRoot->getleft() != nullptr && subRoot->getright() == nullptr) || (subRoot->getleft() == nullptr && subRoot->getright() != nullptr))
			count++;

		count += numNOneChild(subRoot->getleft());

		count += numNOneChild(subRoot->getright());
	}
	return count;
}
////////////////////////////////////////////////////////////////////////////////
int maxNumNodes(int a, int b)
{
	return ((a > b) ? a : b);
}

int TreeHeight(Node* subRoot)
{
	int count = 0, len_left = 0, len_right = 0, long_path = 0;
	if (subRoot != nullptr)
	{
		if (subRoot->getleft() != nullptr && subRoot->getright() != nullptr)
			count++;

		len_left = TreeHeight(subRoot->getleft());

		len_right = TreeHeight(subRoot->getright());

		return 1 + maxNumNodes(len_left, len_right);
	}
	return count;
}
////////////////////////////////////////////////////////////////////////////////
bool CheckBalance(Node* subRoot)
{
	int count = 0, len_left = 0, len_right = 0;
	if (subRoot != nullptr)
	{
		len_left = TreeHeight(subRoot->getleft());

		len_right = TreeHeight(subRoot->getright());

		if (abs(len_left - len_right) <= 1 && CheckBalance(subRoot->getleft()) && CheckBalance(subRoot->getright()))
			return true;
	}
	else
		return true;
	return false;
}