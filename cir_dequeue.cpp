#include <bits/stdc++.h>
using namespace std;
struct cirdeqimp
{
	int rear,front,sz;
	int *a;
	cirdeqimp(int n)
	{
		sz=n;
		front=-1;
		rear=-1;
		a=new int[n];
	}
	void pushb(int x)
	{
		if(rear==-1&&front==-1)
		{
			rear=0;
			front=0;
			a[rear]=x;
		}
		else if((rear+1)%sz==front)
		{
			cout<<"Dequeue overflow";
			exit(1);
		}
		else
		{
			rear=(rear+1)%sz;
			a[rear]=x;
		}
	}
	void pushf(int x)
	{
		if(rear==-1&&front==-1)
		{
			rear=0;
			front=0;
			a[front]=x;
		}
		else if(front==0&&rear==sz-1)
		{
			cout<<"Dequeue overflow";
			exit(1);
		}
		else if(front==0&&rear!=sz-1)
		{
			front=sz-1;
			a[front]=x;
		}
		else if((front-1)%sz==rear)
		{
			cout<<"Dequeue overflow";
			exit(1);
		}
		else
		{
			front=(front-1)%sz;
			a[front]=x;
		}
	}
	void popb()
	{
		if(rear==-1)
		{
			cout<<"Dequeue undrflow";
			exit(1);
		}
		else if(rear==0)
		{
			rear=sz-1;
			if(rear==front)
			rear=-1;
		}
		else
		{
			rear=(rear-1)%sz;
			if(rear==front)
				rear=-1;
		}
	}
	void popf()
	{
		if(front==-1)
		{
			cout<<"Dequeue overflow";
			exit(1);
		}
		else
		{
			front=(front+1)%sz;
			if(front==rear)
				front=-1;
		}
	}
};
int main()
{
	int n;
	cin>>n;
	cirdeqimp ob(n);
	//1 -->Push back
	//2 -->Push front
	//3 -->Pop back
	//4 -->Pop front
	//0 -->Print and exi
	while(1)
	{
		int x;
		cin>>x;
		if(x==0)
		{
			if(ob.front<ob.rear)
			{
				for(int i=ob.front;i<=ob.rear;i++)
					cout<<ob.a[i]<<" ";
			}
			else
			{
				for(int i=ob.front;i<n;i++)
					cout<<ob.a[i]<<" ";
				for(int i=0;i<=ob.rear;i++)
					cout<<ob.a[i]<<" ";
			}
			break;
		}
		else
		{
			switch(x)
			{
				case 1:
				int z;
				cin>>z;
				ob.pushb(z);
				break;
				case 2:
				int y;
				cin>>y;
				ob.pushf(y);
				break;
				case 3:
				ob.popb();
				break;
				case 4:
				ob.popf();
				break;
			}
		}
	}
}