#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <conio.h>
#define  OVERFLOW  -2
#define  ERROR  0
#define  OK  1
#define  TRUE  1
#define  FALSE  0
typedef struct LNode
{
	int num;
	struct LNode * next;
}LNode, *Linklist;
Linklist LA = (Linklist)malloc(sizeof(LNode));;
Linklist NEW = (Linklist)malloc(sizeof(LNode));
void LinkListInsert(Linklist &LA)
{
	int i, n;
	Linklist p1, p2;
	p1 = p2 = LA;
	LA->num= NULL;
	printf("���������ݸ���\n");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		p1 = (Linklist)malloc(sizeof(LNode));
		p1->next = NULL;
		printf("�������%d������\n",i+1);
		scanf("%d", &p1->num);
		p2->next = p1;
		p2 = p1;
	}
	printf("ok!\n");
	printf("�����������\n");
	_getch();
	return;
}
void LinkListPrint(Linklist LA)
{
	Linklist p;
	p = LA->next;
	while (p != NULL)
	{
		printf("%d\n", p->num);
		p = p->next;
	}
	printf("�����������\n");
	_getch();
	return;
}
void rolLink(Linklist LA, Linklist &NEW)
{
	Linklist p;
	NEW->next = NULL;
	while (LA->next != NULL)
	{
		p = LA->next;
		LA->next = p->next;
		p->next = NEW->next;
		NEW->next = p;
	}
	printf("ok!\n");
	printf("�����������\n");
	_getch();
	return;
}
void NewLinkListPrint(Linklist NEW)
{
	Linklist p;
	p = NEW->next;
	printf("�µ�����Ϊ\n");
	while (p != NULL)
	{
		printf("%d\n", p->num);
		p = p->next;
	}
	printf("�����������\n");
	_getch();
	return;
}
void menu()
{
	printf("1����������������\n");
	printf("2����������\n");
	printf("3�����������\n");
	printf("4������������\n");
	printf("5���������˳�\n");
}
int main()
{
	while (1)
	{
		system("cls");
		menu();
		int t;
		scanf("%d", &t);
		switch (t)
		{
		case 1:LinkListInsert(LA); break;
		case 2:LinkListPrint(LA); break;
		case 3:rolLink(LA,NEW); break;
		case 4:NewLinkListPrint(NEW); break;
		case 5:exit(0); break;
		}
	}
	return 0;
}