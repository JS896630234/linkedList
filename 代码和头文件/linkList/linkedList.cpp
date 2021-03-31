#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include"linkedList.h"

PNODE create()
{
	int len;	//����ĳ���
	int i;
	int val; //�ڵ��ֵ
	
	//��������ڵ�
	PNODE pHead = (PNODE)malloc(sizeof(NODE));
	if (NULL == pHead)
	{
		printf("����ʧ�ܣ������˳���");
		exit(-1);
	}
	PNODE pTail = pHead;
	pTail->next=NULL;      //��ֹ����Ϊ��

	printf("����������ڵ�ĸ���len��");
	scanf_s("%d", &len);
	for (i = 1; i <= len; i++)
	{
		printf("�������%d���ڵ��ֵ��",i);
		scanf_s("%d", &val);
		PNODE pNew= (PNODE)malloc(sizeof(NODE));
		if (NULL == pHead)
		{
			printf("����ʧ�ܣ������˳���");
			exit(-1);
		}
		pNew->data = val;

		//pTailΪβָ��,�ѽڵ���������
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
		printf("����Ϊ�գ��������\n");
		return 0;
	}
	PNODE p;
	p = pHead->next;
	printf("���������Ϊ��\n");
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
		printf("����Ϊ�գ��������\n");
		return pHead;
	}
	else 
	{
		printf("����ǿ�\n");
		return 0;
	}
}
int length(PNODE pHead)
{
	if (pHead == NULL || pHead->next == NULL)
	{
		printf("����Ϊ�գ��������\n");
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
		printf("����Ϊ�գ��������\n");
		return;
	}
	int i, j, t;
	int len = length(pHead);
	PNODE p, q;
	//ѡ������Ҳ����c++������������ؽ�p=p->next����Ϊp++��
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
	printf("���������!\n");
}
bool insert(PNODE pHead)
{
	int i;
	PNODE p;
	p = pHead;
	int pos, val;
	printf("������Ҫ�����λ�ú�ֵ:\n");
	scanf_s("%d", &pos);
	scanf_s("%d", &val);
	for(i=0;i<pos-1&&NULL!=p;++i)
	{
		p = p->next;
	}
	if (i>pos-1||NULL==p)
	{
		printf("������С��pos���������\n");
		return 0;
	}
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if (NULL == pHead)
	{
		printf("����ʧ�ܣ������˳���\n");
		exit(-1);
	}
	pNew->data = val;

	PNODE q = p->next ; //qΪ��ʱ���p����һλ�ڵ�
	p->next = pNew;
	pNew->next = q;
	//���������൱�ڣ�pNew->next = p->next;p->next = pNew;
	

	return 1;
}
bool delect(PNODE pHead)
{
	if (pHead == NULL || pHead->next == NULL)
	{
		printf("����Ϊ�գ��������\n");
		return 0;
	}
	PNODE p = pHead;
	int i;
	int pos;
	printf("������Ҫɾ����λ��:");
	scanf_s("%d", &pos);
	
	for (i = 0; i < pos - 1 && NULL != p; ++i)
	{
		p = p->next;
	}
	if (i > pos - 1 || NULL == p)
	{
		printf("������С��pos���������");
		return 0;
	}
	PNODE q=p->next;
	//ɾ��p�ڵ����Ľڵ�
	p->next = p->next->next;
	free(q);
	q = NULL;//��Ȼq�ռ䱻�ͷţ����Դ���
	printf("�ѳɹ�ɾ����%d���ڵ�\n", pos);
	return 1;
}
void destroy(PNODE pHead)
{
	if (pHead == NULL || pHead->next == NULL)
	{
		printf("����Ϊ�գ��������\n");
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
	printf("����������\n");
}
void find(PNODE pHead)
{
	
	if (pHead == NULL || pHead->next == NULL)
	{
		printf("����Ϊ�գ��������\n");
		return ;
	}
	int data;
	printf("������Ҫ���ҵ�ֵ:");
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
			printf("���ҵ������ڵ�%d���ڵ�\n", cnt+1);
			return; 
		}
	}
	printf("���ҵ����ݲ�������\n");
	
}
PNODE OddEven(PNODE head)
{
	if (head == NULL || head->next == NULL)
	{
		printf("����Ϊ�գ��������\n");
		return head;
	}
	PNODE root = head;//rootΪ�µ�����ͷָ��
	PNODE temp = root;//tempΪ�м���ʱ����
	PNODE p1, p2;
	
	while (temp->next != NULL && temp->next->next != NULL)
	{
		//p1Ϊԭ���������ڵ㣬p2Ϊԭ����ż���ڵ�
		p1 = temp->next;
		p2 = temp->next->next;


		temp->next = p2; //ͷָ��2
		p1->next = p2->next; //1ָ��3����֤�������������
		p2->next = p1;  //2ָ��1
		//ͷ->2->1->3�������Ѿ����ǰ�����ĶԻ���
		temp = p1;
		//�ٰ�ͷ��ʱ��Ϊԭ�ȵڶ���λ�ã�Ҳ��val=1.
	}
	return root;
}
PNODE Ireverse(PNODE pHead)
{
	if (pHead == NULL||pHead->next==NULL)
	{
		printf("����Ϊ�գ��������\n");
		return pHead;
	}
	PNODE prev = NULL; //prevΪ�������ͷָ��
	PNODE curr = pHead->next;
	PNODE temp ;
	while (curr) {
		temp = curr->next; //temp�ȱ���curr����һ���ڵ�
		curr->next = prev;  //currָ��prev����������			
		//��������Ųһ��λ��
		prev = curr;		
		curr = temp;
	}
	printf("����ɷ�ת��\n");
	return prev;
}
PNODE Rreverse(PNODE pHead)
{
	if (pHead == NULL || pHead->next==NULL) // ��ֹ����
	{
		return pHead;
	}
	PNODE curr = pHead->next;
	PNODE res = Rreverse(curr);			// �ݹ������������ڵ�
	pHead->next->next= pHead;					// ��һ��ָ��ǰһ ��
	pHead->next = NULL;				//ʹ���������һ���ڵ��ָ����ΪNULL
	printf("����ɷ�ת��\n");
	return res;
}
void findMiddle(PNODE pHead)
{
	if (pHead == NULL || pHead->next == NULL)
	{
		printf("����Ϊ�գ��������\n");
		return ;
	}
	PNODE p = pHead->next;
	int i, len;
	len = length(pHead);
	for (i = 0; i < len/2; i++)
	{
		p = p->next;
	}
	printf("�����м�ڵ�Ϊ%d\n", p->data);
	
}
bool is_circle(PNODE pHead)
{
	if (pHead == NULL || pHead->next == NULL)
	{
		printf("����Ϊ�գ��������\n");
		return 0;
	}
	PNODE fast=pHead->next;//fast������
	PNODE slow=pHead->next;//slow��һ��
	//����ɻ�����Ȼ����fast=slow�Ľڵ�
	while (fast != NULL)
	{
		fast = fast->next; 
		if (fast == NULL) { printf("�����ɻ�\n"); return 0; }  //���дfast=fast->next->next�����޷���֤fast->next�Ƿ�ΪNULL
		fast = fast->next;
		if (fast == NULL) { printf("�����ɻ�\n"); return 0; }
		slow = slow->next;
		if (fast == slow) { printf("����ɻ�\n"); return 1; }
	}
	printf("�����ɻ�\n");
	return 0;
}
void welcome(PNODE pHead)
{
	int choice;
	
A:	printf("                              ���˵�\n");
	printf("  -----------------------------------------------------------------------\n");
	printf("*****************************************************************************\n");
	printf("                      ��������Ҫ���еĲ�����1-8����\n");
	printf("\n");
	printf("             1---��������                   2---��������\n");
	printf("\n");
	printf("             3---��������                   4---ɾ������ \n");
	printf("\n");
	printf("             5---��������                   6---��ӡ����\n");
	printf("\n");
	printf("             7---��������                   8---�˳��˵�\n");
	printf("\n");
	printf("*****************************************************************************\n");
	printf("  -----------------------------------------------------------------------\n");
	printf("\n");
	printf("��������ţ�1-8����\n");
	while (!(scanf_s("%d", &choice) && getchar() == '\n'))
	{
		while (getchar() != '\n');					//��ջ�����
		printf("���������������������һ�飡\n");	//��ܰ����һ��
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

B:	printf("                              ��������\n");
	printf("*****************************************************************************\n");
	printf("                      ��������Ҫ���еĲ�����0-5����\n");
	printf("             (1)��ż����                   (2)�ҵ��е�\n");
	printf("             (3)�жϳɻ�                   (4)��ת����\n");
	printf("             (5)��������                   (0)�������˵� \n");
	printf("*****************************************************************************\n");
	printf("���������(1-4)��\n");
	
	while (!(scanf_s("%d", &choice) && getchar() == '\n'))
	{
		while (getchar() != '\n');					//��ջ�����
		printf("���������������������һ�飡\n");	//��ܰ����һ��
	}

	system("cls");
	switch (choice)
	{
	case 0:welcome(pHead);
	case 1:pHead=OddEven(pHead); goto B;
	case 2:findMiddle(pHead); goto B;
	case 3:is_circle(pHead); goto B;
	case 4:char select;
		printf("���������a/b��\n");
		printf("aΪ������bΪ�ݹ�\n");
		while (!(scanf_s("%c", &select) && getchar() == '\n'))
		{
			while (getchar() != '\n');					//��ջ�����
			printf("���������������������һ�飡\n");	//��ܰ����һ��
		}
		if (select == 'a')pHead = Ireverse(pHead);
		if (select == 'b')pHead = Rreverse(pHead);
		goto B;
	case 5:sort(pHead); goto B;
	}
}