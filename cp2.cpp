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
int nc2(int n)
{
    return (n*(n-1))/2;
}
signed main()
{
    int test_case=1;
    //cin>>test_case;
    //sieve();
    // for(int i=1;i<MAXS;i++)
    //     prime[prm[i]].push_back(i);
    while(test_case--)
    {
        int k,p,num=-1;
        cin>>k>>p;
        if(k==1)
        {
            cout<<1;
            return 0;
        }
        while(k%2==0)
        {
            num=max(num,2ll);
            k/=2;
        }
        for(int i=3;i<=sqrt(k);i+=2)
        {
            while(k%i==0)
            {
                num=max(num,i);
                k/=i;
            }
        }
        if(k>2)
            num=max(num,k);
        k=num;
        int mn=1,mx=k*p,ans=1;
        while(mx>=mn)
        {
            if(mx==mn)
            {
                ans=mx;
                break;
            }
            else
            {
                int mid=(mn+mx)/2;
                int sum=0;
                int prod=k;
                int z=mid/prod;
                while(z)
                {
                    sum+=z;
                    prod*=k;
                    z=mid/prod;
                }
                if(sum>=p)
                    mx=mid;
                else
                    mn=mid+1;
            }
        }
        cout<<ans;
    }
    return 0;
}
