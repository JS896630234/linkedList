#include<stdio.h>
#include<stdlib.h>
#include"dulinkedList.h"

PDUNODE create()
{
	PDUNODE pNew, pTail,pHead;
	int i,len;
	pHead = (PDUNODE)malloc(sizeof(DUNODE));
	
	if(pHead==NULL)
	{
		printf("����ʧ�ܣ������˳�");
		exit(-1);
	}
	pHead->prior = pHead->next = NULL;
	printf("����������ĳ��ȣ�");
	scanf_s("%d", &len);
	if (len <= 0) { printf("����������"); return create(); }
	pTail = pHead;
	pNew = (PDUNODE)malloc(sizeof(DUNODE));
	for (i = 0; i < len; i++)
	{
		pNew = (PDUNODE)malloc(sizeof(DUNODE));

		if (pNew == NULL)
		{
			printf("����ʧ�ܣ������˳�");
			exit(-1);
		}
		printf("�������%d���ڵ��ֵ��", i + 1);
		scanf_s("%d", &pNew->data);
		//ǰ��ָ��
		pTail->next = pNew;
		pNew->prior = pTail;
		pTail = pTail->next;//����Ųһ��λ��
	}
	pNew->next = NULL;
	return pHead;
}
void traverse(PDUNODE pHead)
{
	if (pHead == NULL || pHead->next == NULL)
	{
		printf("����Ϊ�գ��������\n");
		return 0;
	}
	PDUNODE p;
	p = pHead->next;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
PDUNODE insert(PDUNODE pHead)
{
	if (pHead == NULL || pHead->next == NULL)
	{
		printf("����Ϊ�գ��������\n");
		return 0;
	}
	int pos;
	ElemType val;
	printf("������Ҫ�����λ�ú�ֵ:\n");
	scanf_s("%d", &pos);
	scanf_s("%d", &val);
	if (pHead == NULL || pHead->next == NULL)return NULL;
	PDUNODE p = pHead;
	int i=0;
	while (i < pos-1&& p != NULL)
	{
		p = p->next; i++;
	}
	if (i > pos - 1 || NULL == p)
	{
		printf("������С��pos���������");
		return 0;
	}
	PDUNODE pNew = (PDUNODE)malloc(sizeof(DUNODE));
	if (pHead == NULL)
	{
		printf("����ʧ�ܣ������˳�");
		exit(-1);
	}
	//�����ڵ�ָ��ǰ��
	if(p->next!=NULL)
	{
	pNew->prior = p;
	pNew->data = val;
	pNew->next = p->next;

	//��ڵ�ָ������
	p->next->prior = pNew;
	//ǰ�ڵ�ָ������
	p->next = pNew;

	}
	if (p->next == NULL)  //�������һ��ʱ
	{
		pNew->data = val;
		pNew->prior = p;
		p->next = pNew;
		pNew->next = NULL;
	}
	return pHead;
}
PDUNODE delect(PDUNODE pHead)
{ 
	if (pHead == NULL || pHead->next == NULL)
	{
		printf("����Ϊ�գ��������\n");
		return 0;
	}
	int pos;
	printf("������Ҫɾ����λ��:");
	scanf_s("%d", &pos);
	PDUNODE p = pHead;
	int i = 0;
	while (i < pos - 1 && p != NULL)
	{
		p = p->next; i++;
	}
	if (i > pos - 1 || NULL == p)
	{
		printf("������С��pos���������");
		return 0;
	}
	int val = p->next->data;
	p->next->next->prior = p;
	p->next = p->next->next;
	printf("��ɾ����%dΪ������,��ֵΪ%d\n", pos,val);

	return pHead; 
}
void destroy(PDUNODE pHead)
{
	if (pHead == NULL || pHead->next == NULL)
	{
		printf("����Ϊ�գ��������\n");
		return ;
	}
	int len = length(pHead);
	int i;

	PDUNODE p = pHead->next;

	for (i = 0; i < len; i++)
	{
		PDUNODE q = p->next;;

		free(p);
		p = q;

	}
	pHead->next = NULL;
	printf("����������\n");
}
PDUNODE find(PDUNODE pHead)
{
	int data;
	printf("������Ҫ���ҵ�ֵ��\n");
	scanf_s("%d", &data);
	if (pHead == NULL || pHead->next == NULL)
	{
		printf("����Ϊ�գ��������\n");
		return 0;
	}
	PDUNODE p;
	int cnt = 0;
	p = pHead->next;

	while (p != NULL)
	{
		cnt++;
		p = p->next;
		if (data == p->data)
		{
			printf("���ҵ������ڵ�%d���ڵ�\n", cnt);
			return p;
		}
	}
	return NULL;
}
int length(PDUNODE pHead)
{
	PDUNODE p;
	p = pHead->next;
	int cnt = 0;
	while (NULL != p)
	{
		cnt++;
		p = p->next;
	}
	return cnt;
}
void welcome(PDUNODE pHead)
{
	int choice;

A:	printf("                              ���˵�\n");
	printf("  -----------------------------------------------------------------------\n");
	printf("*****************************************************************************\n");
	printf("                      ��������Ҫ���еĲ�����0-6����\n");
	printf("\n");
	printf("             1---��������                   2---��������\n");
	printf("\n");
	printf("             3---��������                   4---ɾ������ \n");
	printf("\n");
	printf("             5---��������                   6---��ӡ����\n");
	printf("\n");
	printf("*****************************************************************************\n");
	printf("  -----------------------------------------------------------------------\n");
	printf("\n");
	printf("��������ţ�0-6��(0--�˳����򣩣�\n");
	while (!(scanf_s("%d", &choice) && getchar() == '\n'))
	{
		while (getchar() != '\n');					//��ջ�����
		printf("���������������������һ�飡\n");	//��ܰ����һ��
	}
	if (choice)
		system("cls");
	fflush(stdin);
	switch (choice)
	{
	case 1:pHead = create(); goto A;
	case 2:destroy(pHead); goto A;
	case 3:insert(pHead); goto A;
	case 4:delect(pHead); goto A;
	case 5:find(pHead); goto A;
	case 6:traverse(pHead); goto A;
	default:printf("error\n"); goto A;
	};
	return;
}
