#include <iostream>
#include <string>
using namespace std;

class node 
{
public :
	string info;
	node* leftchild;
	node* rightchild;

	// constructor for the node class
	node(string i, node* l, node* r)
	{
		info = i;
		leftchild = l;
		rightchild = r;
	}
};

class binarytree
{
public:
	node* ROOT;

	binarytree()
	{
		ROOT = NULL; // initializing ROOT to null
	}
 
	void insert(string element) // insert a node in the binary search tree
	{
		node* newNode = new node(element, NULL, NULL); //allocate memory for the new node
		newNode->info = element; // assign value to the data field of the new node
		newNode->leftchild = NULL; // make the left child of the new node point to NULL
		newNode->rightchild = NULL; // make the right child of the new node point to NULL

		node* parent = NULL;
		node* currentNode = NULL;
		search(element, parent, currentNode); // locate the node which will be the parent of the node to be inserted

		if (parent == NULL) // if the parent is NULL (tree is empty)
		{
			ROOT = newNode; //mark the new node as ROOT
			return; //exit
		}

		if (element < parent->info) // if the value in the data field of the new node less than that of the parent
		{
			parent->leftchild = newNode; // make the left child of the parent point to the new node
		}
		else if (element > parent->info) // if the value in the data field of the new node is greater than that of the parent
		{
			parent->rightchild = newNode; // make the right child of the parent point to the new node
		}
	}


	void search(string element, node*& parent, node*& currentnode)
	{
		// this function searches the currentNode of the specified Node as well as the current node of its parent
		currentnode = ROOT;
		parent = NULL;
		while ((currentnode != NULL) && (currentnode->info != element))
		{
			parent = currentnode;
			if (element < currentnode->info)
				currentnode = currentnode->leftchild;
			else
				currentnode = currentnode->rightchild;
		}
	}

	void inorder(node* ptr)
	{

	}
};