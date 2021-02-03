#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
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
#define all(v)          v.begin(), v.end()
#define vii             vector<pair<int,int> >
#define pii             pair<int,int>
#define vi              vector<int>
#define desc            greater<int>()
#define sd(arr,n)       sort(arr,arr+n,desc)
#define si(arr,n)       sort(arr,arr+n)
#define Si(v)           sort(v.begin(),v.end())
#define Sd(v)           sort(v.begin(), v.end(),desc)
#define s2i(v)          sort(v.begin(),v.end(),sbs)
#define s2d(v)          sort(v.begin(),v.end(),sbds)
#define eif             else if 
#define int             long long int
#define F               first
#define S               second
#define fk              1000000007
#define fk1             998244353
#define pie             3.14159265358979323846
#define inf             1e18
#define dec(x)          fixed<<setprecision(x)
#define sz(x)           (x.empty() ? 0 : x.size())
#define mi              map<int,int>
#define bs(a,x)       	binary_search(all(a),x)
#define MX(a)         	*(max_element(all(a)))
#define MN(a)         	*(min_element(all(a)))
#define in(n)           int n;I n
#define inp(a,n)        vi a(n);f(xxx,n) I a[xxx]
#define mem(a)          memset(a, -1, sizeof(a))
#define ub(v,x)         std::upper_bound(all(v), x)     //first value greater than x
#define lb(v,x)         std::lower_bound(all(v), x)     //first value greater than or equal to x
#define boost           ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define TLE             cerr<<endl<<"Time Elasped : "<<1.0 * clock() / CLOCKS_PER_SEC<<endl;
#define N 100005
vi adj[N],dad(N),dep(N),pwr2(15),logg2(N);
int dp[N][15],dp1[N][15];
void calc()
{
    pwr2[0]=1;
    for(int i=1;i<15;i++)
        pwr2[i]=pwr2[i-1]*2;
    for(int i=2;i<N;i++)
        logg2[i]=1+logg2[i/2];
        
}
int kth(int x,int k)
{
    int z=logg2[k];
    int ans=x;
    while(k)
    {
        ans=dp[ans][z];
        k-=pwr2[z];
    }
    return ans;
}
void dfs1(int x,int xd)
{
    for(auto i:adj[x])
    {
        if(i!=xd)
        {
            dep[i]=dep[x]+1;
            dfs1(i,x);
        }
    }
}
void dfs2(int x,int xd)
{
    for(auto i:adj[x])
    {
        if(i!=xd)
        {
            
        }
    }
}
void myth()
{
    int n;
    cin>>n;
    for(int i=1,u;i<=n;i++)
    {
        cin>>u;
        dad[i]=u;
        if(u)
        {
            adj[i].pb(u);
            adj[u].pb(i);
        }
    }
    
    for(int i=1;i<=n;i++)
    {
        dp[i][0]=dad[i];
        dp1[j][0]=sz(adj[j])-(dad[i]!=0);
        if(not dad[i])
            dfs1(i,0);
    }
    for(int i=1;i<15;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(pwr2[j]<=dep[j])
                dp[j][i]=dp[dp[j][i-1]][i-1];
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(not dad[i])
            dfs2(i,0);
    }
}
signed main()
{
    int test_case=1;
    //cin>>test_case;
    calc();
    //sieve();
    //solve();
    while(test_case--)
    {
        myth();
        cout<<endl;
    }
    return 0;
}
