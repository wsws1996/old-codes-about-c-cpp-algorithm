# include <iostream>
# include <string>
# include<stack>
# include<stdlib.h>
# include<cmath>
# include<ctype.h>

using namespace std;

int main(void)
{
	string shu;
	stack<string> symbol;
	stack<string>temp;
	stack<string>str;
	str.push("#");
	cin >> shu;
	while (shu != "#")
	{
		if (shu == "+" || shu == "-" || shu == "*" || shu == "/" || shu == "(" || shu == ")")
		{
			if (shu == "+" || shu == "-")
			{
				if (symbol.empty())
					symbol.push(shu);
				else if (symbol.top() != "*")
				{
					if (symbol.top() != "/")
					{
						symbol.push(shu);
					}
				}
				else
				{
					while (!symbol.empty())
					{
						if (symbol.top() != "(")
						{
							//cout << symbol.top()<<" ";
							temp.push(symbol.top());
							symbol.pop();
						}
						else
							break;
					}
					symbol.push(shu);
				}
			}
			else if (shu == "*" || shu == "/")
				symbol.push(shu);
			else if (shu == "(")
				symbol.push(shu);
			else if (shu == ")")
			{
				while (symbol.top() != "(")
				{
					//cout << symbol.top() << " ";
					temp.push(symbol.top());
					symbol.pop();
				}
				symbol.pop();
			}
		}
		else
			//cout << shu << " ";
			temp.push(shu);
		cin.clear();
		cin >> shu;
	}
	while (!symbol.empty())
	{
		//cout << symbol.top() << " ";
		temp.push(symbol.top());
		symbol.pop();
	}
	while (!temp.empty())
	{
		str.push(temp.top());
		temp.pop();
	}
	//while (!str.empty())
	//{
	//	cout << str.top() << " ";
	//	str.pop();
	//}
	stack<double> s;
	int n = 0;
	string data;
	double d, e;
	data = str.top();
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
		str.pop();
		data=str.top();
	}
	cout << s.top() << endl;
	return 0;
}
