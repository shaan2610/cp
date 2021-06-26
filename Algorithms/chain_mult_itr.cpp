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

int dp[10][10];

void solve()
{
    int n;
    cin>>n;
    vi a(n);
    for(auto &i:a)
        cin>>i;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i!=j)
                dp[i][j]=inf;
            else
                dp[i][j]=0;
        }
    }
    for(int len=2;len<n;len++)
    {
        for(int i=1;i<n-len+1;i++)
        {
            int j=i+len-1;
            for(int k=i;k<j;k++)
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+a[i-1]*a[k]*a[j]);
        }
    }
    cout<<dp[1][n-1];
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

5
1 2 3 4 3

*/