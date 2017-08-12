

	root@ubuntu:/binarytree# g++ -o main -g main.cpp
	root@ubuntu:/binarytree# ./main 
	Pls. enter root: A
	Pls. enter left and right child of A(empty with @): LC
	Pls. enter left and right child of L(empty with @): BE
	Pls. enter left and right child of C(empty with @): @D
	Pls. enter left and right child of B(empty with @): @@
	Pls. enter left and right child of E(empty with @): @@
	Pls. enter left and right child of D(empty with @): W@
	Pls. enter left and right child of W(empty with @): @X
	Pls. enter left and right child of X(empty with @): @@
	Create completed!
	PreOder: 
	A L B E C D W X 
	InOrder: 
	B L E A C W X D 
	postOrder: 
	B E L X W D C A 
