#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
typedef struct QNode
{
	int score;
	char name[10];
}student;

int n;

void menu()
{
	printf("\n\t****************");
	printf("\n\t1������ѧ������ѧ���������ɼ�\n");
	printf("\n\t2����ֱ�Ӳ��������������\n");
	printf("\n\t3����ѡ�������������\n");
	printf("\n\t4���ÿ��������������\n");
	printf("\n\t5����ϣ�������������\n");
	printf("\n\t****************");
}

void InsertSort(student *a)
{
	int i, j;
	for (i = 2; i <= n; i++)
	{
		if ((a + i)->score<(a + i - 1)->score)
		{
			*a = *(a + i);
			*(a + i) = *(a + i - 1);
			for (j = i - 2; a->score<(a + j)->score; j--)
				*(a + j + 1) = *(a + j);
			*(a + j + 1) = *a;
		}
	}
}

void SelectSort(student *a)
{
	int i, j, k, p;
	student t;
	for (i = 1; i<n; i++)
	{
		p = (a + i)->score;
		for (j = i + 1;j<=n - i;j++)
		{
			if ((a + j)->score < p)
			{
				k = j;
				p = (a + j)->score;
			}
		}
		if (i != k)
		{
			t = *(a + i);
			*(a + i) = *(a + k);
			*(a + k) = t;
		}
	}
}

void ShellInsert(student *a,int dk)
{
	int i, j;
	for (i = dk + 1; i <= n; i++)
		if ((a + i)->score < (a + i - dk)->score)
		{
			*a = *(a + i);
			for (j = i - dk; a->score < (a + j)->score;j-=dk)
				*(a + j + dk) = *(a + j);
			*(a + j + dk) = *a;
		}
}

void Print1(student *a)
{
	int i;
	for (i = 1; i <= n; i++)
		printf("%d\n", (a + i)->score);
}

void ShellSort(student *a, int dlta[], int t)
{
	int k;
	for (k = 0; k < t; k++)
	{
		ShellInsert(a, dlta[k]);
		printf("dlta[%d] = %d,��%d��������", k, dlta[k], k + 1);
		Print1(a);
	}
}

int Partition(student *a, int low, int high)
{
	int pivotkey;
	pivotkey = (a + low)->score;
	*a = *(a + low);
	while (low<high)
	{
		while (low<high && (a + high)->score >= pivotkey)
			--high;
		*(a + low) = *(a + high);
		while (low<high && (a + low)->score <= pivotkey)
			++low;
		*(a + high) = *(a+low);
	}
	*(a + low) = *a;
	return low;
}

void Qsort(student *a, int low, int high)
{
	int pivotloc;
	if (low<high)
	{
		pivotloc = Partition(a, low, high);
		Qsort(a, low, pivotloc - 1);
		Qsort(a, pivotloc + 1, high);
	}
}

void QuickSort(student *a)
{
	Qsort(a, 1, n);
}

int main()
{
	int t;
	int i;
	student *a;
	while (1) {
		system("cls");
		menu();
		printf("\n\t��ѡ��:");
		scanf("%d", &t);
		switch (t)
		{
		case 1:
		{
			printf("\n\t������ѧ����:");
			scanf("%d", &n);
			a = (student*)malloc(sizeof(student)*(n + 1));
			for (i = 1; i <= n; i++)
			{
				printf("\n\t�������%d��ѧ�����������ɼ�:", i);
				scanf("%s%d", (a + i)->name, &(a + i)->score);
			}
			printf("\n\tok!");
		}; _getch(); break;
		case 2:
		{
			InsertSort(a);
			for (i = 1; i <= n; i++)
				printf("\n\t������%s,�ɼ���%d", (a + i)->name, (a + i)->score);
		}
		_getch();
		break;
		case 3:
		{
			SelectSort(a);
			for (i = 1; i <= n; i++)
				printf("\n\t������%s,�ɼ���%d", (a + i)->name, (a + i)->score);
		}
		_getch(); break;
		case 4:
		{
			QuickSort(a);
			for (i = 1; i <= n; i++)
				printf("\n\t������%s,�ɼ���%d", (a + i)->name, (a + i)->score);
		}
		_getch(); break;
		case 5:
		{
			int w, dlta[10];
			printf("���������������磺��3�鼴���룺3��\n");
			scanf("%d", &w);
			printf("���������dlta���磺��3�鼴���룺3 2 1��\n");
			for (i = 0; i < w; i++)
				scanf("%d", &dlta[i]);
			ShellSort(a,dlta,w);
			for (i = 1; i <= n; i++)
				printf("\n\t������%s,�ɼ���%d", (a + i)->name, (a + i)->score);
		}
		_getch(); break;
		case 6:exit(0);
		default:exit(0);
		}
	}
	return 0;
}

