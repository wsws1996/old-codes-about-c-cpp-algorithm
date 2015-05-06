// 树的相关源码.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"stdio.h"
#include"malloc.h"
#include"windows.h"

typedef struct a
{
	int data;
	struct a * pLchild;
	struct a * pRchild;
}BTNode,*PBTNode;

PBTNode CreateBTree(void)
{
	PBTNode pA = (PBTNode)malloc(sizeof(BTNode));
	PBTNode pB = (PBTNode)malloc(sizeof(BTNode));
	PBTNode pC = (PBTNode)malloc(sizeof(BTNode));
	PBTNode pD = (PBTNode)malloc(sizeof(BTNode));
	PBTNode pE = (PBTNode)malloc(sizeof(BTNode));
	pA->data = 'A';
	pB->data = 'B';
	pC->data = 'C';
	pD->data = 'D';
	pE->data = 'E';
	pA->pLchild = pB;
	pA->pRchild = pC;
	pC->pLchild = pD;
	pD->pRchild = pE;
	pB->pLchild = pB->pRchild = NULL;
	pC->pRchild = NULL;
	pD->pLchild = NULL;
	pE->pLchild = pE->pRchild = NULL;
	return pA;
}

void PreTraverseBTree(PBTNode pT)
{
	printf("%c\n", pT->data);
	if (pT->pLchild!=NULL)
		PreTraverseBTree(pT->pLchild);
	if (pT->pRchild!=NULL)
		PreTraverseBTree(pT->pRchild);
}

void InTraverseBTree(PBTNode pT)
{
	if (pT->pLchild != NULL)
		InTraverseBTree(pT->pLchild);
	printf("%c\n", pT->data);
	if (pT->pRchild != NULL)
		InTraverseBTree(pT->pRchild);
}

void PostTraverseBTree(PBTNode pT)
{
	if (pT->pLchild != NULL)
		PostTraverseBTree(pT->pLchild);
	if (pT->pRchild != NULL)
		PostTraverseBTree(pT->pRchild);
	printf("%c\n", pT->data);
}

int _tmain(int argc, _TCHAR* argv[])
{
	PBTNode pT = CreateBTree();
	PreTraverseBTree(pT);
	InTraverseBTree(pT);
	PostTraverseBTree(pT);
	system("pause");
	return 0;
}

