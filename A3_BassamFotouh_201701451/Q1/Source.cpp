#include "Node.h"
#include <iostream>
using namespace std;

bool CheckMinBiHeap(Node* subRoot);

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
	//               /   \ 
	//              2     3
	//             / \   / 
	//            4   5 6
	// level 1
	Node* tree2 = new Node(1);

	// level 2
	tree2->setleft(new Node(2));
	tree2->setright(new Node(3));

	// level 3
	tree2->getleft()->setleft(new Node(4));
	tree2->getleft()->setright(new Node(5));

	tree2->getright()->setleft(new Node(6));

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
	cout << "a) Is tree 1 a binary minimum heap?  ";
	cout << ((CheckMinBiHeap(tree1)) ? "Yes" : "No") << endl;
	cout << endl;

	cout << "b) Is tree 2 a binary minimum heap?  ";
	cout << ((CheckMinBiHeap(tree2)) ? "Yes" : "No") << endl;
	cout << endl;

	cout << "c) Is tree 3 a binary minimum heap?  ";
	cout << ((CheckMinBiHeap(tree3)) ? "Yes" : "No") << endl;
	cout << endl;
}


bool CheckMinBiHeap(Node* subRoot)
{
	if (subRoot != nullptr)
	{
		if (subRoot->getright() != nullptr && subRoot->getleft() != nullptr)
		{
			if (subRoot->getdata() <= subRoot->getleft()->getdata()
				&& subRoot->getdata() <= subRoot->getright()->getdata()
				&& CheckMinBiHeap(subRoot->getleft()) && CheckMinBiHeap(subRoot->getright()))
				return true;
		}
		else if (subRoot->getright() == nullptr && subRoot->getleft() != nullptr)
		{
			if (subRoot->getdata() <= subRoot->getleft()->getdata()
				&& CheckMinBiHeap(subRoot->getleft()))
				return true;
		}
		else if (subRoot->getright() != nullptr && subRoot->getleft() == nullptr)
		{
			if (subRoot->getdata() <= subRoot->getright()->getdata()
				&& CheckMinBiHeap(subRoot->getright()))
				return true;
		}
		else
		{
			return true;
		}
	}
	else
		return true;
	return false;
}
