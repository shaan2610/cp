#include "iostream"
#include "math.h"
#include "cstring"

using namespace std;

#define int long long
#define vi vector<int>
#define sz(v) (int)(v.size())
#define pb push_back
#define fk 998244353
double pi = acos(-1);
const long long inf = 1e18;

int power(int x,int n,int mod)
{
    if(n==0)
        return 1;
    if(n%2)
        return ((x%mod)*(power(x,n-1,mod)%mod))%mod;
    return power((x*x)%mod,n/2,mod)%mod;
}

int top(int x,int y)
{
    if(x%y)
        return x/y + 1;
    else
        return x/y;
}

int n,cost[10][10],dp[10][1000];

int tsp(int city,int mask)
{
    if(dp[city][mask]!=-1)
        return dp[city][mask];
    if(mask==(1<<(n))-1)  // when all cities are visited ...111111
        return dp[city][mask]=cost[city][0];
    int mn=inf;
    for(int i=0;i<n;i++)
    {
        if(not (mask&(1<<i)))
            mn=min(mn,cost[city][i]+tsp(i,mask|(1<<i))); 
    }
    return dp[city][mask]=mn;
}

void solve()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cin>>cost[i][j];
    }
    memset(dp,-1,sizeof(dp));
    cout<<tsp(0,1);   // City -> 1 => Mask -> ...001 = 1
}

signed main()
{
    int t=1;
    // cin>>t;
    while(t--)
    {
        solve();
        cout<<endl;
    }
    return 0;
}

/*      Test case

4
0 10 15 20
20 0 35 25
35 15 0 30
10 5 30 0

*/
