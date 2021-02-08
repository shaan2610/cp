#include <bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node *nxt;
};
node *head=NULL;
void insert(int x,int pos)
{
	node *temp;
	temp=new node;
	temp->data=x;
	if(head==NULL)
	{
		temp->nxt=NULL;
		head=temp;
	}
	else
	{
		if(pos==1)
		{
			temp->nxt=head;
			head=temp;
		}
		else
		{
			node *itr=head;
			int c=0;
			while(c<pos-2)
			{
					c++;
				itr=itr->nxt;
			}
			temp->nxt=itr->nxt;
			itr->nxt=temp;
		}
	}
}
void del(int pos)
{
	node *itr=head;
	int c=0;
	while(c!=pos-2)
	{
		c++;
		itr=itr->nxt;
	}
	itr->nxt=(itr->nxt)->nxt;
}
void print()
{
	node *itr=head;
	while(itr!=NULL)
	{
		cout<<itr->data<<" ";
		itr=itr->nxt;
	}
}
int main()
{
	//1 --> insert
	//2 -->delete
	//3 -->print
	//0 -->exit
	while(1)
	{
		int x;
		cin>>x;
		if(x==0)
			break;
		else
		{
			switch(x)
			{
				case 1:
				int q,pos;
				cin>>pos>>q;
				insert(q,pos);
				break;
				case 2:
				int pos1;
				cin>>pos1;
				del(pos1);
				break;
				case 3:
				print();
				break;
			}
		}
	}
}