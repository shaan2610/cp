#include<bits/stdc++.h> 
#define pb push_back
using namespace std; 
struct infpos
{
	int sz,top;
	char *a;
	infpos(int n)
	{
		sz=n;
		top=-1;
		a=new char[n];
	}
	void push(char c)
	{
		if(top+1<sz)
		{
			top++;
			a[top]=c;
		}
		else
		{
			cout<<"Stack overflow";
			exit(1);
		}
	}
	void pop()
	{
		if(top==-1)
		{
			cout<<"Stack underflow";
			exit(1);
		}
		else
			top--;
	}
	/*char top1()
	{
		if(top==-1)
			cout<<"Stack is empty";
		else
			return a[top];
	}*/
};
int prec(char c)
{
	if(c=='^')
		return 3;
	else if(c=='/'||c=='*')
		return 2;
	else if(c=='+'||c=='-')
		return 1;
	else
		return -1;
}
int main()
{
	string s;
	cin>>s;
	int l=s.length();
	infpos ob(l+1);
	ob.push('@');
	string ans="";
	for(int i=0;i<l;i++)
	{
		if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))
			ans.pb(s[i]);
		else if(s[i]=='(')
			ob.push(s[i]);
		else if(s[i]==')')
		{
			while(ob.a[ob.top]!='@'&&ob.a[ob.top]!='(')
			{
				char c=ob.a[ob.top];
				ob.pop();
				ans.pb(c);
			}
			if(ob.a[ob.top]=='(')
				ob.pop();
		}
		else
		{
			while(ob.a[ob.top]!='@'&&prec(s[i])<=prec(ob.a[ob.top]))
			{
				char c=ob.a[ob.top];
				ans.pb(c);
				ob.pop();
			}
			ob.push(s[i]);
		}
	}
	while(ob.a[ob.top]!='@')
	{
		char c=ob.a[ob.top];
		ob.pop();
		ans.pb(c);
	}
	cout<<ans;
}