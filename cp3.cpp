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
        int n;
        cin>>n;
        vi a(n);
        for(auto &i:a)
            cin>>i;
        int ans=(n*(n-1))/2;
        cout<<ans<<endl;
        int x[n][22]={0};
        for(int i=0;i<n;i++)
        {
            int z=a[i],cnt=0;
            while(z)
            {
                x[i][cnt++]=z%2;
                z/=2;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<20;j++)
                cout<<x[i][j]<<" ";
            cout<<endl;
        }
        for(int i=1;i<20;i++)
        {
            int u=0,v=0;
            for(int j=0;j<n;j++)
            {
                cout<<x[j][i]<<" ";
                if(x[j][i])
                    u++;
                else
                    v++;
            }
            //cout<<u*v<<endl;
            cout<<endl;
        }
    }
    return 0;
}