#include<iostream>  
#include<sstream>  
#include<string>  
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int n,q,*data,que;
	cin >> n >> q;
	data = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> data[i];
	}
	sort(data, data + n);
	for (int i = 0; i < q; i++)
	{
		cin >> que;
		cout << que<<" found at "<<(lower_bound(data, data + n, que)-data+1);
	}
	cout << "1111";
}