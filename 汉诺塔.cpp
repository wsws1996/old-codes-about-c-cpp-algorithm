# include "stdafx.h"
# include <iostream>

using namespace std;

int total = 0;

void move(int num, char A, char B, char C)
{
	if (3 == num)
	{
		cout << "��" << total+1 << "�Σ�" << "��1�����ӣ���A�����ƶ���C����" << endl;
		total++;
		cout << "��" << total + 1 << "�Σ�" << "��2�����ӣ���A�����ƶ���B����" << endl;
		total++;
		cout << "��" << total + 1 << "�Σ�" << "��1�����ӣ���C�����ƶ���B����" << endl;
		total++;
		cout << "��" << total + 1 << "�Σ�" << "��3�����ӣ���A�����ƶ���C����" << endl;
		total++;
		cout << "��" << total + 1 << "�Σ�" << "��1�����ӣ���B�����ƶ���A����" << endl;
		total++;
		cout << "��" << total + 1 << "�Σ�" << "��2�����ӣ���B�����ƶ���C����" << endl;
		total++;
		cout << "��" << total + 1 << "�Σ�" << "��1�����ӣ���A�����ƶ���C����" << endl;
		total++;
	}
	else if (num < 3)
		cout << "���ܼ���" << endl;
	else
	{
		move(num - 1, A, C, B);
		cout << "��" << total + 1 << "�Σ�" << "��" << num << "�����ӣ���" << A << "�����ƶ���" << C << "����" << endl;
		total++;
		move(num - 1, B, A, C);
	}
}

int  main(void)
{
	int num;
	cin >> num;
	move(num, 'A', 'B', 'C');
	cout << "�����ƶ���" << total << "��" << endl;
	return 0;
}