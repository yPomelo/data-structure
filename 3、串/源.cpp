#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <conio.h>
typedef unsigned char SString[255];
int n;
int next[50];
void menu()
{
	printf("\n\n\n\t\t\t\t******************************************************\n");
	printf("\t\t\t\t\tģʽƥ��\n");
	printf("\t\t\t\t1������һ������S\n");
	printf("\t\t\t\t2������һ��ģʽ��T\n");
	printf("\t\t\t\t3������ģʽ��T��next����ֵ��������ʽ��ʾ��next����ֵ\n");
	printf("\t\t\t\t4��ʵ�ּ�ģʽƥ�� \n");
	printf("\t\t\t\t5��ʵ��KMPģʽƥ��\n");
	printf("\t\t\t\t6�������񣿣�y/n?��\n");
	printf("\t\t\t\t******************************************************\n\t\t\t\t");
}
void get(SString &S)
{
	printf("\t\t\t\t�����봮����\n\t\t\t\t");
	scanf("%d", &n);
	S[0] = n;
	for (int i = 1; i <= n; i++)
	{
		getchar();
		printf("\t\t\t\t�������%d���ַ�����\n\t\t\t\t", i);
		scanf("%c", &S[i]);
	}
	printf("\t\t\t\tOK!\n��������������˵�");
	_getch();
	return;
}
void get_next(SString T, int next[])
{
	int j = 0, i = 1;
	next[1] = 0;
	while (i < T[0])
	{
		if (j == 0 || T[i] == T[j])
		{
			i++;
			j++;
			next[i] = j;
		}
		else
			j = next[j];
	}
}
int Index(SString S, SString T, int pos)
{
	int i = pos, j = 1;
	while (i <= S[0] && j <= T[0])
	{
		if (S[i] == T[j])
		{
			++i;
			++j;
		}
		else
		{
			i = i - j + 2;
			j = 1;
		}
	}
	if (j > T[0])
		return i - T[0];
	else
		return 0;
}
int KMP(SString S, SString T, int pos)
{
	int i = pos, j = 1;
	while (i <= S[0] && j <= T[0])
		if (j == 0 || S[i] == T[j])
		{
			i++;
			j++;
		}
		else
			j = next[j];
	if (j > T[0])
		return i - T[0];
	else
		return 0;
}
void main()
{
	int pos;
	SString S, T;
	while (1)
	{
		int t;
		system("cls");
		menu();
		scanf("%d", &t);
		switch (t)
		{
		case 1:get(S); break;
		case 2:get(T); break;
		case 3:
		{
			get_next(T, next);
			for (int i = 1; i <= T[0]; i++)
			{
				printf("\t\t\t\tnext[%d] = %d\n", i, next[i]);
			}
			_getch();
		}break;
		case 4:
		{
			printf("\t\t\t\t�������������ĵڼ���λ�ÿ�ʼ��ʵ�ּ�ģʽƥ��\n\t\t\t\t");
			scanf("%d", &pos);
			printf("\t\t\t\t�Ӵ�T������S�ĵ�%d���ַ����λ��\n\t\t\t\t", Index(S, T, pos));
			_getch();
		}break;
		case 5:
		{
			printf("\t\t\t\t�������������ĵڼ���λ�ÿ�ʼ��ʵ��KMPģʽƥ��\n\t\t\t\t");
			scanf("%d", &pos);
			printf("\t\t\t\t�Ӵ�T������S�ĵ�%d���ַ����λ��\n\t\t\t\t", KMP(S, T, pos));
			_getch();
		} break;
		case 6:exit(0); break;
		}
	}
}