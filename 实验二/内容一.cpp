#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <conio.h>
#define STACK_INIT_SIZE 100
typedef struct
{
	int *base;
	int *top;
	int stacksize;
}Sqstack;
Sqstack S;
void InitStack(Sqstack &S)
{
	S.base = (int*)malloc(STACK_INIT_SIZE * sizeof(int));
	if (!S.base)
		printf("error!\n");
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
}
int Stackempty(Sqstack S)
{
	if (S.top == S.base)
		return 1;
	else
		return 0;
}
void push(Sqstack &S,int e)
{
	if (S.top - S.base == STACK_INIT_SIZE)
		S.base = (int*)realloc(S.base, (S.stacksize + 10) * sizeof(int));
	if (!S.base)
		printf("error!\n");
	*S.top++ = e;
	return;
}
void pop(Sqstack &S, int &e)
{
	if (S.top == S.base)
		printf("error!\n");
	e = *--S.top;
	return;
}
void menu()
{
	printf("����ת��\n");
	printf("1������һ��ʮ������n\n");
	printf("2������ת���Ľ���m\n");
	printf("3������ת�� \n");
	printf("4�������񣿣�y/n?��\n");
}
//����һ��ʮ������n
void getnum(int &n)
{
	printf("������һ��ʮ������\n");
	scanf("%d", &n);
	printf("OK!\n��������������˵�");
	_getch();
	return;
}
//����ת���Ľ���m
void getchange(int &m)
{
	printf("������ת���Ľ���\n");
	scanf("%d", &m);
	printf("OK!\n��������������˵�");
	_getch();
	return;
}
//����ת�� 
void change(int n,int m)
{
	int e;
	while (n != 0)
	{
		push(S, n%m);
		n = n / m;
	}
	printf("n��%d������Ϊ��", m);
	while (!Stackempty(S))
	{
		pop(S, e);
		printf("%d", e);
	}
	printf("\n�����������\n");
	_getch();
	return;
}
int main()
{
	InitStack(S);
	int t, n, m;
	while (1)
	{

		system("cls");
		menu();
		scanf("%d", &t);
		switch (t)
		{
			case 1:getnum(n); break;
			case 2:getchange(m); break;
			case 3:change(n,m); break;
			case 4:exit(0); break;
		}

	}

}
