#include "Han.h"
void agoi(char ar[], char kornum[])
{
	char* list = "���̻�����ĥ�ȱ��ʹ�õ�����";
	char* knum[12] = { "õ", "��", "��", "��", "õ", "��", "��", "��", "õ", "��", "��", "��" };
	char num[13] = "000000000000";
	char target[3] = { 0 };
	int siz, i, j = 12, lnum;
	siz = strlen(kornum);
	for (i = siz - 2; i >= 0; i -= 2)
	{
		strncpy(target, kornum + i, 2);
		lnum = (strstr(list, target) - list + 2) / 2;
		if (lnum<10)
			num[j] = lnum + '0';
		else
		{
			while (strcmp(knum[--j], target));
			if ((i == 0) || ((j + 1) % 4 != 0))num[j] = '1';
		}
	}
	strcat(ar, num);
}

void igoa(int total)
{
	char cbuf[3] = { 0 }, ch[15] = { 0 }, pptr[40] = { 0 };
	const char* list = "���̻�����ĥ�ȱ��ʹ�õ������";
	int siz, i, ciph;
	itoa(total, ch, 10);
	siz = strlen(ch);
	for (i = 0; i<siz; i++)
	{
		ciph = siz - i - 1;
		if (ch[i]>'1')
			strncat(pptr, list + 2 * (ch[i] - '1'), sizeof(char) * 2);
		else if (ch[i] == '1')
			if (((ciph == 8) || (ciph == 4) || (ciph == 0)) && (siz != 5))
				strncat(pptr, list + 2 * (ch[i] - '1'), sizeof(char) * 2);
		if (ciph % 4 == 0)
			if ((ciph == 4) && (total / 10000 % 10000 == 0));
			else
				strncat(pptr, list + 2 * (12 + ciph / 4), sizeof(char) * 2);
		else if (ch[i] != '0')
			strncat(pptr, list + 2 * (8 + ciph % 4), sizeof(char) * 2);
	}
	puts(pptr);
}