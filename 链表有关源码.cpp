// �����й�Դ��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "stdio.h"
#include "malloc.h"
#include"stdlib.h"
#include"windows.h"

typedef struct Node
{
	int data;
	struct Node *pNext;
}NODE, *PNODE;

PNODE create_list(void)//��������
{
	int len;//��Ч����ڵ���
	int cnt;//��������
	int val;//��ʱ��Žڵ�ֵ

	PNODE pHead = (PNODE)malloc(sizeof(NODE));
	if (NULL == pHead)
	{
		printf("��̬�ڴ����ʧ�ܣ������˳���\n");
		exit(-1);
	}
	PNODE pTail = pHead;
	pTail->pNext = NULL;
	scanf("%d", &len);
	for (cnt = 0; cnt < len; ++cnt)
	{
		printf("������ڵ�ֵ��");
		scanf("%d", &val);
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if (NULL == pNew)
		{
			printf("����ʧ�ܣ������˳���\n");
			exit(-1);
		}
		pNew->data = val;
		pTail->pNext = pNew;
		pNew->pNext = NULL;
		pTail = pNew;
	}
	return pHead;
}

void traverse_list(PNODE pHead)//��������
{
	PNODE p = pHead->pNext;

	while (NULL != p)
	{
		printf("%d\n", p->data);
		p = p->pNext;
	}
}

bool is_empty(PNODE pHead)//�ж��Ƿ�Ϊ��
{
	if (pHead->pNext == NULL)
		return true;
	else
		return false;
}

int length_list(PNODE pHead)//��������
{
	int len=0;
	PNODE p = pHead->pNext;

	while (NULL != p)
	{
		len++;
		p = p->pNext;
	}
	return len;
}

bool insert_list(PNODE pHead, int pos, int val)//�������в�������
{
	int cnt = 0;
	PNODE p = pHead;
	while (NULL != p && cnt < pos - 1)
	{
		p = p->pNext;
		++cnt;
	}

	if (cnt>pos-1 || NULL==p)
		return false;

	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if (NULL == pNew)
	{
		printf("��̬�ڴ����ʧ�ܣ������˳���\n");
		exit(-1);
	}
	pNew->data = val;
	PNODE q = p->pNext;
	p->pNext = pNew;
	pNew->pNext = q;
	return true;
}

bool delete_list(PNODE pHead, int pos, int * pVal)//��������ɾ������
{
	int cnt = 0;
	PNODE p = pHead;

	while (NULL != p->pNext && cnt < pos - 1)
	{
		p=p->pNext;
		++cnt;
	}

	if (cnt>pos-1 || NULL==p->pNext)
		return false;

	PNODE q = p->pNext;
	*pVal == q->data;

	p->pNext = p->pNext->pNext;
	free(q);
	q = NULL;
	return true;
}

void sort_list(PNODE pHead)//����������������
{
	int t;
	int len = length_list(pHead);
	PNODE p,q;

	for (p = pHead->pNext; p != NULL; p = p->pNext)
	{
		for (q = p->pNext; q != NULL; q = q->pNext)
		{
			if (p->data > q->data)
			{
				t = p->data;
				p->data = q->data;
				q->data = t;
			}
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	PNODE pHead = NULL;
	int val;
	int *pVal;
	pVal = &val;
	pHead = create_list();
	//sort_list(pHead);
	traverse_list(pHead);
	insert_list(pHead, 2, 99);
	traverse_list(pHead);
	delete_list(pHead, 3, pVal);
	traverse_list(pHead);
	//if (is_empty(pHead))
	//	printf("yes\n");
	//else
	//	printf("no\n");
	//printf("%d\n", length_list(pHead));
	system("pause");

	return 0;
}

