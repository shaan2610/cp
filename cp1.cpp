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
        int n,ans=0;
        cin>>n;
        vi x(n),y(n);
        for(int i=0;i<n;i++)
            cin>>x[i]>>y[i];
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        for(auto i:x)
            ans+=abs(i-x[n/2]);
        for(auto i:y)
            ans+=abs(i-y[n/2]);
        cout<<ans;
    }
    return 0;
}