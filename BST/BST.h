//Speeds up compilation by only needing the file once
#pragma once
// Allows input and output functions
#include <iostream>
//Includes "Node" header information
#include "Node.h"

// Template for Binary Search Tree (BST) class
template <typename T>
class BST
{
// Access specifier. Lists data that can be directly accessed from anywhere object can be accessed
public:
	// Pointer to root node
	Node* root;
	// Inserts node with value in BST prototype
	Node<T>* insertNode(Node<T>* root, T data);
	// Deletes node with value in BST prototype
	Node<T>* deleteNode(Node<T>* root, T data);
	// Finds and displays maximum value in BST prototype
	void maximum(Node<T>* root);
	// Traverses (travels through) BST, displaying values in order in BST prototype
	void inorderTraverse(Node<T>* node);
};

// Template for insert function
template <typename T>
Node<T>* BST<T>::insertNode(Node<T>* root, T data) {
	// Executes if root is NULL
	if (root == NULL)
	{
		// New node pointer is new node
		Node<T>* newNode = new Node<T>;
		// New node data is number
		newNode->data = data;
		// New node left child is NULL
		newNode->leftChild = NULL;
		// New node right child is NULL
		newNode->rightChild = NULL;
		// Returns root to function
		return newNode;
	}
	// Executes if root is not NULL
	else
	{
		// Executes if root's data is data
		if (root->data == data)
		{
			std::cout << "Duplicate node will not be added to BST.\n\n";
		}
		// Executes if root's data is greater than number
		else if (root->data > data)
		{
		// Root's left pointer is recursive call of insert
		// Based on root's left pointer and data to be found
			root->leftChild = insertNode(root->leftChild, data);
		}
		// Executes if root's data is less than number
		else
		{
		// Root's right pointer is recursive call of insert
		// Based on root's right pointer and data to be found
			root->rightChild = insertNode(root->rightChild, data);
		}
	}
	// Returns root to function
	return root;
}

// Template for delete function
template <typename T>
Node<T>* BST<T>::deleteNode(Node<T>* root, T data) {
	// Executes if root is NULL
	if (root == NULL)
	{
		std::cout << "Can't remove node from empty BST.\n\n";
	}
	// Executes if root data is greater than data
	else if (root->data > data)
	{
		// Root's left pointer is recursive call of delete
		// Based on root's left pointer and data to be found
		root->leftChild = deleteNode(root->leftChild, data);
	}
	// Executes if root data is less than data
	else if (root->data < data)
	{
		// Root's right pointer is recursive call of delete
		// Based on root's right pointer and data to be found
		root->rightChild = deleteNode(root->rightChild, data);
	}
	// Executes if root's data is data
	else
	{
		// Executes if root's left and right pointers are NULL (no child)
		if (root->leftChild == NULL && root->rightChild == NULL)
		{
			// Deletes root
			delete root;
			// Root is NULL
			root = NULL;
		}
		// Executes if root's left or right pointers are NULL (1 child)
		else if (root->leftChild == NULL || root->rightChild == NULL)
		{
			// Executes if root's left pointer is NULL
			if (root->leftChild == NULL)
			{
				// Root is root's right pointer
				root = root->rightChild;
				// Deletes root's right child
				delete root->rightChild;
			}
			// Executes if root's right pointer is NULL
			else
			{
				// Root is root's left pointer
				root = root->leftChild;
				// Deletes root's left child
				delete root->leftChild;
			}
		}
		// Executes if root's left and right pointers are not NULL (2 children)
		else
		{
			// Current node is root's right pointer
			Node<T>* currentNode = root->rightChild;
			// Executes while root's left pointer is not NULL
			while (currentNode->leftChild != NULL)
			{
				// Current node is current node's left pointer
				currentNode = currentNode->leftChild;
			}
			// Root's data is current node's data
			root->data = currentNode->data;
			// Root's right pointer is recursive call of delete
			// Delete is based on current node and current node's data
			root->rightChild = deleteNode(currentNode, currentNode->data);
		}
	}
	// Returns root to function
	return root;
}

// Template for maximum function
template <typename T>
void BST<T>::maximum(Node<T>* root) {
	// Executes while root's right pointer is not NULL
	while (root->rightChild != NULL)
	{
		// Root is root's right pointer
		root = root->rightChild;
	}
	std::cout << "\n\nMaximum value: " << root->data << "\n";
}

// Template for inorder traverse function
template <typename T>
void BST<T>::inorderTraverse(Node<T>* node) {
	// Executes if node is not NULL
	if (node != NULL)
	{
		// Recursively traverses node's left child
		inorderTraverse(node->leftChild);
		//Prints each node's data
		std::cout << node->data << " ";
		// Recursively traverses node's right child
		inorderTraverse(node->rightChild);
	}
}