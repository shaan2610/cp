#include "iostream"
#include "vector"
#include "math.h"

using namespace std;

#define int long long
#define vi vector<int>
#define sz(v) (int)(v.size())
#define pb push_back
#define fk 998244353
#define F first
#define S second
double pi = acos(-1);
const long long inf = 1e18;

int power(int x,int n)
{
    if(n==0)
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

int dp[100][10];

void solve()
{
    int n;
    cin>>n;
    int cost[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cin>>cost[i][j];
    }
    for(int i=0;i<=(1<<n);i++)
    {
        for(int j=0;j<=n;j++)
            dp[i][j]=inf;
    }
    dp[1][0]=0;
    for(int mask=1;mask<(1<<n);mask++)
    {
        for(int last=0;last<n;last++)
        {
            if(mask&(1<<last))
            {
                for(int next=0;next<n;next++)
                {
                    if(mask&(1<<next))
                        continue;
                    dp[mask|(1<<next)][next]=min(dp[mask|(1<<next)][next],dp[mask][last]+cost[last][next]);
                }
            }
        }
    }
    int ans=inf;
    for(int i=1;i<n;i++)
        ans=min(ans,dp[(1<<n)-1][i]+cost[i][0]);
    cout<<ans;
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