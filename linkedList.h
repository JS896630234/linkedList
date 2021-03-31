#pragma once
typedef int  ElemType;
typedef struct Node
{
	ElemType data;
	struct Node* next;
}NODE, * PNODE;
//NODE 等价于strcut Node *PNODE等价于struct*Node



PNODE create();									//创建链表
bool traverse(PNODE pHead);						//遍历链表
bool is_empty(PNODE pHead);						//判断链表是否为空
int length(PNODE pHead);						//求链表的长度
void sort(PNODE pHead);							//数据排序
bool insert(PNODE pHead);						//在第pos位插入数据
bool delect(PNODE pHead);						//在第pos位删除数据
void destroy(PNODE pHead);						//销毁链表
void find(PNODE pHead);							//通过data查找数据
PNODE OddEven(PNODE pHead);						//链表奇偶顺序对换
PNODE Ireverse(PNODE pHead);					//反转链表（迭代）
PNODE Rreverse(PNODE pHead);					//反转链表（递归）
void findMiddle(PNODE pHead);					//找中间节点
bool is_circle(PNODE pHead);					//判断是否成环
void welcome(PNODE pHead);						//菜单
void other(PNODE pHead);						//其他操作