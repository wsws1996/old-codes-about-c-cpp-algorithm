// 队列相关源码.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
#include "malloc.h"
#include "windows.h"

typedef struct Q
{
	int * pBase;
	int front;
	int rear;
}QUEUE;

bool full_queue(QUEUE *pQ)
{
	if ((pQ->rear + 1) % 6 == pQ->front)
		return true;
	return false;
}

bool empty_queue(QUEUE *pQ)
{
	if (pQ->front == pQ->rear)
		return true;
	return false;
}

void init(QUEUE* pQ,int len)
{
	pQ->pBase = (int *)malloc(sizeof(int)*len);
	pQ->front = pQ->rear = 0;
}

bool en_queue(QUEUE *pQ, int val)
{
	if (full_queue(pQ))
		return false;
	else
	{
		pQ->pBase[pQ->rear] = val;
		pQ->rear = (pQ->rear + 1) % 6;
		return true;
	}
}

void traverse_quene(QUEUE * pQ)
{
	int cnt = pQ->front;

	while (cnt != pQ->rear)
	{
		printf("%d\n", pQ->pBase[cnt]);
		cnt = (cnt + 1) % 6;
	}
}

bool out_queue(QUEUE *pQ, int *pVal)
{
	if (empty_queue(pQ))
		return false;
	else
	{
		*pVal = pQ->pBase[pQ->front];
		pQ->front = (pQ->front + 1)%6;
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	QUEUE Q;
	int val;
	int *pVal;
	pVal = &val;
	init(&Q,6);
	en_queue(&Q, 1);
	en_queue(&Q, 2);
	en_queue(&Q, 3);
	en_queue(&Q, 4);
	en_queue(&Q, 5);
	en_queue(&Q, 6);
	printf("队列元素为：\n");
	traverse_quene(&Q);
	out_queue(&Q, pVal);
	printf("出队元素为：%d\n", val);
	printf("队列元素为：\n");
	traverse_quene(&Q);
	system("pause");
	return 0;
}

