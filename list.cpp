#define ElementType  int
#define Success 0
#define Fail 0
#include <stdlib.h>
#include <stdio.h>

struct Node {
	ElementType element;
	Node* next;
};

typedef Node* ptrNode;
int isEmpty(ptrNode node) {
	return !node || !node->next;
}

ptrNode Find(ElementType x, ptrNode l){
	if (!l) {
		return NULL;
	}
	
	ptrNode node = l->next;
	while (node && node->element != x) {
		node = node->next;
	}
	
	return node;
}

int Delete(ElementType x, ptrNode head){
	if (!head) {
		return Fail;
	}
	
	ptrNode pre = head;
	ptrNode node = head->next;
	while (node) {
		if (node->element == x) {
			pre->next = node->next;
			delete node;
			return Success;
		}
		
		pre = node;
		node = node->next;
	}
	
	return Fail;
}

void createNode(ptrNode node, int x) {
	if (node) {
		ptrNode new_node = new Node;
		new_node->element = x;
		new_node->next = NULL;
		
		ptrNode next = node->next;
		node->next = new_node;
		new_node->next = next;
	}
}

void printNode(ptrNode node) {
	if (!node) {
		return;
	}
	
	ptrNode next = node->next;
	while (next){
		printf("%d ", next->element);
		next = next->next;
	}
	printf("\n");
}

int main() {
	ptrNode head = new Node;
	head->next = NULL;
	for (int i = 0; i < 10; ++i) {
		createNode(head, i);
	}
	
	Delete(5, head);
	Delete(2, head);
	printNode(head);
}

