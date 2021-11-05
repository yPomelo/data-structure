#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define MAXSIZE 12500
typedef struct
{
	int i;
	int j;
	int e;
}Triple;
typedef struct
{
	Triple data[MAXSIZE + 1];
	int mu, nu, tu;
}TSM;
void menu()
{
	printf("\n\n\n");
	printf("\t\t\t***********************************\n");
	printf("\t\t\t*    1.��Ԫ����ʽ����ϵ������A    *\n");
	printf("\t\t\t*    2.�������A(��Ԫ����ʽ)      *\n");
	printf("\t\t\t*    3.Aת��ΪB                   *\n");
	printf("\t\t\t*    4.���B                      *\n");
	printf("\t\t\t*    5.�˳�                       *\n");
	printf("\t\t\t***********************************\n");
	printf("\t\t\t     ��ѡ��");
}
void Get(TSM &A)
{
	system("cls");
	printf("\n\t\t\t     ����������:");
	scanf("%d", &A.mu);
	printf("\n\t\t\t     ����������:");
	scanf("%d", &A.nu);
	printf("\n\t\t\t     ���������Ԫ����:");
	scanf("%d", &A.tu);
	for (int i = 1; i <= A.tu; i++)
	{
		system("cls");
		printf("\n\t\t\t �������%d������Ԫ���б�:", i);
		scanf("%d", &A.data[i].i);
		printf("\n\t\t\t �������%d������Ԫ���б�:", i);
		scanf("%d", &A.data[i].j);
		printf("\n\t\t\t �������%d������Ԫ:", i);
		scanf("%d", &A.data[i].e);
	}
	printf("\n\t\t\t ��������������˵�");
	_getch();
	return;
}
void printTriple(TSM A)
{
	system("cls");
	for (int i = 1; i <= A.tu; i++)
	{
		printf("\n\t\t\t     ��%d������Ԫ(%d,%d,%d):", i, A.data[i].i, A.data[i].j, A.data[i].e);
	}
	printf("\n\t\t\t     ��������������˵�");
	_getch();
	return;

}
void turn(TSM A, TSM &B)
{
	system("cls");
	int p, q, col, *num, *cpot;
	num = (int*)malloc((A.mu + 1) * sizeof(int));
	cpot = (int*)malloc((A.nu + 1) * sizeof(int));
	B.mu = A.nu;
	B.nu = A.mu;
	B.tu = A.tu;
	if (B.tu)
	{
		for ( col = 1; col < A.nu; col++)
		{
			num[col] = 0;
		}
		for (p = 1; p <= A.nu; p++)
		{
			++num[A.data[p].j];
		}
		cpot[1] = 1;
		for ( col = 2; col <= A.nu; col++)
		{
			cpot[col] = cpot[col - 1] + num[col - 1];
		}
		for ( p = 1; p <= A.tu; p++)
		{
			q = cpot[A.data[p].j];
			B.data[q].i = A.data[p].j;
			B.data[q].j = A.data[p].i;
			B.data[q].e = A.data[p].e;
			++cpot[A.data[p].j];
		}
	}
	free(num);
	free(cpot);
	printf("\n\t\t\t     OK!\n\t\t\t     ��������������˵�");
	_getch();
	return;
}
void print(TSM A)
{
	system("cls");
	int i = 1, j = 1, p = 1;
	for (i = 1; i <= A.mu; i++)
	{
		printf("\n\t\t\t     ");
		for (j = 1; j <= A.nu; j++)
		{
			if (j == A.data[p].j&&i == A.data[p].i)
				printf("%d", A.data[p++].e);
			else
				printf("0");
		}
	}
	_getch();
	return;
}
void main()
{
	TSM A, B;
	int t;
	while (1)
	{
		system("cls");
		menu();
		scanf("%d", &t);
		switch (t)
		{
		case 1:Get(A); break;
		case 2:printTriple(A); break;
		case 3:turn(A,B); break;
		case 4:print(B); break;
		case 5:exit(0); break;

		}
	}
}