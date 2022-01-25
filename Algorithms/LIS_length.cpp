#include "bits/stdc++.h"

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
const int N=505;
const int N1=1e5+5;

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

int lis(vi &a)          // Longest non-decreasing subsequence
{
    int n=sz(a);
    vi tail(n);
    tail[0]=a[0];
    int len=1;
    for(int i=1;i<n;i++)
    {                   // For longest increasing subsequence change upper_bound to lower_bound
        int idx=upper_bound(tail.begin(),tail.begin()+len,a[i])-tail.begin();
        if(idx==len)
        {
            tail[len]=a[i];
            len++;
        }
        else
            tail[idx]=a[i];
    }
    return len;
}

void solve()
{
    int n;
    cin>>n;
    vi a(n);
    for(auto &i:a)
        cin>>i;
    cout<<lis(a);
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
