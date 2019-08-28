#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct
{
	char name[10];
	int grade;
	char zy[10];
	int age;
}student;

int n;

void menu()
{
	printf("1.����ѧ����\n");
	printf("2.����ѧ������������Ϣ\n");
	printf("3.���ѧ��������Ϣ��\n");
	printf("4.��˳������㷨ʵ�ֲ���\n");
	printf("5.���۰�����㷨ʵ�ֲ���\n");
	printf("6.�˳�\n");
	printf("7.��ѡ��");
}

void out(student *a)
{
	int i;
	for (i = 1; i <= n; i++)
	{
		printf("\n��%d��ѧ��������%s ���䣺%d רҵ��%s �꼶��%d", i, (a + i)->name, (a + i)->age, (a + i)->zy, (a + i)->grade);
	}
}

int Search(student *a)
{
	char t[10];
	printf("������Ҫ����ѧ������:");
	scanf("%s", t);
	int i;
	strcpy(a->name, t);
	for (i = n; !strcmp((a + i)->name, t); --i);
	return i;
}

int HalfSearch(student *a)
{
	char t[10];
	printf("������Ҫ����ѧ������:");
	scanf("%s", &t);
	int i, j;
	for (i = 2; i <= n; i++)
		if (strcmp((a + i)->name, (a + i - 1)->name)<0)
		{
			*a = *(a + i);
			*(a + i) = *(a + i - 1);
			for (j = i - 2; strcmp(a->name, (a + j)->name)<0; j--)
				*(a + j + 1) = *(a + j);
			*(a + j + 1) = *a;
		}
	int mid, low = 1, high = n;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (!strcmp(t, (a + mid)->name))
			return mid;
		else if (strcmp(t, (a + mid)->name)<0)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return 0;
}

int main()
{
	int choice, i;
	student *a;
	while (1)
	{
		system("cls");
		menu();
		scanf("%d", &choice);
		getchar();
		switch (choice)
		{
		case 1:
		{
			printf("������ѧ����");
			scanf("%d", &n);
			a = (student*)malloc((n + 1) * sizeof(student));
			printf("\n��ѡ��2��������");
			_getch();
		}break;
		case 2:
		{
			for (i = 1; i <= n; i++)
			{
				printf("                           ���� ���� �꼶 רҵ");
				printf("\n�������%d��ѧ���Ļ�����Ϣ:", i);
				scanf("%s%d%d%s", (a + i)->name, &(a + i)->age, &(a + i)->grade, (a + i)->zy);
			}
			printf("\n��ѡ����3��4��5");
			_getch();
		}break;
		case 3:out(a); printf("\n�����������"); _getch(); break;
		case 4:
		{
			i = Search(a);
			if (!i)
				printf("error!");
			else
			{
				printf("\n��%d��ѧ��������%s ���䣺%d רҵ��%s �꼶��%d", i, (a + i)->name, (a + i)->age, (a + i)->zy, (a + i)->grade);
			}
			printf("\n�����������");
			_getch();
		}break;
		case 5:
		{
			i = HalfSearch(a);
			if (!i)
				printf("error!");
			else
			{

				printf("\n��%d��ѧ��������%s ���䣺%d רҵ��%s �꼶��%d", i, (a + i)->name, (a + i)->age, (a + i)->zy, (a + i)->grade);
			}
			printf("\n�����������");
			_getch();
		}break;
		case 6:	return 0;
		}
	}
}