#include<iostream>

using namespace std;

const int maxd = 10;
int tree[ 1 << maxd];

int main()
{
	int D, I, n;
	cin >> D >> I;
	int k = 1;
	for (int i = 0; i < D - 1; i++)
	{
		if (I % 2) { k = k * 2; I = (I + 1) / 2; }
		else { k = k * 2 + 1; I /= 2; }
	}
	cout << k;
}