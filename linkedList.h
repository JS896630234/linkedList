#pragma once
typedef int  ElemType;
typedef struct Node
{
	ElemType data;
	struct Node* next;
}NODE, * PNODE;
//NODE �ȼ���strcut Node *PNODE�ȼ���struct*Node



PNODE create();									//��������
bool traverse(PNODE pHead);						//��������
bool is_empty(PNODE pHead);						//�ж������Ƿ�Ϊ��
int length(PNODE pHead);						//������ĳ���
void sort(PNODE pHead);							//��������
bool insert(PNODE pHead);						//�ڵ�posλ��������
bool delect(PNODE pHead);						//�ڵ�posλɾ������
void destroy(PNODE pHead);						//��������
void find(PNODE pHead);							//ͨ��data��������
PNODE OddEven(PNODE pHead);						//������ż˳��Ի�
PNODE Ireverse(PNODE pHead);					//��ת����������
PNODE Rreverse(PNODE pHead);					//��ת�����ݹ飩
void findMiddle(PNODE pHead);					//���м�ڵ�
bool is_circle(PNODE pHead);					//�ж��Ƿ�ɻ�
void welcome(PNODE pHead);						//�˵�
void other(PNODE pHead);						//��������