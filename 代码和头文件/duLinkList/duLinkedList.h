#pragma once
typedef int ElemType;

typedef struct dunode {
	ElemType data;
	struct dunode* prior;
	struct dunode* next;
}DUNODE, * PDUNODE;


PDUNODE create();									  //����
void traverse(PDUNODE);								  //��ӡ
PDUNODE insert(PDUNODE pHead);					      //����
PDUNODE delect(PDUNODE pHead);						  //ɾ��
int length(PDUNODE pHead);							  //�󳤶�
void destroy(PDUNODE pHead);						  //����
PDUNODE find(PDUNODE pHead);						  //����
