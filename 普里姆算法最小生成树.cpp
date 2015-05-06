#include"stdafx.h"
#include<iostream>
using namespace std;
#define X 6
#define Y 6
int arc[X][Y];

void prim(int arc[X][Y])
{
	int min, i, j, k;
	int adjvex[65535];//前驱节点数组
	int lowcost[65535];//权值数组
	lowcost[0] = 0;
	adjvex[0] = 0;
	for (i = 1; i < X; ++i)
	{
		lowcost[i] = arc[0][i];
		adjvex[i] = 0;
	}
	for (i = 1; i < X; i++)
	{
		min = 65535;
		j = 1;
		k = 0;
		while (j < X)
		{
			if (lowcost[j] != 0 && lowcost[j] < min)
			{
				min = lowcost[j];
				k = j;
			}
			j++;
		}
		cout << adjvex[k] << " " << k << endl;
		lowcost[k] = 0;
		for (j = 1; j < X; ++j)
		{
			if (lowcost[j] != 0 && arc[k][j] < lowcost[j])
			{
				lowcost[j] = arc[k][j];
				adjvex[j] = k;
			}
		}
	}
}
int main(void)
{
	int i = 0, j = 0;
	for (i = 0; i < X; ++i)
	{
		for (j = 0; j < Y; ++j)
		{
			cin >> arc[i][j];
		}
	}
	prim(arc);
	return 0;
}