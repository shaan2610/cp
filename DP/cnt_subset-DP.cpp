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
#define Sd(v)           sort(v.begin(), v.end(),sdf)
#define s2i(v)          sort(v.begin(),v.end(),sbs)
#define s2d(v)          sort(v.begin(),v.end(),sbds)
#define desc            greater<int>
#define eif             else if 
#define int             long long int
#define F               first
#define S               second
#define fk              1000000007
#define fk1             998244353
#define sz              size()
#define mi              map<int,int>
#define bs(a,n,x)       binary_search(a,a+n,x)
#define MX(a,n)         *(max_element(a,a+n))
#define MN(a,n)         *(min_element(a,a+n))
#define in(n)           int n;I n
#define inp(a,n)        int a[n];f(xxx,n) I a[xxx]
#define mem(a)          memset(a, -1, sizeof(a))
#define all(v)          v.begin(), v.end()
#define ub(v,x)         std::upper_bound(all(v), x)     //first value greater than x
#define lb(v,x)         std::lower_bound(all(v), x)     //first value greater than or equal to x
#define boost           ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define elasped_time    1.0 * clock() / CLOCKS_PER_SEC 
int invmod(int x, int n, int mod){ if(n==0)  return 1%mod; int half = invmod(x,n/2,mod);half = (half*half)%mod; if(n%2==1)  half = (half*(x%mod))%mod; return half;}
int bin(int a[],int l,int r,int x){ if(l<=r){ int m=l+(r-l)/2; if(a[m]==x) return m; else if (a[m]>x) return bin(a,l,m-1,x); else return bin(a,m+1,r,x);} else return -1;}
int power(int b,int e,int m){ if(e==0) return 1; if(e%2) return b*power(b*b%m,(e-1)/2,m)%m; else return power(b*b%m,e/2,m);}
int power(int b,int e){ if(e==0) return 1; if(e%2) return b*power(b*b,(e-1)/2); else return power(b*b,e/2);}
int ncr(int n, int r, int x) { if (r==0) return 1; int fac[n+1]; fac[0] = 1; fr(i,1,n) fac[i] = fac[i-1]*i%x; return (fac[n]* power(fac[r], x-2, x) % x * power(fac[n-r], x-2, x) % x) % x; }
int ncr(int n,int p){ int r=min(p,n-p),rf=1,ln=1; fr(i,1,r) rf=rf*i; f(i,r) ln=ln*(n-i); return ln/rf;}
bool sbs(pii &a,pii &b){ return (a.S<b.S);}
bool sbds(pii &a,pii &b){ return (a.S>b.S);}
bool sdf(pii &a,pii &b){ return (a.first > b.first); }
int SUM(int a[],int n){ int sum=0; f(i,n) sum+=a[i]; return sum;}
int chkprm(int n){ fr(i,2,sqrt(n)) if(n%i==0) return 0; return 1;}
//vector<int> adj[200010];           //*****TREE MOVES*****
//int dep[200010],vis[200010],dad[200010],intime[200010],extime[200010],timer=0;
//void dfs_cal(int i){ dad[1]=1; intime[i]=timer; timer++; for(auto j: adj[i]){ if(j!=dad[i]){ dad[j]=i;dep[j]=dep[i]+1;dfs_cal(j);}} extime[i]=timer;  timer++;}
int dp[1001][1001],dp1[1001][1001];
int solve1(int a[],int n,int sum)
{
	f(i,n+1)
	dp1[i][0]=1;
	fr(i,1,sum)
	dp1[0][i]=0;
	fr(i,1,n)
	{
		fr(j,1,sum)
		{
			if(a[i-1]<=j)
				dp1[i][j]=dp1[i-1][j-a[i-1]]+dp1[i-1][j];
			else
				dp1[i][j]=dp1[i-1][j];
		}
	}
	return dp[n][sum];
}
int solve(int a[],int n,int sum)
{
	if(sum==0)
		return 1;
	if(n==0)
		return 0;
	if(dp[n][sum]!=-1)
		return dp[n][sum];
	if(a[n-1]<=sum)
		return dp[n][sum]=solve(a,n-1,sum-a[n-1])+solve(a,n-1,sum);
	else
		return dp[n][sum]=solve(a,n-1,sum);
}
void myth()
{
    in(n);
    in(sum);
    inp(a,n);
    mem(dp);
    mem(dp1);
    P solve(a,n,sum)<<endl;
    P solve1(a,n,sum);
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
    cerr<<endl<<"Time Elasped : "<<elasped_time<<endl;
    return 0;
}