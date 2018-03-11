#include<iostream>
#include<sstream>
#include<string>
#include<queue>
/*
�����Ľ�����������256����������������ֻ��256����㣬���������������256�㣬�����256����㶼��ÿһ��һ����
���Բ���������������ָ����ʹ����
*/
using namespace std;


struct tnode
{
	int data;
	tnode* lchild;
	tnode* rchild;
};
int main()
{
	int flag=0;
	string s;
	tnode *root;
	root = new tnode();
	root->lchild = nullptr;
	root->rchild = nullptr;
	tnode *buf_t = root;
	while (getline(cin, s))
	{
		if (flag == 1)
			break;
		stringstream ss(s);
		string buf;
		while (ss >> buf)
		{
			if (!buf.compare("()"))
			{
				flag = 1;
				break;
			}
			buf_t = root;
			int data = 0;
			int pos = buf.find(',');
			for (int i = 1; i < pos; i++)
			{
				if (i == 1)
					data = buf[i]-'0';
				else
					data = data * 10 + (buf[i]-'0');
			}
			for (int j = pos; j < (int)buf.length(); j++)
			{
				if (buf[j] == 'L')
				{
					if (buf_t->lchild == nullptr)
						buf_t->lchild = new tnode();
					buf_t = buf_t->lchild;
				}
				else if (buf[j] == 'R')
				{
					if (buf_t->rchild == nullptr) 
						buf_t->rchild = new tnode();
					buf_t = buf_t->rchild;
				}
				else if(buf[j]==')')
				{
					buf_t->data = data;
				}
			}
		}
	}
	queue<tnode*> q;
	buf_t = root;
	q.push(buf_t);
	while (!q.empty())
	{
		tnode *buf_tt = q.front();
		q.pop();
		if (buf_tt->lchild != nullptr)
			q.push(buf_tt->lchild);
		if (buf_tt->rchild != nullptr)
			q.push(buf_tt->rchild);
		cout << buf_tt->data<<"  ";
	}
}