#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include"linkedList.h"

PNODE create()
{
	int len;	//链表的长度
	int i;
	int val; //节点的值
	
	//分配各个节点
	PNODE pHead = (PNODE)malloc(sizeof(NODE));
	if (NULL == pHead)
	{
		printf("分配失败，程序退出！");
		exit(-1);
	}
	PNODE pTail = pHead;
	pTail->next=NULL;      //防止链表为空

	printf("请输入链表节点的个数len：");
	scanf_s("%d", &len);
	for (i = 1; i <= len; i++)
	{
		printf("请输入第%d个节点的值：",i);
		scanf_s("%d", &val);
		PNODE pNew= (PNODE)malloc(sizeof(NODE));
		if (NULL == pHead)
		{
			printf("分配失败，程序退出！");
			exit(-1);
		}
		pNew->data = val;

		//pTail为尾指针,把节点连接起来
		pTail->next = pNew;
		pNew->next = NULL;
		pTail = pNew;
	}
	
	return pHead;
}
bool traverse(PNODE pHead)
{
	if (pHead == NULL || pHead->next == NULL)
	{
		printf("链表为空，输入错误\n");
		return 0;
	}
	PNODE p;
	p = pHead->next;
	printf("链表的数据为：\n");
	while (p!=NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
	return 1;
}
bool is_empty(PNODE pHead)
{
	if (pHead == NULL || pHead->next == NULL)
	{
		printf("链表为空，输入错误\n");
		return pHead;
	}
	else 
	{
		printf("链表非空\n");
		return 0;
	}
}
int length(PNODE pHead)
{
	if (pHead == NULL || pHead->next == NULL)
	{
		printf("链表为空，输入错误\n");
		return 0;
	}
	PNODE p;
	p = pHead->next;
	int cnt=0;
	while (NULL != p)
	{
		cnt++;
		p = p->next;
	}
	return cnt;
}
void sort(PNODE pHead)
{
	if (pHead == NULL || pHead->next == NULL)
	{
		printf("链表为空，输入错误\n");
		return;
	}
	int i, j, t;
	int len = length(pHead);
	PNODE p, q;
	//选择排序，也可在c++运用运算符重载将p=p->next重载为p++；
	for (i=0,p = pHead->next;i<len-1;i++, p = p->next)
	{
		for (j=i+1,q = p->next;j<len;  j++, q = q->next)
		{
			if (p->data > q->data)
			{
				t = p->data;
				p->data = q->data;
				q->data = t;
			}
		}
	}
	printf("已完成排序!\n");
}
bool insert(PNODE pHead)
{
	int i;
	PNODE p;
	p = pHead;
	int pos, val;
	printf("请输入要插入的位置和值:\n");
	scanf_s("%d", &pos);
	scanf_s("%d", &val);
	for(i=0;i<pos-1&&NULL!=p;++i)
	{
		p = p->next;
	}
	if (i>pos-1||NULL==p)
	{
		printf("链表长度小于pos，程序错误！\n");
		return 0;
	}
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if (NULL == pHead)
	{
		printf("分配失败，程序退出！\n");
		exit(-1);
	}
	pNew->data = val;

	PNODE q = p->next ; //q为临时存放p的下一位节点
	p->next = pNew;
	pNew->next = q;
	//以上三句相当于：pNew->next = p->next;p->next = pNew;
	

	return 1;
}
bool delect(PNODE pHead)
{
	if (pHead == NULL || pHead->next == NULL)
	{
		printf("链表为空，输入错误\n");
		return 0;
	}
	PNODE p = pHead;
	int i;
	int pos;
	printf("请输入要删除的位置:");
	scanf_s("%d", &pos);
	
	for (i = 0; i < pos - 1 && NULL != p; ++i)
	{
		p = p->next;
	}
	if (i > pos - 1 || NULL == p)
	{
		printf("链表长度小于pos，程序错误！");
		return 0;
	}
	PNODE q=p->next;
	//删除p节点后面的节点
	p->next = p->next->next;
	free(q);
	q = NULL;//虽然q空间被释放，但仍存在
	printf("已成功删除第%d个节点\n", pos);
	return 1;
}
void destroy(PNODE pHead)
{
	if (pHead == NULL || pHead->next == NULL)
	{
		printf("链表为空，输入错误\n");
		return;
	}
	int len = length(pHead);
	int i;

	PNODE p = pHead->next;
	
	for (i = 0; i < len; i++)
	{
		PNODE q = p->next;;
		
		free(p);
		p = q;
		
	}
	pHead->next = NULL;
	printf("已销毁链表！\n");
}
void find(PNODE pHead)
{
	
	if (pHead == NULL || pHead->next == NULL)
	{
		printf("链表为空，输入错误\n");
		return ;
	}
	int data;
	printf("请输入要查找的值:");
	scanf_s("%d", &data);
	PNODE p;
	int cnt = 0;
	p = pHead->next;
	
	while (p!=NULL)
	{
		cnt++;
		p = p->next;
		if (data == p->data)
		{
			printf("所找的数据在第%d个节点\n", cnt+1);
			return; 
		}
	}
	printf("所找的数据不在链表！\n");
	
}
PNODE OddEven(PNODE head)
{
	if (head == NULL || head->next == NULL)
	{
		printf("链表为空，输入错误\n");
		return head;
	}
	PNODE root = head;//root为新的链表头指针
	PNODE temp = root;//temp为中间临时变量
	PNODE p1, p2;
	
	while (temp->next != NULL && temp->next->next != NULL)
	{
		//p1为原链表奇数节点，p2为原链表偶数节点
		p1 = temp->next;
		p2 = temp->next->next;


		temp->next = p2; //头指向2
		p1->next = p2->next; //1指向3，保证后续链表的连续
		p2->next = p1;  //2指向1
		//头->2->1->3，到此已经完成前两个的对换。
		temp = p1;
		//再把头临时变为原先第二个位置，也即val=1.
	}
	return root;
}
PNODE Ireverse(PNODE pHead)
{
	if (pHead == NULL||pHead->next==NULL)
	{
		printf("链表为空，输入错误\n");
		return pHead;
	}
	PNODE prev = NULL; //prev为新链表的头指针
	PNODE curr = pHead->next;
	PNODE temp ;
	while (curr) {
		temp = curr->next; //temp先保存curr的下一个节点
		curr->next = prev;  //curr指向prev，反向排序			
		//整体往后挪一个位置
		prev = curr;		
		curr = temp;
	}
	printf("已完成反转！\n");
	return prev;
}
PNODE Rreverse(PNODE pHead)
{
	if (pHead == NULL || pHead->next==NULL) // 终止条件
	{
		return pHead;
	}
	PNODE curr = pHead->next;
	PNODE res = Rreverse(curr);			// 递归后继相邻两个节点
	pHead->next->next= pHead;					// 后一个指向前一 个
	pHead->next = NULL;				//使新链表最后一个节点的指针域为NULL
	printf("已完成反转！\n");
	return res;
}
void findMiddle(PNODE pHead)
{
	if (pHead == NULL || pHead->next == NULL)
	{
		printf("链表为空，输入错误\n");
		return ;
	}
	PNODE p = pHead->next;
	int i, len;
	len = length(pHead);
	for (i = 0; i < len/2; i++)
	{
		p = p->next;
	}
	printf("所求中间节点为%d\n", p->data);
	
}
bool is_circle(PNODE pHead)
{
	if (pHead == NULL || pHead->next == NULL)
	{
		printf("链表为空，输入错误\n");
		return 0;
	}
	PNODE fast=pHead->next;//fast走两步
	PNODE slow=pHead->next;//slow走一步
	//如果成环，必然会有fast=slow的节点
	while (fast != NULL)
	{
		fast = fast->next; 
		if (fast == NULL) { printf("链表不成环\n"); return 0; }  //如果写fast=fast->next->next，则无法保证fast->next是否为NULL
		fast = fast->next;
		if (fast == NULL) { printf("链表不成环\n"); return 0; }
		slow = slow->next;
		if (fast == slow) { printf("链表成环\n"); return 1; }
	}
	printf("链表不成环\n");
	return 0;
}
void welcome(PNODE pHead)
{
	int choice;
	
A:	printf("                              主菜单\n");
	printf("  -----------------------------------------------------------------------\n");
	printf("*****************************************************************************\n");
	printf("                      请输入你要进行的操作（1-8）：\n");
	printf("\n");
	printf("             1---创建链表                   2---销毁链表\n");
	printf("\n");
	printf("             3---插入数据                   4---删除数据 \n");
	printf("\n");
	printf("             5---查找数据                   6---打印链表\n");
	printf("\n");
	printf("             7---其他操作                   8---退出菜单\n");
	printf("\n");
	printf("*****************************************************************************\n");
	printf("  -----------------------------------------------------------------------\n");
	printf("\n");
	printf("请输入序号（1-8）：\n");
	while (!(scanf_s("%d", &choice) && getchar() == '\n'))
	{
		while (getchar() != '\n');					//清空缓存区
		printf("你输入的数据有误，请再输一遍！\n");	//温馨提醒一下
	}
	if(choice)
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
	case 7:other(pHead); goto A;
	case 8:break;
	default:printf("error\n"); goto A;
	};
	return;
}
void other(PNODE pHead)
{
	int choice;

B:	printf("                              其他操作\n");
	printf("*****************************************************************************\n");
	printf("                      请输入你要进行的操作（0-5）：\n");
	printf("             (1)奇偶调换                   (2)找到中点\n");
	printf("             (3)判断成环                   (4)反转链表\n");
	printf("             (5)数据排序                   (0)返回主菜单 \n");
	printf("*****************************************************************************\n");
	printf("请输入序号(1-4)：\n");
	
	while (!(scanf_s("%d", &choice) && getchar() == '\n'))
	{
		while (getchar() != '\n');					//清空缓存区
		printf("你输入的数据有误，请再输一遍！\n");	//温馨提醒一下
	}

	system("cls");
	switch (choice)
	{
	case 0:welcome(pHead);
	case 1:pHead=OddEven(pHead); goto B;
	case 2:findMiddle(pHead); goto B;
	case 3:is_circle(pHead); goto B;
	case 4:char select;
		printf("请输入序号a/b：\n");
		printf("a为迭代，b为递归\n");
		while (!(scanf_s("%c", &select) && getchar() == '\n'))
		{
			while (getchar() != '\n');					//清空缓存区
			printf("你输入的数据有误，请再输一遍！\n");	//温馨提醒一下
		}
		if (select == 'a')pHead = Ireverse(pHead);
		if (select == 'b')pHead = Rreverse(pHead);
		goto B;
	case 5:sort(pHead); goto B;
	}
}