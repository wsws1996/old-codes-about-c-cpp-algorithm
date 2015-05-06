//�ô���ľ��������������ر�֤�������ݵĹ淶��
#include"stdafx.h"
#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;

struct _hlNode
{
	char symbol;
	string str;
	_hlNode *next;
};

struct _hlTable
{
	_hlNode* first;
	_hlNode* last;
};

struct _htNode
{
	char symbol;
	_htNode * left, *right;
};

struct data
{
	_htNode* ht;
	int num;
	friend bool operator < (data a, data b)
	{
		return a.num > b.num;
	}
};

void traverseTree(_htNode* root, _hlTable *table, int k, char code[256])
{
	if ((root->left == NULL) && (root->right == NULL))
	{
		code[k] = '\0';
		_hlNode * aux = new _hlNode;
		aux->str = code;
		aux->symbol = root->symbol;
		aux->next = NULL;

		if (table->first == NULL)
		{
			table->first = aux;
			table->last = aux;
		}
		else
		{
			table->last->next = aux;
			table->last = aux;
		}
		return;
	}
	if (root->left != NULL)
	{
		code[k] = '0';
		traverseTree(root->left, table, k + 1, code);
	}
	if (root->right != NULL)
	{
		code[k] = '1';
		traverseTree(root->right, table, k + 1, code);
	}
}

int main(void)
{
	cout << "������Ҫ����Ϊ������ַ�����" << endl;
	char aim[26] = {'\0'};
	int i = 0;
	//�������ȶ���
	priority_queue<data> q;
	string str;
	cin >> str;
	char letter;
	data t;
	int count = 0;
	for (letter = 'a'; letter <= 'z'; ++letter)
	{
		for (int cnt = 0; cnt < str.size(); ++cnt)
		{
			if (str[cnt] == letter)
			{
				count++;
			}
		}
		if (count>0)
		{
			aim[i] = letter;
			i++;
			t.num = count;
			_htNode* ht = new _htNode;
			ht->symbol = letter;
			ht->left = NULL;
			ht->right = NULL;
			t.ht = ht;
			count = 0;
			q.push(t);
		}
	}
	//���ɹ�������
	while (q.size() != 1)
	{
		data m;
		m.num = q.top().num;
		_htNode* left = q.top().ht;
		q.pop();
		m.num += q.top().num;
		_htNode*right = q.top().ht;
		q.pop();
		_htNode* newNode = new _htNode;
		newNode->symbol = NULL;
		newNode->left = left;
		newNode->right = right;
		m.ht = newNode;
		q.push(m);
	}
	_htNode *root = (q.top().ht);
	//������������
	_hlTable*table = new _hlTable;
	table->first = NULL;
	table->last = NULL;
	char code[256];
	int k = 0;
	//������������
	traverseTree(root, table, k, code);
	//��ӡ����
	_hlNode * traversal;
	cout << "Encoding...." << endl << "Input string:" << endl << str << endl;
	cout << "Encoded string:" << endl;
	for (int i = 0; i<strlen(aim); i++)
	{
		traversal = table->first;
		while (traversal->symbol != aim[i])
			traversal = traversal->next;
		cout << aim[i] << ":";
		cout << traversal->str << endl;
	}
	//�������
	cout << "������Ҫ����Ϊ�ַ��ı��룺" << endl;
	_htNode *Traversal = root;
	string Code;
	cin >> Code;
	cout << "Decoding...." << endl << "Input code:" << endl << Code << endl;
	for (int j = 0;j<Code.length()+5; ++j)
	{
		if (Traversal->left == NULL&&Traversal->right == NULL)
		{
			cout << "the char is:" << Traversal->symbol << endl;
			Traversal = root;
			break;
		}
		if (Code[j] == '0')
			Traversal = Traversal->left;
		if (Code[j] == '1')
			Traversal = Traversal->right;
		if (Code[j] != '0'&&Code[j] != '1')
		{
			cout << "Error" << endl;
			break;
		}
	}
	return 0;
}