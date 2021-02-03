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
int chkprm(int n){ int x=5,s=sqrt(n); if(n<2)return 0; if(n<4)return 1; if((n&1)==0)return 0; if(n%3==0)return 0; while(x<=s){ if(n%x==0)return 0; x+=2; if(n%x==0)return 0; x+=4; } return 1;}
vi prm;
void myth()
{
    in(z);
    int x=ub(prm,z)-prm.begin();
    int y=lb(prm,prm[x]+z)-prm.begin();
    P prm[x]*prm[y];
}
signed main()
{
    boost
    int test_case=1;
    I test_case;
    fr(i,2,30000)
        if(chkprm(i))
            prm.pb(i);
    while(test_case--)
    {
        myth();
        P endl;
    }
    TLE
    return 0;
}