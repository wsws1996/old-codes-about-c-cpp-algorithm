# include"stdafx.h"
# include<windows.h>
# include<stdio.h>
# include<malloc.h>
# include<stdlib.h>

typedef struct Node
{
	int data;
	struct Node *pNext;
}NODE, * PNODE;

typedef struct Stack
{
	PNODE pTop;
	PNODE pBottom;
}STACK, *PSTACK;

bool empty(PSTACK pS)
{
	if (pS->pTop == pS->pBottom)
		return true;
	else
		return false;
}

void init(PSTACK pS)
{
	pS->pTop = (PNODE)malloc(sizeof(NODE));
	if (NULL == pS->pTop)
	{
		printf("动态内存分配失败!\n");
		exit(-1);
	}
	pS->pBottom = pS->pTop;
	pS->pTop->data = NULL;
	pS->pTop->pNext = NULL;
}

void push(PSTACK pS, int val)
{
	PNODE pNew;
	pNew = (PNODE)malloc(sizeof(NODE));
	pNew->data = val;
	pNew->pNext = pS->pTop;
	pS->pTop = pNew;
}

void traverse(PSTACK pS)
{
	PNODE p = pS->pTop;

	while(p != pS->pBottom)
	{
		printf("%d\n", p->data);
		p = p->pNext;
	}
	printf("\n");
}

bool pop(PSTACK pS, int * pVal)
{
	if (empty(pS))
	{
		return false;
	}
	else
	{
		PNODE r;
		r = pS->pTop;
		*pVal = r->data;
		pS->pTop = pS->pTop->pNext;
		free(r);
		r = NULL;
		return true;
	}
}

void clear(PSTACK pS)
{
	if (empty(pS))
	{
		return;
	}
	PNODE p, q;
	p = pS->pTop;
	while (p != pS->pBottom)
	{
		q = p->pNext;
		free(p);
		p = q;
	}
	pS->pTop = pS->pBottom;
}

int main(void)
{
	STACK S;
	int * pVal;
	int val;
	pVal = &val;

	init(&S);
	push(&S, 1);
	push(&S, 2);
	push(&S, 3);

	traverse(&S);
	clear(&S);
	if (empty(&S))
		printf("清空成功！\n");

	system("pause");
	return 0;
}