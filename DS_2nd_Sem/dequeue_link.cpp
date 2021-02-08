#include <bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node *nxt;
	node *prev;
};
node *head=NULL;
node *tail=NULL;
void pushb(int x)
{
	node *temp;
	temp=new node;
	temp->data=x;
	if(head==NULL)
	{
		temp->nxt=NULL;
		temp->prev=NULL;
		head=temp;
		tail=temp;
	}
	else
	{
		temp->nxt=NULL;
		temp->prev=tail;
		tail->nxt=temp;
		tail=temp;
	}
}
void pushf(int x)
{
	node *temp;
	temp=new node;
	temp->data=x;
	if(head==NULL)
	{
		temp->nxt=NULL;
		temp->prev=NULL;
		head=temp;
		tail=temp;
	}
	else
	{
		temp->nxt=head;
		temp->prev=NULL;
		head->prev=temp;
		head=temp;
	}
}
void popf()
{
	if(head==NULL)
	{
		cout<<"Dequeue underflow";
		exit(1);
	}
	else
	{
		head=head->nxt;
		head->prev=NULL;
	}
}
void popb()
{
	if(head==NULL)
	{
		cout<<"Dequeue underflow";
		exit(1);
	}
	else
	{
		tail=tail->prev;
		tail->nxt=NULL;
	}
}
void print()
{
	node *itr=head;
	while(itr!=tail)
	{
		cout<<itr->data<<" ";
		itr=itr->nxt;
	}
	cout<<tail->data;
}
int main()
{
	//1 --> push back
	//2 --> push front
	//3 --> pop back
	//4 --> pop front
	//5 --> print
	//0 --> exit
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
				int q;
				cin>>q;
				pushb(q);
				break;
				case 2:
				int qq;
				cin>>qq;
				pushf(qq);
				break;
				case 3:
				popb();
				break;
				case 4:
				popf();
				break;
				case 5:
				print();
				break;
			}

		}
	}
}