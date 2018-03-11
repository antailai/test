#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

struct var
{
	char name,zhuangtai;
	int value;
	var()
	{
		value = 0;
	}
};
vector<var> da;

int main()
{
	int n, t1, t2, t3, t4, t5, Q;
	cin >> n >> t1 >> t2 >> t3 >> t4 >> t5 >> Q;
	string s;
	while (cin >> s)
	{
		if (s.size() == 1)
		{
			var buf;
			buf.name = s[0];
			cin >> s;
			cin >> s;
			buf.value = s[0] - '0';
		}
		else if (s.compare("print"))
		{

		}
	}
	cout<<s.find_first_of('\n');
	cout << ' ';
}