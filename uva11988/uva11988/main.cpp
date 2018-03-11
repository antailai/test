#include<iostream>
#include<string>
#include<sstream>
using namespace std;

struct point
{
	char data;
	point *pre;
	point  *next;
};
int main()
{
	point * head;
	head = new point;
	head->pre = nullptr;
	string s;
	while (getline(cin, s))
	{
		point **buf;
		buf = new point*[s.size()];
		for (int i = 0; i < s.size(); i++)
		{
			if (i == 0 || s[i] == '[')
			{
				if (s[i] != '[')
				{
					buf[i] = new point;
					buf[i]->data = s[i];
					head->next = buf[i];
					buf[i]->pre = head;
					buf[i]->next = nullptr;
				}
				else
				{
					buf[i] = new point;
					buf[i]->data = '\0';
					buf[i]->next = head->next;
					head->next->pre = buf[i];
					head->next = buf[i];
					buf[i]->pre = head;
				}
			}
			else
			{
				if (s[i] == ']')
				{
					point *buf_1 = head,*buf_2=nullptr;
					buf_1 = buf_1->next;
					while (buf_1->next != nullptr)
					{
						buf_2 = buf_1;
						buf_1 = buf_1->next;
					}
					buf_1 = new point;
					buf_1->data = '\0';
					buf_1->pre = buf_2;
					buf_1->next = nullptr;
				}
				else
				{
					buf[i] = new point;
					buf[i]->data = s[i];
					buf[i]->pre = buf[i - 1];
					buf[i - 1]->next = buf[i];
				}
			}
		}
		point *buf_s = head;
		for (int i = 0; i < s.size(); i++)
		{
			buf_s = buf_s->next;
			if ((buf_s->data) != '\0')
			{
				cout << buf_s->data;
			}
		}
	}
}
