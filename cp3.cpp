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
//#define endl            "\n"
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
#define bs(a,x)       binary_search(all(a),x)
#define MX(a)         *(max_element(all(a)))
#define MN(a)         *(min_element(all(a)))
#define in(n)           int n;I n
#define inp(a,n)        vi a(n+1);fr(xxx,1,n) I a[xxx]
#define mem(a)          memset(a, -1, sizeof(a))
#define ub(v,x)         std::upper_bound(all(v), x)     //first value greater than x
#define lb(v,x)         std::lower_bound(all(v), x)     //first value greater than or equal to x
#define boost           ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define TLE             cerr<<endl<<"Time Elasped : "<<1.0 * clock() / CLOCKS_PER_SEC<<endl;
//vi fac(MAXN);
//void fact(int x){ fac[0] = 1; fr(i,1,MAXN) fac[i] = fac[i-1]*i%x; }
int invmod(int x, int n, int mod){ if(n==0)  return 1%mod; int half = invmod(x,n/2,mod);half = (half*half)%mod; if(n%2==1)  half = (half*(x%mod))%mod; return half;}
int bin(vi &a,int l,int r,int x){ if(l<=r){ int m=l+(r-l)/2; if(a[m]==x) return m; else if (a[m]>x) return bin(a,l,m-1,x); else return bin(a,m+1,r,x);} else return -1;}
int power(int b,int e,int m){ if(e==0) return 1; if(e%2) return b*power(b*b%m,(e-1)/2,m)%m; else return power(b*b%m,e/2,m);}
int power(int b,int e){ if(e==0) return 1; if(e%2) return b*power(b*b,(e-1)/2); else return power(b*b,e/2);}
//int ncr(int n, int r, int x) { if (r==0) return 1; return (fac[n]* power(fac[r], x-2, x) % x * power(fac[n-r], x-2, x) % x) % x; }
int ncr(int n,int p){ int r=min(p,n-p),rf=1,ln=1; fr(i,1,r) rf=rf*i; f(i,r) ln=ln*(n-i); return ln/rf;}
bool sbs(pii &a,pii &b){ return (a.S<b.S);}
bool sbds(pii &a,pii &b){ return (a.S>b.S);}
int SUM(vi &a){ int sum=0; for(auto i:a) sum+=i; return sum;}
int chkprm(int n){ int x=5,s=sqrt(n); if(n<2)return 0; if(n<4)return 1; if((n&1)==0)return 0; if(n%3==0)return 0; while(x<=s){ if(n%x==0)return 0; x+=2; if(n%x==0)return 0; x+=4; } return 1;}
// #define MAXT 100005
// vi adj[MAXT],dep(MAXT);           //*****TREE MOVES*****
//void dfs_cal(int i){ dad[1]=1; intime[i]=timer++; for(auto j: adj[i]){ if(j!=dad[i]){ dad[j]=i;dep[j]=dep[i]+1;dfs_cal(j);}} extime[i]=timer++;}
//int prm[MAXS];                     //****SIEVE MOVES****
//void sieve(){ f(i,MAXS) prm[i]=i; for(int i=4;i<MAXS;i+=2) prm[i]=2; for(int i=3;i<sqrt(MAXS);i+=2){ if(prm[i]==i){ for(int j=i*i;j<MAXS;j+=i) prm[j]=i; }}}
int top(int x,int y)
{
    if(x%y)
        return x/y +1;
    return x/y;
}
int solve(int i,int j)
{
    if(i==j)
        return i;
    int mid=(i+j)/2;
    cout<<"? "<<i<<" "<<j<<endl;
    int x;
    cin>>x;
    if(j==i+1)
        return i+j-x;
    cout<<"? "<<i<<" "<<mid<<endl;
    int x1;
    cin>>x1;
    if(x==x1)
        return solve(i,mid);
    else
        return solve(mid+1,j);
}
void myth()
{
    int n;
    cin>>n;
    cout<<"! "<<solve(1,n)<<endl;
}
signed main()
{
    boost
    int test_case=1;
    //cin>>test_case;
    while(test_case--)
    {
        myth();
        //cout<<'\n';
    }
    TLE
    return 0;
}