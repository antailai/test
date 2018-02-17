#include<iostream>
#include<queue>
using namespace std;

int main()
{
	int n;
	char c;
	queue<char> data;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> c;
		data.push(c);
	}
	while ((int)data.size() != 1)
	{
		cout << data.front() << endl;
		data.pop();
		char cache;
		cache = data.front();
		data.pop();
		data.push(cache);
	}
	cout << data.front();
}