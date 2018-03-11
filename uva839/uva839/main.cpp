#include<iostream>

using namespace std;

bool balance(int &w);


int main()
{
	int t, w;
	cin >> t;
	while (t--)
	{
		bool b=balance(w);
		if (b)
			cout << "yes";
	}
}

bool balance(int &w)
{
	int w1, w2, d1, d2;
	bool b1=true, b2=true;
	cin >> w1 >> d1 >> w2 >> d2;
	if (!w1)
	{
		b1=balance(w1);
	}
	if (!w2)
	{
		b2=balance(w2);
	}
	w = w1 + w2;
	return b1&&b2 && (w1*d1) == (w2*d2);
}