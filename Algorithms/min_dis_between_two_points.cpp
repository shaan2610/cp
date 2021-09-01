#include "bits/stdc++.h"

using namespace std;

#define int long long
#define vi vector<int>
#define sz(v) (int)(v.size())
#define pb push_back
#define all(v) v.begin(),v.end()
#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define F first
#define S second

float calc(pair<int,int> &a,pair<int,int> &b)
{
    return sqrt(((a.S-b.S)*(a.S-b.S))+((a.F-b.F)*(a.F-b.F)));
}

bool srt(pair<int,int> &a,pair<int,int> &b)
{
    if(a.S<b.S)
        return true;
    if(a.S==b.S)
    {
        if(a.F<b.F)
            return true;
        return false;
    }
    return false;
}

float min(float a,float b)
{
    if(a<b)
        return a;
    return b;
}

float mindist(vector<pair<int,int>> &v,int l,int r)
{
    if(r-l+1<=3)
    {
        float dis=10000.0;
        for(int i=l;i<=r;i++)
        {
            for(int j=i+1;j<=r;j++)
                dis=min(dis,calc(v[i],v[j]));
        }
        return dis;
    }
    int mid=(l+r)/2;
    pair<int,int> midp=v[mid];
    float dl=mindist(v,l,mid);
    float dr=mindist(v,mid+1,r);
    float d=min(dl,dr);
    vector<pair<int,int>> v1;
    for(int i=l;i<=r;i++)
    {
        if(abs(midp.F-v[i].F)<d)
            v1.pb({v[i].F,v[i].S});
    }
    sort(v1.begin(),v1.end(),srt);
    int n=v1.size();
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n and abs(v1[i].S-v1[j].S)<d;j++)
        {
            if(calc(v1[i],v1[j])<d)
                d=calc(v1[i],v1[j]);
        }
    }
    return d;
}

void solve()
{
    int n;
    cin>>n;
    vector<pair<int,int>> v(n),vx(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i].F>>v[i].S;
        vx[i].F=v[i].F;
        vx[i].S=v[i].S;
    }
    sort(vx.begin(),vx.end());
    float ans=mindist(vx,0,n-1);
    cout<<ans;
}

signed main()
{
    boost
    int t=1;
    // cin>>t;
    while(t--)
    {
        solve();
        cout<<endl;
    }
    return 0;
}
