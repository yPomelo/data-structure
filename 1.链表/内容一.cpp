#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <conio.h>
#define LIST_INIT_SIZE 100
#define LISTINCREATMENT 20
#define  OVERFLOW  -2
#define  ERROR  0
#define  OK  1
#define  TRUE  1
#define  FALSE  0
typedef struct
{
	int * elem;
	int length;
	int listsize;
} SqList;
typedef struct LNode
{
	int num;
	struct LNode * next;
}LNode, *Linklist;
int del, ser;
SqList L;
Linklist LA = (Linklist)malloc(sizeof(LNode));
void InitList(SqList &L)
{
	L.elem = (int*)malloc(LIST_INIT_SIZE * sizeof(int));
	if (!L.elem)
		exit(OVERFLOW);
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
}
void ListInsert(SqList &L)
{
	if (L.length == 0) 
	{
		int i,n;
		printf("��������Ҫ��������ݸ���\n");
		scanf("%d", &n);
		for (i = 0; i < n; i++)
		{
			printf("�������%d��ѧ��\n",i + 1);
			scanf("%d", L.elem + i);
			++L.length;
		}
		printf("ok!\n");
		printf("�����������\n");
		_getch();
		return;
	}
	else
	{
		int *newbase, *q, *p, i, e;
		printf("������Ҫ��������\n");
		scanf("%d", &i);
		printf("������Ҫ���������\n");
		scanf("%d", &e);
		if (i<1 || i>L.length + 1)
		{
			printf("error!\n");
			return;
		}
		if (L.length > L.listsize)
		{
			newbase = (int*)realloc(L.elem, (L.listsize + LISTINCREATMENT) * sizeof(int));
			if (!newbase)
				exit(OVERFLOW);
			L.elem = newbase;
			L.listsize = L.listsize + LISTINCREATMENT;
		}
		q = L.elem + i - 1;
		for (p = L.elem + L.length - 1; p >= q; p--)
			*(p + 1) = *p;
		*q = e;
		++L.length;
		printf("ok!\n");
		printf("�����������\n");
		_getch();
		return;
	}

}
void ListLength(SqList L)
{
	printf("��ǰ˳�����Ϊ%d\n", L.length);
	printf("�����������\n");
	_getch();
}
void ListDelete(SqList &L, int &del)
{
	int *p, *q, i;
	printf("������Ҫɾ��������\n");
	scanf("%d", &i);
	if (i<1 || i>L.length)
	{
		printf("error!\n");
		return;
	}
	p = L.elem + i - 1;
	*p = del;
	q = L.elem + i - 1;
	for (p++; q >= p; p++)
		*(p - 1) = *p;
	L.length--;
	printf("ok!\n");
	printf("�����������\n");
	_getch();
	return;

}
void ListPrint(SqList L)
{
	int n = 0, *p;
	p = L.elem;
	for (n; n < L.length; n++)
	{
		printf("num %d\n", *p);
		p++;
	}
	printf("�����������\n");
	_getch();
	return;
}
void LinkListInsert(Linklist &LA)
{
	if (LA->next == NULL)
	{
		int i, n;
		Linklist p1, p2;
		p2 = p1 = LA;
		printf("���������ݸ���\n");
		scanf("%d", &n);
		for (i = 0; i < n; i++)
		{
			p1 = (Linklist)malloc(sizeof(LNode));
			p1->next = NULL;
			printf("�������%d��ѧ��\n", i + 1);
			scanf("%d", &p1->num);
			p2->next = p1;
			p2 = p1;
		}
		printf("ok!\n");
		printf("�����������\n");
		_getch();
		return;
	}
	else
	{
		int n,j = 0;
		Linklist p,p1;
		printf("���������λ��\n");
		scanf("%d", &n);
		p = LA;
		while (p && j<n-1)
		{
			p = p->next;
			j++;
		}
		if (!p || j > n - 1)
			printf("error");
		p1 = (Linklist)malloc(sizeof(LNode));
		printf("���������ѧ��\n");
		scanf("%d", &p1->num);
		p1->next = p->next;
		p->next = p1;
		printf("ok!\n");
		printf("�����������\n");
		_getch();
		return;
	}
}
void LinkListDelete(Linklist &LA, int &del)
{
	int i, j = 0;
	printf("������Ҫɾ���ĺ���\n");
	scanf("%d", &i);
	Linklist p, q;
	p = LA;
	while (p->next&&j<i - 1)
	{
		p = p->next;
		j++;
	}
	if (!p->next || j>i - 1)
		printf("ɾ��λ�ò�����\n");
	q = p->next;
	p->next = q->next;
	del = q->num;
	free(q);
	printf("ɾ���ɹ���\n");
	printf("�����������\n");
	_getch();
	return;
}
void LinkListsearch(Linklist LA, int &ser)
{
	int i, j = 0;
	Linklist p;
	p = LA;
	printf("������Ҫ���ҵĺ���\n");
	scanf("%d", &i);
	while (p->next&&j<i)
	{
		p = p->next;
		j++;
	}
	if (!p || j>i)
		printf("error!\n");
	ser = p->num;
	printf("%d\n", ser);
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
void menu()
{
	printf("1��˳�������������\n");
	printf("2��˳����ɾ��\n");
	printf("3��˳���ĳ���\n");
	printf("4��˳������ʾ���\n");
	printf("5����������������\n");
	printf("6�������ɾ��\n");
	printf("7��ȡ����ĵ�i��Ԫ��\n");
	printf("8����������\n");
	printf("9���������˳�\n");
}
int main()
{
	InitList(L);
	LA->next = NULL;
	while (1)
	{
		system("cls");
		menu();
		int t;
		scanf("%d", &t);
		switch (t)
		{
		case 1:ListInsert(L); break;
		case 2:ListDelete(L, del); break;
		case 3:ListLength(L); break;
		case 4:ListPrint(L); break;
		case 5:LinkListInsert(LA); break;
		case 6:LinkListDelete(LA, del); break;
		case 7:LinkListsearch(LA, ser); break;
		case 8:LinkListPrint(LA); break;
		case 9:exit(0); break;
		}
	}
	return 0;
}