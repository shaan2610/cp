#include <bits/stdc++.h>
using namespace std;

#define f(i,n)          for(int i=0;i<n;i++)
#define fr(i,a,b)       for(int i=a;i<=b;i++)
#define P               cout<<
#define I               cin>>
#define pb              push_back
#define mp              make_pair
#define ppb             pop_back()
#define L               length()
#define endl            "\n"
#define vii             vector<pair<int,int> >
#define pii             pair<int,int>
#define vi              vector<int>
#define sd(arr,n)       sort(arr,arr+n,greater<int>())
#define si(arr,n)       sort(arr,arr+n)
#define Si(v)           sort(v.begin(),v.end())
#define Sd(v)           sort(v.begin(), v.end(), greater<int>())
#define s2i(v)          sort(v.begin(),v.end(),sbs)
#define s2d(v)          sort(v.begin(),v.end(),sbds)
#define desc            greater<int>
#define eif             else if 
#define int             long long int
#define F               first
#define S               second
#define fk              1000000007
#define bs(a,n,x)       binary_search(a,a+n,x)
#define in(n)           int n;I n
#define inp(a,n)        int a[n];f(xxx,n) I a[xxx]
#define mem(a)          memset(a, -1, sizeof(a))
#define all(v)          v.begin(), v.end()
#define ub(v,x)         std::upper_bound(all(v), x)     //first value greater than x
#define lb(v,x)         std::lower_bound(all(v), x)     //first value greater than or equal to x
#define boost           ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int invmod(int x, int n, int mod)
{
    if(n==0) return 1%mod;
    int half = invmod(x,n/2,mod);
    half = (half*half)%mod;
    if(n%2==1) half = (half*(x%mod))%mod;
    return half;
}
int bin(int a[],int l,int r,int x)
{
    if(l<=r)
    {
        int m=l+(r-l)/2;
        if(a[m]==x)
        return m;
        else if (a[m]>x)
        return bin(a,l,m-1,x);
        else
        return bin(a,m+1,r,x);
    }
    else
    return -1;
}
int power(int b,int e,int m)
{
    if(e==0)
    return 1;
    if(e%2)
    return b*power(b*b%m,(e-1)/2,m)%m;
    else
    return power(b*b%m,e/2,m);
}
int power(int b,int e)
{
    if(e==0)
    return 1;
    if(e%2)
    return b*power(b*b,(e-1)/2);
    else
    return power(b*b,e/2);
}
int ncr(int n, int r, int x) 
{ 
   if (r==0) 
   return 1; 
   int fac[n+1]; 
   fac[0] = 1; 
   for (int i=1 ; i<=n; i++) 
   fac[i] = fac[i-1]*i%x; 
   return (fac[n]* power(fac[r], x-2, x) % x * power(fac[n-r], x-2, x) % x) % x; 
}
int ncr(int n,int p)
{
    int r=min(p,n-p);
    int rf=1,ln=1;
    fr(i,1,r)
    rf=rf*i;
    f(i,r)
    ln=ln*(n-i);
    return ln/rf;
}
bool sbs(pii &a,pii &b) 
{ 
    return (a.S<b.S); 
}
bool sbds(pii &a,pii &b) 
{ 
    return (a.S>b.S); 
}
int chkprm(int n)
{
    int c=0;
    fr(i,2,sqrt(n))
    {
        if(n%i==0)
        {
            c++;
            break;
        }
    }
    if(c==0)
    return 1;
    else
    return 0;
}
void merge(int a[],int l,int m,int r)
{
	int x[m-l+1],y[r-m];
	f(i,m-l+1)
	x[i]=a[l+i];
	f(i,r-m)
	y[i]=a[m+i+1];
	int i=0,j=0,k=l;
	while(i<m-l+1 && j<r-m)
	{
		if(x[i]<=y[j])
		{
			a[k]=x[i];
			i++;
		}
		else
		{
			a[k]=y[j];
			j++;
		}
		k++;
	}
	while(i<m-l+1)
	{
		a[k]=x[i];
		i++;
		k++;
	}
	while(j<r-m)
	{
		a[k]=y[j];
		j++;
		k++;
	}
}
void msort(int a[],int l,int r)
{
	if(l<r)
	{
		int m=(l+r)/2;
		msort(a,l,m);
		msort(a,m+1,r);
		merge(a,l,m,r);
	}
}
void myth()
{
    in(n);
    inp(a,n);
    msort(a,0,n-1);
    f(i,n)
    P a[i]<<" ";
}
signed main()
{
    boost
    int test_case=1;
    //I test_case;
    while(test_case--)
    {
        myth();
        P endl;
    }
    return 0;
}