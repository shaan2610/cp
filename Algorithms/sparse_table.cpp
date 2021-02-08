#pragma GCC optimize("Ofast")
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
#define MAXN 200005
int dp[MAXN][20];
vi logg(MAXN);
void solve()
{
    fr(i,2,MAXN-1)
        logg[i]=logg[i/2]+1;
}
void sparse(vi &v)
{
    int n=sz(v);
    f(i,n)
        dp[i][0]=v[i];
    fr(i,1,19)
    {
        f(j,n)
        {
            if(j+(1<<i)<=n)
            {
                //dp[j][i]=max(dp[j][i-1],dp[j+(1<<(i-1))][i-1]);   //For min/max
                //dp[i][j]=dp[j][i-1]+dp[j+(1<<(i-1))][i-1];        //For sum
            }
            else
                break;
        }
    }
}
int minquery(int l,int r)
{
    l--;
    r--;
    if(l>r)
        return -1;
    int x=logg[r-l+1];
    return max(dp[l][x],dp[r-(1<<x)+1][x]);
}
int sumquery(int l,int r)
{
    if(l>r)
        return -1;
    int sum=0;
    l--;
    r--;
    while(l<=r)
    {
        int x=logg[r-l+1];
        sum+=dp[l][x];
        l+=(1<<x);
    }
    return sum;
}
int SUM(vi &a,int l,int r)
{
    l--;
    r--;
    int sum=0;
    fr(i,l,r)
        sum+=a[i];
    return sum;
}
void myth()
{
    in(n);
    inp(a,n);
    sparse(a);
    in(q);
    f(i,q)
    {
        in(l);
        in(r);
        cout<<sumquery(l,r)<<" "<<SUM(a,l,r)<<endl;;
    }
}
signed main()
{
    boost
    int test_case=1;
    //I test_case;
    solve();
    while(test_case--)
    {
        myth();
        //P endl;
    }
    TLE
    return 0;
}