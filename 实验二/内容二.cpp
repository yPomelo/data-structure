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
	printf("�жϱ��ʽ����ƥ��\n");
	printf("1��������ʽ\n");
	printf("2��������ʽ\n");
	printf("3���жϱ��ʽ�������Ƿ�ƥ�䲢������ʽ��ֵ\n");
	printf("4���˳�\n");
}
void getc(char str[])
{
	printf("��������ʽ����#����\n");
	scanf("%s", str);
	printf("OK!\n��������������˵�\n");
	_getch();
	return ;
}
void putc(char str[])
{
	printf("���ַ���Ϊ��%s\n",str);
	printf("OK!\n��������������˵�\n");
	_getch();
	return;
}
int In(char c) //�ж�c�Ƿ�Ϊ�����
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
char Precede(char  t1, char  t2) //�ж������ŵ����ȹ�ϵ
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
			printf("���Ų�ƥ��\n");
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
			printf("ȱ��������\n");
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
			printf("ȱ��������\n");
			exit(0);
		default:
			f = '>';
		}
	}
	return f;
}
int Operate(int a, char theta,int b) //����������a theta b������������
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
						printf("���Ų�ƥ�䣡\n");
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
					printf("ȱ��������!\n");
					_getch();
					return;
				}
			default:p++;
			}
	if (Stackempty(S))
	{
		printf("ƥ��!\n");
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
				printf("���ַǷ��ַ�\n");
				_getch();
				exit(0);
			}
			GetTop(S1, x);
		}
		pop(S, x);
		if (!Stackempty(S))
		{
			printf("���ʽ����ȷ\n");
			_getch();
			exit(0);
		}
		printf("���Ϊ%d\n", x);
		_getch();
		return;
	}
	else
	{
		printf("ȱ��������!\n");
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
