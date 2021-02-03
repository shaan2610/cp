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
#define MAXN 1005
vi fac(MAXN);
void fact(int x){ fac[0] = 1; fr(i,1,MAXN-1) fac[i] = fac[i-1]*i%x; }
int invmod(int x, int n, int mod){ if(n==0)  return 1%mod; int half = invmod(x,n/2,mod);half = (half*half)%mod; if(n%2==1)  half = (half*(x%mod))%mod; return half;}
int bin(vi &a,int l,int r,int x){ if(l<=r){ int m=l+(r-l)/2; if(a[m]==x) return m; else if (a[m]>x) return bin(a,l,m-1,x); else return bin(a,m+1,r,x);} else return -1;}
int power(int b,int e,int m){ if(e==0) return 1; if(e%2) return b*power(b*b%m,(e-1)/2,m)%m; else return power(b*b%m,e/2,m);}
int power(int b,int e){ if(e==0) return 1; if(e%2) return b*power(b*b,(e-1)/2); else return power(b*b,e/2);}
int ncr(int n, int r, int x) { if (r==0) return 1; return (fac[n]* power(fac[r], x-2, x) % x * power(fac[n-r], x-2, x) % x) % x; }
int ncr(int n,int p){ int r=min(p,n-p),rf=1,ln=1; fr(i,1,r) rf=rf*i; f(i,r) ln=ln*(n-i); return ln/rf;}
bool sbs(pii &a,pii &b){ return (a.S<b.S);}
bool sbds(pii &a,pii &b){ return (a.S>b.S);}
int SUM(vi &a)
{
	int sum=0;
	for(auto i:a)
		sum+=i;
	return sum;
}

void myth()
{
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(auto &i:a)
        cin>>i;
    sort(a.begin(),a.end(),greater<int>());
    int cnt=0,num=a[k-1];
    int cnt1=0;
    for(int i=k-1;i>=0;i--)
    {
        if(a[i]==num)
            cnt++;
    }
    for(auto i:a)
    {
        if(i==num)
            cnt1++;
    }
    //cout<<2;
    cout<<ncr(cnt1,cnt,fk);
}
signed main()
{
    int test_case=1;
    cin>>test_case;
    //sieve();
    //solve();
    fact(fk);
    while(test_case--)
    {
        myth();
        cout<<endl;
    }
    return 0;
}
