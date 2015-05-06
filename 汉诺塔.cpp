# include "stdafx.h"
# include <iostream>

using namespace std;

int total = 0;

void move(int num, char A, char B, char C)
{
	if (3 == num)
	{
		cout << "第" << total+1 << "次：" << "第1号盘子，从A柱子移动到C柱子" << endl;
		total++;
		cout << "第" << total + 1 << "次：" << "第2号盘子，从A柱子移动到B柱子" << endl;
		total++;
		cout << "第" << total + 1 << "次：" << "第1号盘子，从C柱子移动到B柱子" << endl;
		total++;
		cout << "第" << total + 1 << "次：" << "第3号盘子，从A柱子移动到C柱子" << endl;
		total++;
		cout << "第" << total + 1 << "次：" << "第1号盘子，从B柱子移动到A柱子" << endl;
		total++;
		cout << "第" << total + 1 << "次：" << "第2号盘子，从B柱子移动到C柱子" << endl;
		total++;
		cout << "第" << total + 1 << "次：" << "第1号盘子，从A柱子移动到C柱子" << endl;
		total++;
	}
	else if (num < 3)
		cout << "不能计算" << endl;
	else
	{
		move(num - 1, A, C, B);
		cout << "第" << total + 1 << "次：" << "第" << num << "号盘子，从" << A << "柱子移动到" << C << "柱子" << endl;
		total++;
		move(num - 1, B, A, C);
	}
}

int  main(void)
{
	int num;
	cin >> num;
	move(num, 'A', 'B', 'C');
	cout << "共计移动了" << total << "次" << endl;
	return 0;
}