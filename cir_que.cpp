#include <bits/stdc++.h>
using namespace std;
struct cirimp
{
	int rear,front,sz;
	int *a;
	cirimp(int n)
	{
		sz=n;
		rear=-1;
		front=-1;
		a=new int[n];
	}
	bool isemp()
	{
		if(front==-1&&rear==-1)
			return true;
		else
			return false;
	}
	void insert(int x)
	{
		if(rear==-1&&front==-1)
		{
			rear++;
			front++;
			a[rear]=x;
		}
		else if((rear+1)%sz==front)
		{
			cout<<"Queue overflow"<<endl;
			exit(1);
		}
		else
		{
			rear=(rear+1)%sz;
			a[rear]=x;
		}
	}
	void pop()
	{
		if(rear ==-1 && front ==-1)
			{
				cout<<"Queue underflow"<<endl;
				exit(1);
			}
		else if(rear==front)
		{
			rear=-1;
			front=-1;
		}
		else
		front=(front+1)%sz;
	}
};
int main()
{
	int n;
	cin>>n;
	cirimp ob(n);
	while(1)
	{
		int x;
		cin>>x;
		//1 --> Insert
		//2 --> Pop
		//0 --> Print and exit
		if(x==0)
		{
			if(ob.isemp())
			{
				cout<<"Empty Queue"<<endl;
				break;
			}
			else if(ob.front<=ob.rear)
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
				ob.insert(z);
				break;
				case 2:
				ob.pop();
				break;
			}
		}
	}
	return 0;
}