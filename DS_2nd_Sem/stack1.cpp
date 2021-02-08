#include <bits/stdc++.h>
using namespace std;
struct stackimp
{
	int *a;
	int top1,top2,sz;
	stackimp(int n)
	{
		sz=n;
		a=new int[n];
		top1=-1;
		top2=n;
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
			cout<<"Stack Overflow";
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
			cout<<"Stack Overflow";
			exit(1);
		}
	}
	void pop1()
	{
		if(top1>=0)
			top1--;
		else
		{
			cout<<"Stack underflow";
			exit(1);
		}
	}
	void pop2()
	{
		if(top2<sz)
			top2++;
		else
		{
			cout<<"Stack underflow";
			exit(1);
		}
	}
	bool isemp1()
	{
		if(top1==-1)
			return true;
		else
			return false;
	}
	bool isemp2()
	{
		if(top2==sz)
			return true;
		else
			return false;
	}
};
int main()
{
	//cout<<"Enter the size of array"<<endl;
	int n;
	cin>>n;
	stackimp ob(n);
	//cout<<"1 --> Push in 1st";
	//cout<<"2 --> Pop in 1st";
	//cout<<"3 --> Push in 2nd";
	//cout<<"4 --> Pop in 2nd";
	//cout<<"5 --> Is empty stack1";
	//cout<<"6 --> Is empty stack2";
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
			for(int i=n-1;i>=ob.top2;i--)
				cout<<ob.a[i]<<" ";
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
				case 3:
				int z;
				cin>>z;
				ob.push2(z);
				break;
				case 4:
				ob.pop2();
				break;
				case 5:
				if(ob.isemp1())
					cout<<"Empty"<<endl;
				else
					cout<<"Not Empty"<<endl;
				break;
				case 6:
				if(ob.isemp2())
					cout<<"Empty"<<endl;
				else
					cout<<"Not Empty"<<endl;
				break;
			}
		}
	}
	return 0;
}