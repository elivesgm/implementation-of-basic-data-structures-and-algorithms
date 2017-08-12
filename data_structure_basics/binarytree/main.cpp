// file: main.cpp

#include <iostream>
#include "binarytree.h"

//#define RECURSIVE_TRANVERSE

int main(int argc, char** argv) 
{
	BinaryTree<char> bt;
	bt.createTree('@');

	bt.preOrder();
	std::cout << std::endl;
	bt.inOrder();
	std::cout << std::endl;
	bt.postOrder();
	std::cout << std::endl;

	return 0;
}
