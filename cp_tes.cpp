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
#define vii             vector<pair<int,int> >
#define pii             pair<int,int>
#define vi              vector<int>
#define sd(arr,n)       sort(arr,arr+n,greater<int>())
#define si(arr,n)       sort(arr,arr+n)
#define Si(v)           sort(v.begin(),v.end())
#define Sd(v)           sort(v.begin(), v.end(),sdf)
#define s2i(v)          sort(v.begin(),v.end(),sbs)
#define s2d(v)          sort(v.begin(),v.end(),sbds)
#define desc            greater<int>
#define eif             else if 
#define int             long long int
#define F               first
#define S               second
#define fk              1000000007
#define fk1             998244353
#define pie             3.14159265358979323846
#define dec(x)          fixed<<setprecision(x)
#define sz              size()
#define mi              map<int,int>
#define bs(a,n,x)       binary_search(a,a+n,x)
#define MX(a,n)         *(max_element(a,a+n))
#define MN(a,n)         *(min_element(a,a+n))
#define in(n)           int n;I n
#define inp(a,n)        int a[n];f(xxx,n) I a[xxx]
#define mem(a)          memset(a, -1, sizeof(a))
#define all(v)          v.begin(), v.end()
#define ub(v,x)         std::upper_bound(all(v), x)     //first value greater than x
#define lb(v,x)         std::lower_bound(all(v), x)     //first value greater than or equal to x
#define boost           ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define TLE             cerr<<endl<<"Time Elasped : "<<1.0 * clock() / CLOCKS_PER_SEC<<endl;
int invmod(int x, int n, int mod){ if(n==0)  return 1%mod; int half = invmod(x,n/2,mod);half = (half*half)%mod; if(n%2==1)  half = (half*(x%mod))%mod; return half;}
int bin(int a[],int l,int r,int x){ if(l<=r){ int m=l+(r-l)/2; if(a[m]==x) return m; else if (a[m]>x) return bin(a,l,m-1,x); else return bin(a,m+1,r,x);} else return -1;}
int power(int b,int e,int m){ if(e==0) return 1; if(e%2) return b*power(b*b%m,(e-1)/2,m)%m; else return power(b*b%m,e/2,m);}
int power(int b,int e){ if(e==0) return 1; if(e%2) return b*power(b*b,(e-1)/2); else return power(b*b,e/2);}
int ncr(int n, int r, int x) { if (r==0) return 1; int fac[n+1]; fac[0] = 1; fr(i,1,n) fac[i] = fac[i-1]*i%x; return (fac[n]* power(fac[r], x-2, x) % x * power(fac[n-r], x-2, x) % x) % x; }
int ncr(int n,int p){ int r=min(p,n-p),rf=1,ln=1; fr(i,1,r) rf=rf*i; f(i,r) ln=ln*(n-i); return ln/rf;}
bool sbs(pii &a,pii &b){ return (a.S<b.S);}
bool sbds(pii &a,pii &b){ return (a.S>b.S);}
bool sdf(pii &a,pii &b){ return (a.first > b.first); }
int SUM(int a[],int n){ int sum=0; f(i,n) sum+=a[i]; return sum;}
int chkprm(int n){ int x=5,s=sqrt(n); if(n<2)return 0; if(n<4)return 1; if((n&1)==0)return 0; if(n%3==0)return 0; while(x<=s){ if(n%x==0)return 0; x+=2; if(n%x==0)return 0; x+=4; } return 1;}
#define MAXT 100005
vector<int> adj[MAXT],eul,edep;           //*****TREE MOVES*****
vii ind(MAXT,{-1,-1});
int dep[MAXT],vis[MAXT],dad[MAXT],intime[MAXT],extime[MAXT],timer=0,dp[MAXT][20],logn[MAXT],dp1[MAXT][20],m[MAXT]={0};
void dfs_cal(int i){ intime[i]=timer; eul.pb(i); timer++; for(auto j: adj[i]){ if(j!=dad[i]){ dad[j]=i; dep[j]=dep[i]+1; dfs_cal(j); eul.pb(i);}} extime[i]=timer; timer++;}
//int prm[MAXS];                     //****SIEVE MOVES****
//void sieve(){ f(i,MAXS) prm[i]=i; for(int i=4;i<MAXS;i+=2) prm[i]=2; for(int i=3;i<sqrt(MAXS);i+=2){ if(prm[i]==i){ for(int j=i*i;j<MAXS;j+=i) prm[j]=i; }}}
struct query
{
    int l,r,idx,chk;
}q[MAXT];
bool anc(int x,int y)//y is ancestor of x
{
    return intime[y]<=intime[x]&&extime[y]>=extime[x];
}
void log_calc()
{
    logn[1]=0;
    fr(i,2,MAXT-1)
    logn[i]=logn[i/2]+1;
}
void sparse(int n)
{
    f(i,n)
    dp[i][0]=edep[i];
    for(int j=1;j<20;j++)
    {
        for(int i=0;i+(1<<j)<=n;i++)
            dp[i][j]=min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
    }
}
void sparse1(int n)
{
    fr(i,1,n)
        dp1[i][0]=dad[i];
    for(int j=1;j<20;j++)
    {
        for(int i=1;i<n;i++)
        {
            if(dep[i]-(1<<j)>=0)
                dp1[i][j]=dp1[dp1[i][j-1]][j-1];
        }
    }
}
int lca(int x,int y)
{
    if(anc(x,y))
        return y;
    eif(anc(y,x))
        return x;
    else
    {
        if(intime[x]>intime[y])
            swap(x,y);
        int ind1=ind[x].F,ind2=ind[y].F;
        //P ind1<<" "<<ind2<<endl;
        int z=logn[ind2-ind1+1];
        int q=min(dp[ind1][z],dp[ind2-(1<<z)+1][z]);
        int q1;
        if(dep[x]<=dep[y])
            q1=x;
        else
            q1=y;
        int dis=dep[q1]-q;
        string s="";
        while(dis!=0)
        {
            if(dis%2)
                s.pb('1');
            else
                s.pb('0');
            dis/=2;
        }
        reverse(all(s));
        int ans1=q1;
        f(i,s.L)
        {
            if(s[i]=='1')
                ans1=dp1[ans1][s.L-1-i];
        }
        return ans1;
    }
}
int ans=fk;
set<int> gt;
void add(int val)
{
    if(m[val]%2==0)
    {
        
    }
    else
        ans/=val;
    ans%=fk;
    m[val]++;
}
void sub(int val)
{
    if(m[val]%2==0)
        ans*=val;
    else
        ans/=val;
    m[val]--;
}
int a1;
bool srt(query a,query b)
{
    if(a.l/a1!=b.l/a1)
        return a.l/a1 < b.l/a1;
    eif((a.l/a1)%2)
        return a.r>b.r;
    else
        return a.r<b.r;
}
void myth()
{
    in(n);
    in(que);
    int a[n+1];
    fr(i,1,n)
    I a[i];
    f(i,n-1)
    {
        in(u);
        in(v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dad[1]=1;
    dep[1]=0;
    dfs_cal(1);
    log_calc();
    int cnt=0;
    for(auto i:eul)
    {
        edep.pb(dep[i]);
        if(ind[i].F==-1)
            ind[i].F=cnt;
        else
            ind[i].S=cnt;
        cnt++;
    }
    sparse(edep.sz);
    sparse1(n);
    f(i,que)
    {
        in(u);
        in(v);
        if(intime[u]>intime[v])
            swap(u,v);
        int pl=0,pr=-1,i1,i2,chk1=0;
        if(anc(v,u))
        {
            i1=ind[u].F;
            i2=ind[v].F;
            q[i].l=i1;
            q[i].r=i2;
        }
        else
        {
            i1=ind[u].S;
            i2=ind[v].F;
            q[i].l=i1;
            q[i].r=i2;
            chk1=ind[lca(u,v)].F;
        }
        q[i].idx=i;
        q[i].chk=chk1;
    }
    a1=sqrt(eul.sz)+1;
    sort(q,q+que,srt);
    int fans[que];
    
}
signed main()
{
    boost
    int test_case=1;
    //I test_case;
    while(test_case--)
    {
        myth();
        P endl;
    }
    TLE
    return 0;
}