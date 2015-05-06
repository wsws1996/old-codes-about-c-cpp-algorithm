# include <iostream>
# include <algorithm>

using namespace std;

//����row��ʾ��ʼ�У�����n��ʾ����
//����(*chess)[8]��ʾָ������ÿһ�е�ָ�룬����chess��ָ���ָ��

int notDanger(int row, int j, int(*chess)[8])
{
	int i = 0;
	int temp = j;
	//�ж��з���
	for (i = 0; i < 8; i++)
	{
		if (chess[i][j] == 1)
			return 0;
	}
	//�ж��з���
	for (i = 0; i < 8; i++)
	{
		if (chess[row][i] == 1)
			return 0;
	}
	//�ж����Ϸ�
	for (i = row; i >= 0 && j >= 0; i--, j--)
	{
		if (chess[i][j] == 1)
			return 0;
	}
	j = temp;
	//�ж����·�
	for (i = row; i <8 && j >= 0; i++, j--)
	{
		if (chess[i][j] == 1)
			return 0;
	}
	j = temp;
	//�ж����Ϸ�
	for (i = row; i >= 0 && j < 8; i--, j++)
	{
		if (chess[i][j] == 1)
			return 0;
	}
	j = temp;
	//�ж����·�
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
		cout << "��" << cnt + 1 << "�֣�" << endl;
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
		//�жϸ�λ���Ƿ�Σ��
		for (j = 0; j < n; j++)
		{
			if (notDanger(row,j,chess))//�ж��Ƿ�Σ��
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
	cout << "����" << cnt << "��" << endl;
	return 0;
}
