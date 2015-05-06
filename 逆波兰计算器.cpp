# include "stdafx.h"
# include <iostream>
# include <string>
# include<stack>
# include<stdlib.h>
# include<cmath>
# include<ctype.h>

using namespace std;

int main(void)
{
	stack<double> s;
	int n = 0;
	string data;
	double d, e;
	cin >> data;
	while (data!="#")
	{
		if (data == "+" || data == "-" || data == "*" || data == "/")
		{
			d = s.top();
			s.pop();
			e = s.top();
			s.pop();
			if (data == "+")
				s.push(d + e);
			else if (data == "-")
				s.push(e - d);
			else if (data == "*")
				s.push(e * (d*1.0));
			else if (data == "/")
				s.push(e / (d*1.0));
		}
		else
			s.push(atoi(data.c_str()));
		cout << "size:" << s.size() << endl;
		/*if (s.size() == 1 && n == 0)
			n++;
		else if (s.size() == 1 && n == 1)
		{
			break;
		}*/
		cin.clear();
		cin >> data;
	}
	cout << s.top() << endl;
	return 0;
}