// Allows input and output functions
#include <iostream>
//Includes "BST" header information.
#include "BST.h"

// Main function
int main()
{
	// Creates binary search tree of integer type
	BST<int> bst;
	// Root node pointer is NULL
	Node<int>* node = NULL;
	// TEST - ATTEMPTING TO REMOVE NODE FROM EMPTY BST
	bst.deleteNode(node, 40);
	// Inserts nodes into BST. First node is root.
	Node<int>* root = bst.insertNode(node, 40);
	//Subsequent nodes are inserted by recursively traversing through root until new place is reached
	bst.insertNode(root, 20);
	bst.insertNode(root, 60);
	bst.insertNode(root, 30);
	bst.insertNode(root, 10);
	bst.insertNode(root, 50);
	// TEST - ATTEMPTING TO INSERT DUPLICATE NODE
	bst.insertNode(root, 60);
	// Inorder traversal (displays nodes in left -> root -> right order)
	bst.inorderTraverse(root);
	// Maximum value of 6 nodes
	bst.maximum(root);
	// TEST - REMOVING NODE WITH 2 CHILDREN
	bst.deleteNode(root, 20);
	// Newline
	std::cout << "\n\n";
	// Inorder traversal (displays nodes in left -> root -> right order)
	bst.inorderTraverse(root);
	// TEST - REMOVING NODE WITH 1 CHILD
	bst.deleteNode(root, 60);
	// Newline
	std::cout << "\n\n";
	// Inorder traversal (displays nodes in left -> root -> right order)
	bst.inorderTraverse(root);
	// TEST - REMOVING NODE WITH NO CHILDREN
	bst.deleteNode(root, 10);
	// Newline
	std::cout << "\n\n";
	// Inorder traversal (displays nodes in left -> root -> right order)
	bst.inorderTraverse(root);
	// Maximum value of 3 nodes
	bst.maximum(root);
	// Returns 0 to function
	return 0;
}