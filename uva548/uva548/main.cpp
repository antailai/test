#include<iostream>
#include<string>
#include<sstream>
#include<queue>
#include<vector>

using namespace std;
/*struct node
{
	int data;
	node *lchild, *rchild;
};
*/
int data_1[100000], data_2[10000];		
int real_pos[10000];
int build(int low_1, int high_1, int low_2, int high_2, int time);
int main()
{
	string s_1, s_2;
	while (getline(cin, s_1) && getline(cin, s_2))
	{
		stringstream ss_1(s_1);
		stringstream ss_2(s_2);
		string buf_1, buf_2;
		int i = 0;
		while (ss_1 >> buf_1&&ss_2 >> buf_2)
		{
			data_1[i]=buf_1[0] - '0';
			data_2[i++]=buf_2[0] - '0';
		}
		build(0, i, 0, i, 1);
	}
}

int build(int low_1, int high_1, int low_2, int high_2, int time)
{
	int root = high_2-1;
	int p = low_1;
	while (data_1[p++] != data_2[root])
	{
	}
	if (time == 1)
	{
		real_pos[time] = low_1;
	}
	int cnt = p - low_1;
	real_pos[time * 2] = build(low_1, p-1, low_2, low_2+cnt-1, time+1);
	real_pos[time * 2 + 1] = build(p+1, high_1, low_2+cnt, high_2 - 1, time++);
	return root;
}