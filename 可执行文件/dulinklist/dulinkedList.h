#pragma once
typedef int ElemType;

typedef struct dunode {
	ElemType data;
	struct dunode* prior;
	struct dunode* next;
}DUNODE, * PDUNODE;


PDUNODE create();									  //创建
void traverse(PDUNODE);								  //打印
PDUNODE insert(PDUNODE pHead);					      //插入
PDUNODE delect(PDUNODE pHead);						  //删除
int length(PDUNODE pHead);							  //求长度
void destroy(PDUNODE pHead);						  //销毁
PDUNODE find(PDUNODE pHead);						  //查找
