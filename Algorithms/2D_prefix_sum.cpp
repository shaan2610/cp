// #include "bits/stdc++.h"
#include "iostream"
#include "vector"

using namespace std;

#define int long long
#define vi vector<int>
#define sz(v) (int)(v.size())
#define pb push_back
#define all(v) v.begin(),v.end()
#define S second
#define F first
#define pii pair<int,int>
#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int fk=1000000007;
const int fk1=998244353;
const int inf=1e18;
const int N=405;
const int N1=1005;

int power(int x,int n,int mod)
{
    if(not x)
        return 0;
    if(not n)
        return 1;
    if(n%2)
        return ((x%mod)*(power(x,n-1,mod))%mod)%mod;
    return power((x*x)%mod,n/2,mod)%mod;
}

int power(int x,int n)
{
    if(not x)
        return 0;
    if(not n)
        return 1;
    if(n%2)
        return (x*power(x,n-1));
    return power(x*x,n/2);
}

int top(int x,int y)
{
    if(x%y)
        return x/y + 1;
    else
        return x/y;
}

int pre[N][N],a[N][N],n,m;

void pre2d()
{
    pre[0][0]=a[0][0];
    for(int i=1;i<m;i++)
        pre[0][i]=pre[0][i-1]+a[0][i];
    for(int i=1;i<n;i++)
        pre[i][0]=pre[i-1][0]+a[i][0];
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
            pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+a[i][j];
    }
}

int pref(int i1,int j1,int i2,int j2)   // 0 based indexing
{
    if(not i1 and not j1)
        return pre[i2][j2];
    if(not i1)
        return (pre[i2][j2]-pre[i2][j1-1]);
    if(not j1)
        return (pre[i2][j2]-pre[i1-1][j2]);
    return (pre[i2][j2]-pre[i1-1][j2]-pre[i2][j1-1]+pre[i1-1][j1-1]);
}

void solve()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cin>>a[i][j];
    }
    pre2d();
    cout<<pref(1,1,4,3);
}

signed main()
{
    boost
    int t=1;
    cin>>t;
    while(t--)
    {
        solve();
        cout<<endl;
    }
    return 0;
}
