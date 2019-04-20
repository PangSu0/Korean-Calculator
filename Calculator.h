#ifndef CALCUL_H
#define CALCUL_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
enum
{
	LEFT_P = '(', RIGHT_P = ')', PLUS = '+', MINUS = '-',
	MULTIPLY = '*', DIVIDE = '/', SPACE = ' ', OPERAND, OPERAND2
};

int IsNumber(char num);
int GetToken(char * ar, char * tok, int * type);
int GetPriority(char Operator, int num);
int Prior(char Oper1, char Oper2);
void Conversion(char* ar);
int Calculate(char * ar);
#endif