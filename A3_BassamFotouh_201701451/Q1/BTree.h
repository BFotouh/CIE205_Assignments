#pragma once

#include "Node.h"

class BTree
{
private:
	Node* root;

	static void rec_insertBT(Node*& subRoot, int key);
	static void rec_inorder_traverse(Node* subRoot);
	static void rec_preorder_traverse(Node* subRoot);
	static void rec_postorder_traverse(Node* subRoot);
	static void rec_destroy_tree(Node*& subRoot);

	static Node* rec_find_max(Node* subRoot);
	static Node* rec_find_min(Node* subRoot);
	static int rec_max_depth(Node* subRoot);
	static int rec_CountGreater(Node*& subRoot, int num);
	static int rec_CountSmaller(Node*& subRoot, int num);
	static void rec_Autumn(Node*& subRoot);
	static void rec_OneChild(Node*& subRoot);


	//////////// Assignment Functions
	static bool rec_CheckMinBiHeap(Node* subRoot);
	static int rec_CountNodes(Node* subRoot);
	static int rec_numLeaves(Node* subRoot);
	static int rec_numNOneChild(Node* subRoot);
	static int rec_TreeHeight(Node* subRoot);
	static bool rec_CheckBalance(Node* subRoot);

public:
	BTree(void);
	~BTree(void);

	void insertBT(int key); // not const
	void inorder_traverse() const;
	void preorder_traverse() const;
	void postorder_traverse() const;
	void destroy_tree(); // not const

	Node* find_max() const; // return a pointer to the node that hold the maximum value in binary search tree.
	Node* find_min() const; // return a pointer to the node that hold the minimum value in binary search tree.
	int max_depth() const;
	int CountGreater(int num);
	int CountSmaller(int num);
	void Autumn();
	void OneChild();


	//////////// Assignment Functions
	bool CheckMinBiHeap() const;
	int CountNodes() const;
	int numLeaves() const;
	int numNOneChild() const;
	static int maxNumNodes(int a, int b);
	int TreeHeight() const;
	bool CheckBalance() const;
};

