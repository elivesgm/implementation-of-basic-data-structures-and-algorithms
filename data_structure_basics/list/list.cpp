#include <iostream>

using namespace std;

struct Node
{
	int   value;
	Node* pnext;

	Node(int x): value(x), pnext(NULL){}
};

Node* addToList(int value, Node* head) {
	if (!head)
		return new Node(value);
	Node* p = head;
	while (p->pnext) p = p->pnext;
	p->pnext = new Node(value);
	return head;
}

void printList(Node* head) {
	Node* p = head;
	while (p) {
		cout << p->value << " ";
		p = p->pnext;
	}
	cout << endl;
}

Node* reverseList(Node* head) {
	if (!head || !head->pnext) return head;

	Node* pCur, *pNext;
	pCur = head;
	while(pCur->pnext){
		pNext = pCur->pnext;
		pCur->pnext = pNext->pnext;
		pNext->pnext = head;
		head = pNext;
	}
	return head;
}

int main()
{
	int n = 10;
	Node* head = NULL;
	
	for (int i = 0; i < n; ++i) {
		head = addToList(i, head);
	}
	printList(head);

	head = reverseList(head);
	printList(head);
}
