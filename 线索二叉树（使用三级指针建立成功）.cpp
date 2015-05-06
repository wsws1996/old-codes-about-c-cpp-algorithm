#include"stdafx.h"
#include <iostream>
using namespace std;

typedef char Type;

typedef struct BiThrNode
{
	Type data;
	bool ltag = true, rtag = true;//线索存储标志位,true为指向其子元素，false为指向其前驱或后继
	struct BiThrNode* lchild, *rchild;
} BiThrNode, *BiThrTree;
//全局变量，指向刚访问过的结点
BiThrTree pre;

//创建一棵二叉树，约定用户遵照前序遍历方式
void CreateBiThrTree(BiThrTree* T)
{
	char c;
	cin >> c;
	if ('^' == c)
	{
		*T = NULL;
	}
	else
	{
		*T = new BiThrNode;
		(*T)->data = c;
		(*T)->ltag = true;
		(*T)->rtag = true;

		CreateBiThrTree(&(*T)->lchild);
		CreateBiThrTree(&(*T)->rchild);
	}
}

//中序遍历将树线索化
void InThreading(BiThrTree T)
{
	if (T)
	{
		InThreading(T->lchild);//递归至左叶子
		//结点处理
		if (!T->lchild)
		{
			T->ltag = false;
			T->lchild = pre;
		}
		if (!pre->rchild)
		{
			pre->rtag = false;
			pre->rchild = T;
		}
		pre = T;
		InThreading(T->rchild);//递归至右叶子
	}
}


//pre设置
void InOrderThreading(BiThrTree*p, BiThrTree T)
{
	*p = new BiThrNode;
	(*p)->ltag = true;
	(*p)->rtag = false;
	(*p)->rchild = *p;
	if (!T)
	{
		(*p)->lchild = *p;
	}
	else
	{
		(*p)->lchild = T;
		pre = *p;

		InThreading(T);
		pre->rchild = *p;
		pre->rtag = false;
		(*p)->rchild = pre;
	}
}

void visit(char c)
{
	cout << c << endl;
}
//中序遍历二叉树，非递归，执行思路等同于人为中序遍历的思路
void InOrderTraverse(BiThrTree T)
{
	BiThrTree p;
	p = T->lchild;
	while (p != T)
	{
		while (p->ltag == true)
		{
			p = p->lchild;
		}
		visit(p->data);
		while (p->rtag == false && p->rchild != T)
		{
			p = p->rchild;
			visit(p->data);
		}
		p = p->rchild;
	}
}

int main()
{
	BiThrTree P, T = NULL;
	CreateBiThrTree(&T);
	InOrderThreading(&P, T);
	cout << "中序遍历输出结果为：" << endl;
	InOrderTraverse(P);//传入的为头指针
	return 0;
}
//线索二叉树线索的意义在于在没有右结点的情况下指引遍历指针找到它下一个需要遍历的结点