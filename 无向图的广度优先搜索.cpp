#include"stdafx.h"
#include<iostream>
#include<queue>
using namespace std;
struct  node
{
	bool connect = false;
	bool visited = false;
};
#define X 9
#define Y 9
int visited[X] = { 0 };
int rex[X][Y];
void BFS(int rex[X][Y],int visited[X])
{
	int i, j;
	queue<int> q;
	for (i = 0; i < X; ++i)
	{
		if (visited[i] == 0)
		{
			cout << (char)(i+'A') << endl;
			visited[i] = 1;
			q.push(i);
			while (!q.empty())
			{
				i = q.front();
				q.pop();
				for (j = 0; j < X; ++j)
				{
					if (rex[i][j] == 1 && !visited[j])
					{
						cout << (char)(j+'A') << endl;
						visited[j] = 1;
						q.push(j);
					}
				}
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
			cin >> rex[i][j];
		}
	}
	BFS(rex, visited);
	return 0;
}
/*------------------------------------------------------------
 ‰»Î
0	1	0	0	0	1	0	0	0
1	0	1	0	0	0	1	0	1
0	1	0	1	0	0	0	0	1
0	0	1	0	1	0	1	1	1
0	0	0	1	0	1	0	1	0
1	0	0	0	1	0	1	0	0
0	1	0	1	0	1	0	1	0
0	0	0	1	1	0	1	0	0
0	1	1	1	0	0	0	0	0
 ‰≥ˆ
A
B
F
C
G
I
E
D
H
-----------------------------------------------------------------*/