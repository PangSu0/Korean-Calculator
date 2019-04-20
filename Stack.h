#ifndef STACK_H
#define STACK_H
#include <stdlib.h>
typedef struct node
{
	char* data;
	struct node* next;
}Node;
typedef struct list
{
	Node* Top;
}List;

void SSet(List* plist);
void SPush(List* plist, char* ar);
void SDelete(Node* DelNode);
int SEmpty(List* plist);
Node* SPop(List* plist);

#endif