#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;

struct matrix
{
	int column, row;
	char name;
};
matrix find(char c,vector<matrix> m)
{
	for (int i = 0; i < (int)(m.size()); i++)
	{
		if (m.at(i).name == c)
		{
			return m.at(i);
		}
	}
}
int main()
{
	int n,sum=0,error=0;
	cin >> n;
	vector<matrix> data_m;
	stack<matrix> buf;
	for (int i = 0; i < n; i++)
	{
		matrix m;
		cin >> m.name >> m.column >> m.row;
		data_m.push_back(m);
	}
	string op;
	while (cin >> op)
	{
		sum = 0;
		for (int i = 0; i < (int)(op.size()); i++)
		{
			if (isalpha(op[i]))
			{
				buf.push(find(op[i], data_m));
			}
			else if (op[i] == ')')
			{
				matrix buf1, buf2, buf3;
				buf2 = buf.top();
				buf.pop();
				buf1 = buf.top();
				buf.pop();
				if (buf1.row != buf2.column)
				{
					error=1;
					break;
				}
				sum += buf1.column*buf1.row*buf2.row;
				buf3.name = 'b';
				buf3.column = buf1.column; buf3.row = buf2.row;
				buf.push(buf3);
			}
			else if (op[i] == '(')
			{
				continue;
			}
		}
		if (error == 0)
			cout << sum << endl;
		else
			cout << "error" << endl;
		
	}
}