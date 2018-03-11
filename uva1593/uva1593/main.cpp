#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	string s,buf;
	vector<int> length;
	vector<string> data[250];
	int i = 0,col=0;
	while (getline(cin,s) && s[0]!='\0')
	{
		i = 0;
		stringstream ss(s);
		while (ss >> buf)
		{
			if((int)length.size()<= i)
			{ 
				length.push_back(buf.length());
			}
			else
			{
				length.at(i) = max(length.at(i), (int)buf.length());
			}
			data[col].push_back(buf);
			i++;
		}
		col++;
	}
	for (int i = 0; i < col; i++)
	{
		int j = 0;
		for (; j < (int)data[i].size() - 1; j++)
		{
			if (data[i][j].size() <= length[j])
			{
				cout << data[i][j];
				for (int p = 0; p < length[j] -(int)data[i][j].size() +1; p++)
				{
					cout << ' ';
				}
			}
		}
		cout << data[i][j] << endl;
	}
}