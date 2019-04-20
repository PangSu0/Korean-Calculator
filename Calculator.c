#include "Calculator.h"
#include "Stack.h"

int IsNumber(char num)
{
	if (num < 0)
		return 2;
	else if ((num >= '0') && (num <= '9'))
		return 1;
	else
		return 0;
}
int GetToken(char * ar, char * tok, int * type)
{
	int i = 0;
	if (IsNumber(ar[i]) == 1)
		*type = OPERAND;
	else if (IsNumber(ar[i]) == 2)
		*type = OPERAND2;
	else
		*type = ar[i];

	if (IsNumber(ar[i]))
		for (i = 0; ar[i] != '\0'; i++)
		{
			tok[i] = ar[i];
			if (!IsNumber(ar[i + 1]))
				break;
		}
	else
		tok[i] = ar[i];
	tok[++i] = '\0';
	return i;
}
int GetPriority(char Operator, int num)
{
	int pr = -1;
	switch (Operator)
	{
	case LEFT_P:
		if (num)
			pr = 0;
		else
			pr = 3;
		break;
	case MULTIPLY:
	case DIVIDE:
		pr = 2;
		break;
	case PLUS:
	case MINUS:
		pr = 1;
		break;
	}
	return pr;
}
int Prior(char Oper1, char Oper2)
{
	return (GetPriority(Oper1, 1) >= GetPriority(Oper2, 0));
}
void Conversion(char* ar)
{
	List List;
	char Token[32] = { 0 };
	int type;
	unsigned int Position = 0;
	unsigned int siz = strlen(ar);
	char* br = (char*)malloc(siz + 1);
	strcpy(br, ar);
	memset(ar, 0, siz + 1);
	SSet(&List);

	while (Position < siz)
	{
		Position += GetToken(&br[Position], Token, &type);
		if (type == OPERAND)
		{
			strcat(ar, Token);
			strcat(ar - 2, " ");
		}
		else if (type == OPERAND2)
		{
			agoi(ar, Token);
			strcat(ar, " ");
		}
		else if (type == RIGHT_P)
		{
			while (!SEmpty(&List))
			{
				Node* TheNode = SPop(&List);
				if (TheNode->data[0] == LEFT_P)
				{
					SDelete(TheNode);
					break;
				}
				strcat(ar, TheNode->data);
				SDelete(TheNode);
			}
		}
		else
		{
			while (!SEmpty(&List) && Prior(List.Top->data[0], Token[0]))
			{
				Node* TheNode = SPop(&List);
				strcat(ar, TheNode->data);
				SDelete(TheNode);
			}
			SPush(&List, Token);
		}
	}
	while (!SEmpty(&List))
	{
		Node* TheNode = SPop(&List);
		strcat(ar, TheNode->data);
		SDelete(TheNode);
	}
}
int Calculate(char * ar)
{
	List List;
	Node* ResultNode;
	char Token[32] = { 0 };
	unsigned int siz = strlen(ar);
	unsigned int Position = 0;
	int Type = -1;
	int Lastdata;

	while (Position < siz)
	{
		Position += GetToken(&ar[Position], Token, &Type);
		if (Type == SPACE)
			continue;
		if (Type == OPERAND)
			SPush(&List, Token);
		else
		{
			char ArrResult[32] = { 0 };
			int Oper1, Oper2, Result;
			Node* TheNode = SPop(&List);
			Oper2 = atoi(TheNode->data);
			SDelete(TheNode);

			TheNode = SPop(&List);
			Oper1 = atoi(TheNode->data);
			SDelete(TheNode);

			switch (Type)
			{
			case PLUS:		Result = Oper1 + Oper2;	break;
			case MINUS:		Result = Oper1 - Oper2;	break;
			case MULTIPLY:	Result = Oper1 * Oper2;	break;
			case DIVIDE:	Result = Oper1 / Oper2;	break;
			}
			itoa(Result, ArrResult, 10);
			SPush(&List, ArrResult);
		}
	}
	ResultNode = SPop(&List);
	Lastdata = atoi(ResultNode->data);
	SDelete(ResultNode);

	return Lastdata;
}