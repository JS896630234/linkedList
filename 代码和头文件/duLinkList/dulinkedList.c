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
		printf("分配失败，程序退出");
		exit(-1);
	}
	pHead->prior = pHead->next = NULL;
	printf("请输入链表的长度：");
	scanf_s("%d", &len);
	if (len <= 0) { printf("请重新输入"); return create(); }
	pTail = pHead;
	pNew = (PDUNODE)malloc(sizeof(DUNODE));
	for (i = 0; i < len; i++)
	{
		pNew = (PDUNODE)malloc(sizeof(DUNODE));

		if (pNew == NULL)
		{
			printf("分配失败，程序退出");
			exit(-1);
		}
		printf("请输入第%d个节点的值：", i + 1);
		scanf_s("%d", &pNew->data);
		//前后指向
		pTail->next = pNew;
		pNew->prior = pTail;
		pTail = pTail->next;//往后挪一个位置
	}
	pNew->next = NULL;
	return pHead;
}
void traverse(PDUNODE pHead)
{
	if (pHead == NULL || pHead->next == NULL)
	{
		printf("链表为空，输入错误\n");
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
		printf("链表为空，输入错误\n");
		return 0;
	}
	int pos;
	ElemType val;
	printf("请输入要插入的位置和值:\n");
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
		printf("链表长度小于pos，程序错误！");
		return 0;
	}
	PDUNODE pNew = (PDUNODE)malloc(sizeof(DUNODE));
	if (pHead == NULL)
	{
		printf("分配失败，程序退出");
		exit(-1);
	}
	//新增节点指向前后
	if(p->next!=NULL)
	{
	pNew->prior = p;
	pNew->data = val;
	pNew->next = p->next;

	//后节点指向新增
	p->next->prior = pNew;
	//前节点指向新增
	p->next = pNew;

	}
	if (p->next == NULL)  //插入最后一个时
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
		printf("链表为空，输入错误\n");
		return 0;
	}
	int pos;
	printf("请输入要删除的位置:");
	scanf_s("%d", &pos);
	PDUNODE p = pHead;
	int i = 0;
	while (i < pos - 1 && p != NULL)
	{
		p = p->next; i++;
	}
	if (i > pos - 1 || NULL == p)
	{
		printf("链表长度小于pos，程序错误！");
		return 0;
	}
	int val = p->next->data;
	p->next->next->prior = p;
	p->next = p->next->next;
	printf("已删除第%d为的数据,其值为%d\n", pos,val);

	return pHead; 
}
void destroy(PDUNODE pHead)
{
	if (pHead == NULL || pHead->next == NULL)
	{
		printf("链表为空，输入错误\n");
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
	printf("以销毁链表！\n");
}
PDUNODE find(PDUNODE pHead)
{
	int data;
	printf("请输入要查找的值：\n");
	scanf_s("%d", &data);
	if (pHead == NULL || pHead->next == NULL)
	{
		printf("链表为空，输入错误\n");
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
			printf("所找的数据在第%d个节点\n", cnt);
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

A:	printf("                              主菜单\n");
	printf("  -----------------------------------------------------------------------\n");
	printf("*****************************************************************************\n");
	printf("                      请输入你要进行的操作（0-6）：\n");
	printf("\n");
	printf("             1---创建链表                   2---销毁链表\n");
	printf("\n");
	printf("             3---插入数据                   4---删除数据 \n");
	printf("\n");
	printf("             5---查找数据                   6---打印链表\n");
	printf("\n");
	printf("*****************************************************************************\n");
	printf("  -----------------------------------------------------------------------\n");
	printf("\n");
	printf("请输入序号（0-6）(0--退出程序）：\n");
	while (!(scanf_s("%d", &choice) && getchar() == '\n'))
	{
		while (getchar() != '\n');					//清空缓存区
		printf("你输入的数据有误，请再输一遍！\n");	//温馨提醒一下
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
