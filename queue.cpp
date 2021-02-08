#include <bits/stdc++.h>
using namespace std;
struct stackimp
{
	int *a;
	int top1,sz;
	stackimp(int n)
	{
		sz=n;
		a=new int[n];
		top1=-1;
	}
	void push1(int x)
	{
		if(top1+1<sz)
		{
			top1++;
			a[top1]=x;
		}
		else
		{
			cout<<"Queue Overflow";
			exit(1);
		}
	}
	void pop1()
	{
		if(top1>=0)
		{
			top1--;
			for(int i=0;i<sz-1;i++)
				a[i]=a[i+1];
		}
		else
		{
			cout<<"Queue underflow";
			exit(1);
		}
	}
};
int main()
{
	//cout<<"Enter the size of array"<<endl;
	int n;
	cin>>n;
	stackimp ob(n);
	//cout<<"1 --> Push in queue";
	//cout<<"2 --> Pop in queue";
	//cout<<"0 --> Print and Exit";
	while(1)
	{
		int q;
		cin>>q;
		if(q==0)
		{
			for(int i=0;i<=ob.top1;i++)
				cout<<ob.a[i]<<" ";
			cout<<endl;
			break;
		}
		else
		{
			switch(q)
			{
				case 1:
				int zz;
				cin>>zz;
				ob.push1(zz);
				break;
				case 2:
				ob.pop1();
				break;
			}
		}
	}
	return 0;
}