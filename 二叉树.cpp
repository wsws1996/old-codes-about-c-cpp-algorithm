#include"stdafx.h"
#include <iostream>
using namespace std;

typedef char Type;

typedef struct BitNode
{
	Type data;
	struct BitNode* lchild, *rchild;
} BitNode, *BiTree;

//����һ�ö�������Լ���û�����ǰ�������ʽ
void CreateBiTree(BiTree* T)
{
	char c;
	cin >> c;
	if ('^' == c)
	{
		*T = NULL;
	}
	else
	{
		*T = new BitNode;
		(*T)->data = c;
		CreateBiTree(&(*T)->lchild);
		CreateBiTree(&(*T)->rchild);
	}
}

void visit(char c, int level)
{
	cout << c << "�ڵ�" << level << "��" << endl;
}

//ǰ���������������
void PreOrderTraverse(BiTree T, int level)
{
	if (T)
	{
		visit(T->data, level);
		PreOrderTraverse(T->lchild, level + 1);
		PreOrderTraverse(T->rchild, level + 1);
	}
}
int main()
{
	int level = 1;
	BiTree T = NULL;
	CreateBiTree(&T);
	PreOrderTraverse(T, level);
	return 0;
}
