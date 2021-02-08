#include <bits/stdc++.h>
using namespace std;
struct deimp
{
	int sz,front,rear;
	int *a;
	deimp(int n)
	{
		sz=n;
		rear=-1;
		a=new int[n];
	}
	void pushf(int x)
	{
		if(rear==-1)
		{
			front=0;
			rear=0;
			a[front]=x;
		}
		else if(rear+1<sz)
		{
			for(int i=rear;i>=0;i--)
				a[i+1]=a[i];
			a[0]=x;
			rear++;
		}
		else
		{
			cout<<"Dequeue overflow";
			exit(1);
		}
	}
	void pushb(int x)
	{
		if(rear+1<sz)
		{
			rear++;
			a[rear]=x;
		}
		else
		{
			cout<<"Dequeue overflow";
			exit(1);
		}
	}
	void popf()
	{
		if(rear==-1)
		{
			cout<<"Dequeue underflow";
			exit(1);
		}
		else
		{
			for(int i=1;i<=rear;i++)
				a[i-1]=a[i];
			rear--;
		}
	}
	void popb()
	{
		if(rear==-1)
		{
			cout<<"Dequeue underflow";
			exit(1);
		}
		else
			rear--;
	}
};
int main()
{
	int n;
	cin>>n;
	deimp ob(n);
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
			for(int i=0;i<=ob.rear;i++)
				cout<<ob.a[i]<<" ";
			break;
		}
		else
		{
			switch(x)
			{
				case 1:
				int q;
				cin>>q;
				ob.pushb(q);
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