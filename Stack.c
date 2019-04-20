#include "Stack.h"

void SSet(List* plist)
{
	plist->Top = NULL;
}
void SPush(List* plist, char* ar)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	char * dat = (char*)malloc(strlen(ar) + 1);
	strcpy(dat, ar);
	NewNode->data = dat;
	NewNode->next = plist->Top;
	plist->Top = NewNode;
}
Node* SPop(List* plist)
{
	Node* PopNode = plist->Top;
	if (PopNode == NULL)
	{
		printf("데이터가 없습니다.");
		return NULL;
	}
	plist->Top = plist->Top->next;
	return PopNode;
}
void SDelete(Node* DelNode)
{
	free(DelNode->data);
	free(DelNode);
}
int SEmpty(List* plist)
{
	return (plist->Top == NULL);
}