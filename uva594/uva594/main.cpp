#include<iostream>

using namespace std;

int isducci(int *, int);

int main()
{
	int n, *data;
	cin >> n;
	data = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> data[i];
	}
	cout << isducci(data, n);
}


int isducci(int *data, int n)
{
	int *cache, flag_1 = 1, flag_2 = 1;
	cache = new int[n];
	for (int j = 0; j < 1000; j++)
	{
		for (int i = 0; i < n; i++)
		{
			cache[i] = abs(data[i%n] - data[(i + 1) % n]);
			if (cache[i] != 0)
			{
				flag_1 = 0;
			}
			if (cache[i] != data[i])
			{
				flag_2 = 0;
			}
		}
		if (flag_1 || flag_2)
		{
			break;
		}
		else
		{
			flag_1 = 1;
			flag_2 = 1;
		}
		for (int q = 0; q < n; q++)
		{
			data[q] = cache[q];
		}
	}
	if (flag_1 == 1)
	{
		return 1;
	}
	else if (flag_2 == 1)
	{
		return 2;
	}
	return 0;
}
