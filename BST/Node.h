//Speeds up compilation by only needing the file once
#pragma once

// Template for Node class
template <typename T>
class Node
{
// Access specifier. Lists data that can be directly accessed from anywhere the object can be accessed
public:
	// Pointer to left child node
	Node* leftChild;
	// Pointer to right child node
	Node* rightChild;
	// Generic data variable
	T data;
};