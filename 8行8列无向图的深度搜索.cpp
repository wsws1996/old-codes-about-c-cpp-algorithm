//可用宏定义的方法扩展该代码为通用于任意行列的图的深搜
#include"stdafx.h"
#include<iostream>
using namespace std;

struct  node
{
	int connect = 0;
	bool flag = false;
};

node mat[8][8];

void dfs(node mat[8][8], int i, int j)
{
	int t = 0;
	for (; j < 8; ++j)
	{
		if (mat[i][j].flag == true)
		{
			if (mat[i][j].connect == false){}
			else
			{
				cout << j << endl;
				for (t = 0; t < 8; ++t)
				{
					mat[t][j].flag = false;
				}
				mat[i][j].flag = true;
				dfs(mat, j, 0);
			}
		}
	}
}

int main(void)
{
	int i = 0, j = 0;
	for (i = 0; i < 8; ++i)
	{
		for (j = 0; j < 8; ++j)
		{
			cin >> mat[i][j].connect;
			mat[i][j].flag = true;
		}
	}
	for (i = 0; i < 8; ++i)
	{
		mat[i][0].flag = false;
	}
	dfs(mat, 0, 0);
	return 0;
}