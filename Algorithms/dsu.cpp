#include <bits/stdc++.h>

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
const int N=1000005;
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

int top(int x,int y)
{
    if(x%y)
        return x/y + 1;
    else
        return x/y;
}

struct dsu{
    vi mom,sze;
    dsu(int n)
    {
        mom.resize(n+5,0);
        sze.resize(n+5,0);
        for(int i=1;i<=n;i++)
            mk(i);
    }
    int find(int x)
    {
        if(mom[x]==x)
            return x;
        return mom[x]=find(mom[x]);
    }
    void mk(int x)
    {
        mom[x]=x;
        sze[x]=1;
    }
    void jnt(int x,int y)
    {
        int a=find(x),b=find(y);
        if(a!=b)
        {
            if(sze[a]>sze[b])
                swap(a,b);
            mom[b]=a;
            sze[a]+=sze[b];
        }
    }
};

void solve()
{
    
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
