#include <bits/stdc++.h>
using namespace std;
struct stackimp
{
	int *a;
	int size,top1,top2;
	stackimp(int n)
	{
		size=n;
		a=new int[n];
		top1=-1;
		top2=size;
	}
	void push1(int x)
	{
		if(top1+1<top2)
		{
			top1++;
			a[top1]=x;
		}
		else
		{
			cout<<"Stack overflow";
			exit(1);
		}
	}
	void push2(int x)
	{
		if(top2-1>top1)
		{
			top2--;
			a[top2]=x;
		}
		else
		{
			cout<<"Stack overflow";
			exit(1);
		}
	}
	void pop1()
	{
		if(top1>-1)
		{
			//return a[top1];
			top1--;
		}
		else
		{
			cout<<"Stack underflow";
			exit(1);
		}
	}
	void pop2()
	{
		if(top2<size)
		{
			//return a[top2];
			top2++;
		}
		else
		{
			cout<<"Stack underflow";
			exit(1);
		}
	}
};
int main()
{
	int xx;
	cin>>xx;
	stackimp hi(xx);
	//cout<<"1 --> Push in 1st";
	//cout<<"2 --> Pop in 1st";
	//cout<<"3 --> Push in 2nd";
	//cout<<"4 --> Pop in 2nd";
	for(int i=0;i<xx;i++)
	{
		int x;
		cin>>x;
		switch(x)
		{
			case 1:
			//cout<<"Enter the element";
			int y;
			cin>>y;
			hi.push1(y);
			break;
			case 2:
			hi.pop1();
			break;
			case 3:
			//cout<<"Enter the element";
			int yy;
			cin>>yy;
			hi.push2(yy);
			break;
			case 4:
			hi.pop2();
		}
	}
	for(int i=0;i<=hi.top1;i++)
		cout<<hi.a[i]<<" ";
	cout<<endl;
	for(int i=xx-1*a;;i>=hi.top2;i--)
		cout<<hi.a[i]<<" ";
}