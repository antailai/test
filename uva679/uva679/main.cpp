#include<iostream>

using namespace std;

const int maxd = 20;
int tree[1 << maxd];

int main()
{
	int D, I,n,j;
	cin >> D >> I;
	n = (1 << D) - 1;	
	memset(tree,0,sizeof(tree));
	for (int i = 0; i < I; i++)
	{
		for (j = 1; j < n; )
		{
			if (tree[j] == 0)
			{
				tree[j] = 1;
				j = 2 * j;
				continue;
			}
			else
			{
				tree[j] = 0;
				j = 2 * j + 1;
				continue;
			}
		}
	}
	cout << j/2;
}