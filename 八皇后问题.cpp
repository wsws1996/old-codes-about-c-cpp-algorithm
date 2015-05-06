# include <iostream>
# include <algorithm>

using namespace std;

//参数row表示起始行，参数n表示列数
//参数(*chess)[8]表示指向棋盘每一行的指针，其中chess是指针的指针

int notDanger(int row, int j, int(*chess)[8])
{
	int i = 0;
	int temp = j;
	//判断列方向
	for (i = 0; i < 8; i++)
	{
		if (chess[i][j] == 1)
			return 0;
	}
	//判断行方向
	for (i = 0; i < 8; i++)
	{
		if (chess[row][i] == 1)
			return 0;
	}
	//判断左上方
	for (i = row; i >= 0 && j >= 0; i--, j--)
	{
		if (chess[i][j] == 1)
			return 0;
	}
	j = temp;
	//判断左下方
	for (i = row; i <8 && j >= 0; i++, j--)
	{
		if (chess[i][j] == 1)
			return 0;
	}
	j = temp;
	//判断右上方
	for (i = row; i >= 0 && j < 8; i--, j++)
	{
		if (chess[i][j] == 1)
			return 0;
	}
	j = temp;
	//判断右下方
	for (i = row; i < 8 && j < 8; i++, j++)
	{
		if (chess[i][j] == 1)
			return 0;
	}
	j = temp;
	return 1;
}
int cnt = 0;
void EightQueen(int row, int n, int(*chess)[8])
{
	int i, j;
	i = j = 0;
	int chess2[8][8];
	for (i = 0; i < 8; ++i)
	{
		for (j = 0; j < 8; ++j)
		{
			chess2[i][j] = chess[i][j];
		}
	}
	if (8 == row)
	{
		cout << "第" << cnt + 1 << "种：" << endl;
		for (int i = 0; i < 8; ++i)
		{
			for (j = 0; j < 8; j++)
			{
				cout << chess[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl << endl;
		cnt++;
	}
	else
	{
		//判断该位置是否危险
		for (j = 0; j < n; j++)
		{
			if (notDanger(row,j,chess))//判断是否危险
			{
				for (i = 0; i < 8; i++)
				{
					chess2[row][i] = 0;
				}
				chess2[row][j] = 1;

				EightQueen(row + 1, n, chess2);
			}
		}
	}
}
int main(void)
{
	int chess[8][8];
	int i = 0;
	int j = 0;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; ++j)
		{
			chess[i][j] = 0;
		}
	}
	EightQueen(0,8,chess);
	cout << "共计" << cnt << "种" << endl;
	return 0;
}
