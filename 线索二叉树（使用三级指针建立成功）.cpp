#include"stdafx.h"
#include <iostream>
using namespace std;

typedef char Type;

typedef struct BiThrNode
{
	Type data;
	bool ltag = true, rtag = true;//�����洢��־λ,trueΪָ������Ԫ�أ�falseΪָ����ǰ������
	struct BiThrNode* lchild, *rchild;
} BiThrNode, *BiThrTree;
//ȫ�ֱ�����ָ��շ��ʹ��Ľ��
BiThrTree pre;

//����һ�ö�������Լ���û�����ǰ�������ʽ
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

//�����������������
void InThreading(BiThrTree T)
{
	if (T)
	{
		InThreading(T->lchild);//�ݹ�����Ҷ��
		//��㴦��
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
		InThreading(T->rchild);//�ݹ�����Ҷ��
	}
}


//pre����
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
//����������������ǵݹ飬ִ��˼·��ͬ����Ϊ���������˼·
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
	cout << "�������������Ϊ��" << endl;
	InOrderTraverse(P);//�����Ϊͷָ��
	return 0;
}
//��������������������������û���ҽ��������ָ������ָ���ҵ�����һ����Ҫ�����Ľ��