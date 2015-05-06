#include<iostream>
#include<stdio.h>
#include<time.h>
using namespace std;
# define X 6
# define Y 6
int chess[X][Y];
//找到基于（X，Y）位置的下一个可走的位置
int nextxy(int *x, int *y, int count)
{
	switch (count)
	{
	case 0:
		if (*x + 2 <= X - 1 && *y - 1 >= 0 && chess[*x + 2][*y - 1] == 0)
		{
			*x += 2;
			*y -= 1;
			return 1;
		}
		break;
	case 1:
		if (*x + 2 <= X - 1 && *y + 1 <= Y - 1 && chess[*x + 2][*y + 1] == 0)
		{
			*x += 2;
			*y += 1;
			return 1;
		}
		break;
	case 2:
		if (*x - 2 >= 0 && *y + 1 <= Y - 1 && chess[*x - 2][*y + 1] == 0)
		{
			*x -= 2;
			*y += 1;
			return 1;
		}
		break;
	case 3:
		if (*x - 2 >= 0 && *y - 1 >= 0 && chess[*x - 2][*y - 1] == 0)
		{
			*x -= 2;
			*y -= 1;
			return 1;
		}
		break;
	case 4:
		if (*x - 1 >= 0 && *y + 2 <= Y - 1 && chess[*x - 1][*y + 2] == 0)
		{
			*x -= 1;
			*y += 2;
			return 1;
		}
		break;
	case 5:
		if (*x - 1 >= 0 && *y - 2 >= 0 && chess[*x - 1][*y - 2] == 0)
		{
			*x -= 1;
			*y -= 2;
			return 1;
		}
		break;
	case 6:
		if (*x + 1 <= X - 1 && *y - 2 >= 0 && chess[*x + 1][*y - 2] == 0)
		{
			*x += 1;
			*y -= 2;
			return 1;
		}
		break;
	case 7:
		if (*x + 1 <= X - 1 && *y + 2 <= Y - 1 && chess[*x + 1][*y + 2] == 0)
		{
			*x += 1;
			*y += 2;
			return 1;
		}
		break;
	default:
		break;
	}
	return 0;
}
void print()
{
	int i, j;
	for (i = 0; i < X; i++)
	{
		for (j = 0; j < Y; ++j)
		{
			printf("%2d\t", chess[i][j]);
		}
		cout << endl;
	}
	cout << endl;
}
//深度优先遍历棋盘，（X，Y）为位置坐标，tag是标记变量，每走一步，tag+1
int TravelChessBoard(int x, int y, int tag)
{
	//cout << tag << "层" << endl;
	int x1 = x, y1 = y, flag = 0, count = 0;
	chess[x][y] = tag;

	if (tag == X*Y)
	{
		print();
		//打印棋盘，退出程序
		return 1;
	}
	//找到马的下一个可走的坐标x1,y1,如果找到flag=1,否则为0
	flag = nextxy(&x1, &y1, count);
	while (0 == flag&&count < 7)
	{
		count++;
		flag = nextxy(&x1, &y1, count);
	}
		while (flag)
	{
		if (TravelChessBoard(x1, y1, tag+1))
		{
			return 1;
		}
		//找到马的下一个可走的坐标x1,y1,如果找到flag=1,否则为0
		x1 = x;
		y1 = y;
		count++;
		flag = nextxy(&x1, &y1, count);
		while (0 == flag&&count < 7)
		{
			count++;
			flag = nextxy(&x1, &y1, count);
		}
	}
	if (0 == flag)
	{
		chess[x][y] = 0;
	}
	return 0;
}

int main(void)
{
	int i, j;
	clock_t start, finish;
	start = clock();
	for (i = 0; i < X; i++)
	{
		for (j = 0; j < Y; ++j)
		{
			chess[i][j] = 0;
		}
	}
	if (!TravelChessBoard(2, 0, 1))
		cout << "fail" << endl;
	finish = clock();
	cout << "time:" << (finish - start) ;
	return 0;
}
