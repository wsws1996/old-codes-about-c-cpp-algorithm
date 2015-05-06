// ConsoleApplication2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
#include<stdlib.h>
#include <string>
#include <vector>

using namespace std;

void getNext(char* T, int *next)
{
	int j = 0;//前缀
	int i = 1;//后缀
	next[1] = 0;
	while (i < T[0])
	{
		if (j == 0 || T[i] == T[j])
		{
			i++;
			j++;
			if (T[i] != T[j])
				next[i] = j;
			else
				next[i] = next[j];
		}
		else
		{
			j = next[j];
		}
	}
}

//返回子串T在主串S第pos个字符之后的位置，若不存在则返回0
int Index_KMP(char* S, char * T, int pos)
{
	int i = pos;
	int j = 1;
	int next[255];
	getNext(T, next);
	while (i <= S[0] && j <= T[0])
	{
		if (0 == j || S[i] == T[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}
	if (j = T[0])
	{
		return i - T[0];
	}
	else
	{
		return 0;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	char T[255];
	char S[255];
	char t;
	scanf_s("%c", &t);
	unsigned int cnt = 0;
	for (cnt = 1; t != '\n'; ++cnt)
	{
		S[cnt] = t;
		scanf_s("%c", &t);
	}
	S[0] = cnt - 1;
	cin >> t;
	for (cnt = 1; t != '\n'; ++cnt)
	{
		T[cnt] = t;
		scanf_s("%c", &t);
	}
	T[0] = cnt - 1;
	int beg = Index_KMP(S, T, 1);
	int end = beg + T[0];
	cout << "从" << beg << "开始匹配成功" << endl;
	cout << "至" << end << "结束" << endl;
	return 0;
}

