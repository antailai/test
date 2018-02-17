#include<iostream>
#include<string>
#include<map>
#include<sstream>
#include<algorithm>

using namespace std;

map<string, int> number;

void print(string, int, char);

int main()
{
	int i = 0,length[180],row=0,j=0;
	memset(length,0,sizeof(length));
	string s[1000],x[180];
	while (getline(cin, s[i]))
	{
		stringstream ss(s[i++]);
		while (ss >> x[j])
		{
			length[j] = max((int)(x[j].length()),length[j]);
			j++;
		} 
		row = max(row,j);
		j = 0;
	}
	for (int i = 0; i < s->size(); i++)
	{
		stringstream sss(s[i]);
		for (int j = 0; j < row; j++)
		{
			sss >> x[j];
			print(x[j], length[j],' ');
		}
	}
}

void print(string s,int i,char c)
{
	if ((int)s.length() < i)
	{
		cout << s;
		for (int j = 0; j < i - s.length(); j++)
		{
			cout << c;
		}
	}
}