#include"stdafx.h"
# include<stdio.h>
# include<malloc.h>
#include"string.h"
# include<stdlib.h>

typedef struct Node
{
	char bra;
	struct Node *pNext;
}NODE, *PNODE;

typedef struct Stack
{
	PNODE pTop;
	PNODE pBottom;
}STACK, *PSTACK;

void init(PSTACK pS)
{
	pS->pTop = (PNODE)malloc(sizeof(NODE));
	if (pS->pTop == NULL)
	{
		printf("¶¯Ì¬ÄÚ´æ·ÖÅäÊ§°Ü£¡\n");
		exit(-1);
	}
	pS->pBottom = pS->pTop;
	pS->pBottom->pNext = NULL;
	pS->pBottom->bra = NULL;
}

void push(PSTACK pS, char half)
{
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	pNew->bra = half;
	pNew->pNext = pS->pTop;
	pS->pTop = pNew;
}
PNODE find(PSTACK pS, char half)
{
	PNODE p;
	p = pS->pTop;
	if (p->bra == half)
		return p;
	while (p ->pNext!= NULL)
	{
		if (p->pNext->bra == half)
			return p;
		p = p->pNext;
	}
	return NULL;
}
void delete_half(PNODE p,PSTACK pS)
{
	if (p == pS->pTop)
	{
		PNODE r;
		r = pS->pTop;
		pS->pTop = pS->pTop->pNext;
		free(r);
	}
	else
	{
		PNODE q;
		q = p->pNext;
		p->pNext = p->pNext->pNext;
		free(q);
	}
}
bool is_empty(PSTACK pS)
{
	if (pS->pTop->pNext == NULL)
		return true;
	return false;
}
void clear(PSTACK pS)
{
	PNODE p, pTemp;
	p = pS->pTop;
	pTemp = pS->pTop->pNext;
	while (pTemp != NULL)
	{
		free(p);
		pS->pTop = pTemp;
		p = pS->pTop;
		pTemp = p->pNext;
	}
}

int main(void)
{
	int num, cnt;
	scanf("%d", &num);
	getchar();
	STACK S;
	init(&S);
	for (cnt = 0; cnt < num; ++cnt)
	{
		clear(&S);
		init(&S);
		int cnt;
		char bra[10000];
		gets(bra);
		int temp = 0;
		for (cnt = 0; cnt < strlen(bra); ++cnt)
		{
			if (bra[cnt] == '[' || bra[cnt] == '(')
				push(&S, bra[cnt]);
			else if (bra[cnt] == ')')
			{
				PNODE p;
				p = find(&S, '(');
				if (p == NULL)
				{
					printf("No\n");
					temp++;
					break;
				}
				else
					delete_half(p,&S);
			}
			else
			{
				PNODE p;
				p = find(&S, '[');
				if (p == NULL)
				{
					printf("No\n");
					temp++;
					break;
				}
				else
					delete_half(p,&S);
			}
		}
		if (temp != 0)
			continue;
		if (is_empty(&S))
			printf("Yes\n");
		else
			printf("No\n");
	}
}
