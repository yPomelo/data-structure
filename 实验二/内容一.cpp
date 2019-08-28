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
	printf("进制转换\n");
	printf("1．输入一个十进制数n\n");
	printf("2．输入转换的进制m\n");
	printf("3．进制转换 \n");
	printf("4．继续否？（y/n?）\n");
}
//输入一个十进制数n
void getnum(int &n)
{
	printf("请输入一个十进制数\n");
	scanf("%d", &n);
	printf("OK!\n按任意键返回主菜单");
	_getch();
	return;
}
//输入转换的进制m
void getchange(int &m)
{
	printf("请输入转换的进制\n");
	scanf("%d", &m);
	printf("OK!\n按任意键返回主菜单");
	_getch();
	return;
}
//进制转换 
void change(int n,int m)
{
	int e;
	while (n != 0)
	{
		push(S, n%m);
		n = n / m;
	}
	printf("n的%d进制数为：", m);
	while (!Stackempty(S))
	{
		pop(S, e);
		printf("%d", e);
	}
	printf("\n按任意键继续\n");
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
