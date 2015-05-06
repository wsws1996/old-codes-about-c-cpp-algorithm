// 链表有关源码.cpp : 定义控制台应用程序的入口点。
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

PNODE create_list(void)//创建链表
{
	int len;//有效链表节点数
	int cnt;//计数变量
	int val;//临时存放节点值

	PNODE pHead = (PNODE)malloc(sizeof(NODE));
	if (NULL == pHead)
	{
		printf("动态内存分配失败，程序退出！\n");
		exit(-1);
	}
	PNODE pTail = pHead;
	pTail->pNext = NULL;
	scanf("%d", &len);
	for (cnt = 0; cnt < len; ++cnt)
	{
		printf("请输入节点值：");
		scanf("%d", &val);
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if (NULL == pNew)
		{
			printf("分配失败，程序退出！\n");
			exit(-1);
		}
		pNew->data = val;
		pTail->pNext = pNew;
		pNew->pNext = NULL;
		pTail = pNew;
	}
	return pHead;
}

void traverse_list(PNODE pHead)//遍历链表
{
	PNODE p = pHead->pNext;

	while (NULL != p)
	{
		printf("%d\n", p->data);
		p = p->pNext;
	}
}

bool is_empty(PNODE pHead)//判断是否为空
{
	if (pHead->pNext == NULL)
		return true;
	else
		return false;
}

int length_list(PNODE pHead)//求链表长度
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

bool insert_list(PNODE pHead, int pos, int val)//向链表中插入数据
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
		printf("动态内存分配失败，程序退出！\n");
		exit(-1);
	}
	pNew->data = val;
	PNODE q = p->pNext;
	p->pNext = pNew;
	pNew->pNext = q;
	return true;
}

bool delete_list(PNODE pHead, int pos, int * pVal)//从链表中删除数据
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

void sort_list(PNODE pHead)//对链表中数据排序
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

