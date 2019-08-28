#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <conio.h>
#define STACK_INIT_SIZE 100
typedef struct
{
	char *base;
	char *top;
	int stacksize;
}Sqstack;
Sqstack S,S1;
void InitStack(Sqstack &S)
{
	S.base = (char*)malloc(STACK_INIT_SIZE * sizeof(char));
	if (!S.base)
		printf("error!\n");
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
}
void ClearStack(Sqstack &S)
{
	S.top = S.base;
	return;
}
int Stackempty(Sqstack S)
{
	if (S.top == S.base)
		return 1;
	else
		return 0;
}
void push(Sqstack &S, char e)
{
	if (S.top - S.base == STACK_INIT_SIZE)
		S.base = (char*)realloc(S.base, (S.stacksize + 10) * sizeof(char));
	if (!S.base)
		printf("error!\n");
	*S.top++ = e;
	return;
}
void pop(Sqstack &S, char &e)
{
	if (S.top == S.base)
		printf("error!\n");
	e = *--S.top;
	return;
}
void GetTop(Sqstack &S,char &top)
{
	if (S.top > S.base)
	{
		top = *(S.top - 1);
		return;
	}
	else
		printf("error!");
}
void menu()
{
	printf("判断表达式括号匹配\n");
	printf("1．输入表达式\n");
	printf("2．输出表达式\n");
	printf("3．判断表达式的括号是否匹配并计算表达式的值\n");
	printf("4．退出\n");
}
void getc(char str[])
{
	printf("请输入表达式，以#结束\n");
	scanf("%s", str);
	printf("OK!\n按任意键返回主菜单\n");
	_getch();
	return ;
}
void putc(char str[])
{
	printf("该字符串为：%s\n",str);
	printf("OK!\n按任意键返回主菜单\n");
	_getch();
	return;
}
int In(char c) //判断c是否为运算符
{
	switch (c)
	{
	case'+':
	case'-':
	case'*':
	case'/':
	case'(':
	case')':
	case'#':
		return 1;
	default:
		return 0;
	}
}
char Precede(char  t1, char  t2) //判断两符号的优先关系
{
	char f;
	switch (t2)
	{
	case'+':
	case'-':
		if (t1 == '(' || t1 == '#')
			f = '<';
		else
			f = '>';
		break;
	case'*':
	case'/':
		if (t1 == '*' || t1 == '/' || t1 == ')')
			f = '>';
		else
			f = '<';
		break;
	case'(':
		if (t1 == ')')
		{
			printf("括号不匹配\n");
			exit(0);
		}
		else
			f = '<';
		break;
	case')':
		switch (t1)
		{
		case'(':
			f = '=';
			break;
		case'#':
			printf("缺乏左括号\n");
			exit(0);
		default:
			f = '>';
		}
		break;
	case'#':
		switch (t1)
		{
		case'#':
			f = '=';
			break;
		case'(':
			printf("缺乏右括号\n");
			exit(0);
		default:
			f = '>';
		}
	}
	return f;
}
int Operate(int a, char theta,int b) //做四则运算a theta b，返回运算结果
{
	switch (theta)
	{
	case'+':
		return a + b;
	case'-':
		return a - b;
	case'*':
		return a*b;
	}
	return a / b;
}
void EvaluateExpression(char str[])
{
	char *p,e;
	p = str;
	while (*p)
		switch(*p)
			{
			case '(':
			case '[':push(S, *p++); break;
			case ')':
			case ']':
				if (!Stackempty(S))
				{
					pop(S, e);
					if (*p == ')'&&e != '('|| *p == '['&&e != ']')
					{
						printf("括号不匹配！\n");
						_getch();
						return;
					}
					else
					{
						p++;
						break;
					}
				}
				else
				{
					printf("缺乏左括号!\n");
					_getch();
					return;
				}
			default:p++;
			}
	if (Stackempty(S))
	{
		printf("匹配!\n");
		ClearStack(S);
		ClearStack(S1);
		char a, b, *c, x,c2;
		int a1, b1,c1;
		push(S1, '#');
		c = str;
		GetTop(S1,x);
		while (*c != '#' || x != '#')
		{
			if(In(*c))
				switch (Precede(x, *c))
				{
				case '<':
				{
					push(S1, *c);
					c++;
					break;
				}
				case '=':
				{
					pop(S1, x);
					c++;
					break;
				}
				case '>':
					pop(S1, x);
					pop(S, b);
					pop(S, a);
					push(S,Operate(a, x, b));
					break;
				}
			else if (*c >= '0'&&*c <= '9')
			{
				push(S, *c-48);
				c++;
			}
			else
			{
				printf("出现非法字符\n");
				_getch();
				exit(0);
			}
			GetTop(S1, x);
		}
		pop(S, x);
		if (!Stackempty(S))
		{
			printf("表达式不正确\n");
			_getch();
			exit(0);
		}
		printf("结果为%d\n", x);
		_getch();
		return;
	}
	else
	{
		printf("缺乏左括号!\n");
		_getch();
		return;
	}
}
int main()
{
	InitStack(S);
	InitStack(S1);
	char str[80];
	int t;
	while (1)
	{

		system("cls");
		menu();
		scanf("%d", &t);
		switch (t)
		{
		case 1:getc(str); break;
		case 2:putc(str); break;
		case 3:EvaluateExpression(str); break;
		case 4:exit(0); break;
		}

	}

}
