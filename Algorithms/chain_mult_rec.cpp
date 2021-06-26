#include "iostream"
#include "vector"
#include "cstring"

using namespace std;

#define int long long
#define vi vector<int>
#define sz(v) (int)(v.size())
#define pb push_back
const long long inf = 1e18;
const int N = 105;

int dp[N][N];

int top(int x,int y)
{
    if(x%y)
        return x/y + 1;
    else
        return x/y;
}

int chainmult(vi &a,int l,int r)
{
	if(dp[l][r]!=-1)
		return dp[l][r];
	if(l==r)
		return dp[l][r]=0;
	int mn=inf;
	for(int i=l;i<r;i++)
	{
		int ans=chainmult(a,l,i)+chainmult(a,i+1,r)+a[l-1]*a[i]*a[r];
		mn=min(mn,ans);
	}
	return dp[l][r]=mn;
}


void solve()
{
	int n;
	cin>>n;
	// n++;
	vi a(n);
	for(auto &i:a)
		cin>>i;
	memset(dp,-1,sizeof(dp));
	cout<<chainmult(a,1,n-1);
}

signed main()
{
    int t=1;
    //cin>>t;
    while(t--)
    {
        solve();
        cout<<endl;
    }
    return 0;
}

/*		Test case

5
1 2 3 4 3

*/