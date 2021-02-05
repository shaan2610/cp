#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
#define int long long
#define vi vector<int>
#define fk 1000000007
int power(int b,int e,int m)
{ 
    if(e<0)
        return 0;
    if(e==0) 
        return 1; 
    if(e%2) 
        return b*power(b*b%m,(e-1)/2,m)%m; 
    else 
        return power(b*b%m,e/2,m);
}
signed main()
{
    int test_case=1;
    //cin>>test_case;
    while(test_case--)
    {
        int n,d;
        cin>>n>>d;
        int ans=0;
        vi a(n);
        for(auto &i:a)
            cin>>i;
        sort(a.begin(),a.end());
        for(int i=0;i<n;i++)
        {
            auto it=lower_bound(a.begin(),a.end(),a[i]+d);
            if(it==a.end() or *it != a[i]+d)
                continue;
            int diff=(it-a.begin())-i;
            ans+=power(2,diff-1,fk);
            ans%=fk;
        }
        cout<<ans%fk;
    }
    return 0;
}