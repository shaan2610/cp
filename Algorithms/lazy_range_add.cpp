#include "bits/stdc++.h"

using namespace std;

#define int long long
#define vi vector<int>
#define sz(v) (int)(v.size())
#define pb push_back
#define all(v) v.begin(),v.end()
#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int fk=1000000007;
const int fk1=998244353;
const int inf=1e18;
const int N=505;

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

int top(int x,int y)
{
    if(x%y)
        return x/y + 1;
    else
        return x/y;
}

struct segtree
{
    vi t,lazy;
    segtree(int x)
    {
        t.resize(4*x,0);
        lazy.resize(4*x,0);
    }
    void rem(int st,int en,int v)
    {
        if(not lazy[v])
            return;
        t[v]+=lazy[v];
        if(st!=en)
        {
            lazy[2*v]+=lazy[v];
            lazy[2*v+1]+=lazy[v];
        }
        lazy[v]=0;
    }
    void update(int st,int en,int v,int idx,int val)
    {
        rem(st,en,v);
        if(st>en or idx>en or idx<st)
            return;
        if(st==en)
        {
            t[v]=val;
            return;
        }
        int mid=(st+en)/2;
        update(st,mid,2*v,idx,val);
        update(mid+1,en,2*v+1,idx,val);
        t[v]=t[2*v]+t[2*v+1];

    }
    int sum(int st,int en,int v,int l,int r)
    {
        rem(st,en,v);
        if(l>r or st>en)
            return 0;
        if(st>r or en<l)
            return 0;
        if(st>=l and en<=r)
            return t[v];
        int mid=(st+en)/2;
        return sum(st,mid,2*v,l,r)+sum(mid+1,en,2*v+1,l,r);
    }
    void ranadd(int st,int en,int v,int l,int r,int val)
    {
        rem(st,en,v);
        if(st>en or l>r)
            return;
        if(r<st or l>en)
            return;
        if(st>=l and en<=r)
        {
            lazy[v]=val;
            rem(st,en,v);
            return;
        }
        int mid=(st+en)/2;
        ranadd(st,mid,2*v,l,r,val);
        ranadd(mid+1,en,2*v+1,l,r,val);
        t[v]=t[2*v]+t[2*v+1];
    }
};


void solve()
{
    int n;
    cin>>n;
    segtree st(n+5);
    vi a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        st.update(0,n-1,1,i,a[i]);
    }
    for(int i=0;i<n;i++)
        cout<<st.sum(0,n-1,1,i,i)<<" ";
    cout<<endl;
    st.ranadd(0,n-1,1,2,5,-1);
    for(int i=0;i<n;i++)
        cout<<st.sum(0,n-1,1,i,i)<<" ";
    cout<<endl;
    st.update(0,n-1,1,3,4);
    for(int i=0;i<n;i++)
        cout<<st.sum(0,n-1,1,i,i)<<" ";
}

signed main()
{
    boost
    int t=1;
    // calc();
    // cin>>t;
    while(t--)
    {
        solve();
        cout<<endl;
    }
    return 0;
}                                                             