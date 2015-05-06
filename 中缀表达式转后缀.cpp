# include"stdafx.h"
# include<iostream>
# include<stack>
# include<string>

using namespace std;

int main(void)
{
	string data;
	stack<string> symbol;
	cin >> data;
	while (data != "#")
	{
		if (data == "+" || data == "-" || data == "*" || data == "/" || data == "(" || data == ")")
		{
			if (data == "+" || data == "-")
			{
				if (symbol.empty())
					symbol.push(data);
				else if (symbol.top() != "*")
				{
					if (symbol.top() != "/")
					{
						symbol.push(data);
					}
				}
				else
				{
					while (!symbol.empty())
					{
						if (symbol.top() != "(")
						{
							cout << symbol.top()<<" ";
							symbol.pop();
						}
						else
							break;
					}
					symbol.push(data);
				}
			}
			else if (data == "*" || data == "/")
				symbol.push(data);
			else if (data == "(")
				symbol.push(data);
			else if (data == ")")
			{
				while (symbol.top() != "(")
				{
					cout << symbol.top() << " ";
					symbol.pop();
				}
				symbol.pop();
			}
		}
		else
			cout << data << " ";
		cin.clear();
		cin >> data;
	}
	while (!symbol.empty())
	{
		cout << symbol.top() << " ";
		symbol.pop();
	}
	return 0;
}