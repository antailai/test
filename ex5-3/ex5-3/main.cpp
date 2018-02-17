#include<iostream>
#include<string>
#include<sstream>
#include<set>
using namespace std;

/*

因为有标点符号  所以要先处理data 把标点符号变成空格 然后用sstream分开
*/
int main()
{
	string data, s;
	cin >> data;
	for (int i = 0; i < data.size(); i++)
	{
		if (isalpha(data[i]))
			data[i] = tolower(data[i]);
		else
			data[i] = ' ';
	}
	stringstream ss(data);
	set<string> datacache;
	while (ss >> s)
	{
		datacache.insert(s);
	}
	for (set<string>::iterator it = datacache.begin(); it != datacache.end(); ++it)
	{
		cout << *it << endl;
	}
	return 0;
}
