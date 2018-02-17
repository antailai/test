#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int n;
	vector<vector<int>> datacache;
	vector<int> ave;
	struct point
	{
		int x, y;
	};
	cin >> n;
	point *data;
	data = new point[n];
	for (int i = 0; i < n; i++)
	{
		cin >> data[i].x >> data[i].y;
		datacache.at(data[i].y - 1).push_back(data[i].x);
	}
	for (int i = 0; i < datacache.capacity(); i++)
	{
		ave
	}
}