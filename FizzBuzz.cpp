#include<bits/stdc++.h>
using namespace std;
class Node {
	public:
		int val;
		Node *next;
		
		Node( int val, Node *nextNode ) {
			this->val = val;
			this->next = nextNode;
		}
};
Node *head = NULL;

Node *tail = NULL;

void pushback(int);
void popfront();
void printlist();

int main()
{
	// Insert 3 elements in the List
	pushback(2);
	pushback(3);
	pushback(5);
	printlist();
	
	// Remove the 1st element
	popfront();
	printlist();
	
	// Remove the other two elements
	popfront();
	popfront();
	printlist();
}

void pushback( int val ) {
	Node *newNode = new Node(val,NULL);
	
	if(tail==NULL) {
		head = newNode;
	} else {
		tail->next = newNode;
	}
	tail = newNode;
}

void popfront() {
	if(head!=NULL) {
		Node *nextNode = head->next;
		
		delete(head);
		
		head = nextNode;
		
		if(head==NULL) {
			tail = NULL;
		}
	}
}

void printlist() {
	Node *curNode = head;
	if(curNode==NULL) {
		printf("--empty list--\n");
		return;
	}
	while ( curNode !=NULL ) {
		printf("%d", curNode->val);
		curNode = curNode->next;
		
		if(curNode != NULL) {
			printf("->");
		}
	}
	
	printf("\n");
}
