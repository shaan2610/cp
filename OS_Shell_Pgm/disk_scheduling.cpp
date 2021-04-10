#include "bits/stdc++.h"

using namespace std;

#define int long long
#define vi vector<int>
#define sz(v) (int)(v.size())
#define pb push_back
const long long inf = 1e18;

#define tail 10
int pos,n;
vector<int> v;
void FCFS()
{
    int curr=pos,ans=0;
    cout<<"FCFS execution order :-"<<endl;
    for(int i=0;i<n;i++)
    {
        ans+=abs(v[i]-curr);
        curr=v[i];
        cout<<v[i]<<" ";
    }
    cout<<endl<<ans<<endl;
}
void SSTF()
{
    set<int> s;
    for(int i=0;i<n;i++)
        s.insert(v[i]);
    int curr=pos,ans=0;
    cout<<"SSTF execution order :-"<<endl;
    while(not s.empty())
    {
        auto it=s.lower_bound(curr);
        if(it==s.begin())
        {
            ans+=abs(*it-curr);
            curr=*it;
            cout<<*it<<" ";
            s.erase(it);
        }
        else if(it==s.end())
        {
            it--;
            ans+=abs(*it-curr);
            curr=*it;
            cout<<*it<<" ";
            s.erase(it);
        }
        else
        {
            auto it1=it;
            it1--;
            if(abs(*it1-curr)<=abs(*it-curr))
            {
                ans+=abs(*it1-curr);
                curr=*it1;
                cout<<*it1<<" ";
                s.erase(*it1);
            }
            else
            {
                ans+=abs(*it-curr);
                curr=*it;
                cout<<*it<<" ";
                s.erase(*it);
            }
        }
    }
    cout<<endl<<ans<<endl;
}
void SCAN() // Considering the direction to the end
{
    cout<<"SCAN execution order :-"<<endl;
    int idx=-1,curr=pos;
    vi v1(n);
    for(int i=0;i<n;i++)
    {
        v1[i]=v[i];
    }
    sort(v1.begin(),v1.end());
    for(int i=0;i<n;i++)
    {
        if(v1[i]>=curr)
        {
            idx=i;
            break;
        }
    }
    int ans=0;
    for(int i=idx;i<n;i++)
    {
        cout<<v1[i]<<" ";
        ans+=abs(curr-v1[i]);
        curr=v1[i];
    }
    ans+=abs(tail-curr);
    ans*=2;
    curr=pos;
    for(int i=idx-1;i>=0;i--)
    {
        cout<<v1[i]<<" ";
        ans+=abs(curr-v1[i]);
        curr=v1[i];
    }
    cout<<endl<<ans<<endl;
}
void CSCAN()
{
    cout<<"CSCAN execution order :-"<<endl;
    int idx=-1,curr=pos;
    vi v1(n);
    for(int i=0;i<n;i++)
    {
        v1[i]=v[i];
    }
    sort(v1.begin(),v1.end());
    for(int i=0;i<n;i++)
    {
        if(v1[i]>=curr)
        {
            idx=i;
            break;
        }
    }
    int ans=0;
    for(int i=idx;i<n;i++)
    {
        cout<<v1[i]<<" ";
        ans+=abs(curr-v1[i]);
        curr=v1[i];
    }
    ans+=abs(tail-curr);
    ans+=tail;
    curr=0;
    for(int i=0;i<idx;i++)
    {
        cout<<v1[i]<<" ";
        ans+=abs(curr-v1[i]);
        curr=v1[i];
    }
    cout<<endl<<ans<<endl;
}
void LOOK() // Considering the direction to the end
{
    cout<<"LOOK execution order :-"<<endl;
    int idx=-1,curr=pos;
    vi v1(n);
    for(int i=0;i<n;i++)
    {
        v1[i]=v[i];
    }
    sort(v1.begin(),v1.end());
    for(int i=0;i<n;i++)
    {
        if(v1[i]>=curr)
        {
            idx=i;
            break;
        }
    }
    int ans=0;
    for(int i=idx;i<n;i++)
    {
        cout<<v1[i]<<" ";
        ans+=abs(curr-v1[i]);
        curr=v1[i];
    }
    ans*=2;
    curr=pos;
    for(int i=idx-1;i>=0;i--)
    {
        cout<<v1[i]<<" ";
        ans+=abs(curr-v1[i]);
        curr=v1[i];
    }
    cout<<endl<<ans<<endl;
}
signed main()
{
    cin>>pos;
    cin>>n;
    for(int i=0,x;i<n;i++)
    {
        cin>>x;
        v.pb(x);
    }
    FCFS();
    SSTF();
    SCAN();
    CSCAN();
    LOOK();
    return 0;
}