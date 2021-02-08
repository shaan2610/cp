#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
#define int long long
#define vi vector<int>
#define fk 1000000007
#define sz(x) (x.empty() ? 0 : x.size())
signed main()
{
    int test_case=1;
    //cin>>test_case;
    while(test_case--)
    {
        int n;
        cin>>n;
        string a,b;
        cin>>a>>b;
        string a1=a,b1=b;
        sort(a1.begin(),a1.end());
        sort(b1.begin(),b1.end());
        for(int i=0;i<n;i++)
        {
            if(a1[i]!=b1[i])
            {
                cout<<-1;
                return 0;
            }
        }
        vector<pair<pair<int,int>,int>> v;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]==b[0])
            {
                if(i==0)
                    break;
                ans++;
                v.push_back({{i,0},n-i});
                string s1=a.substr(0,i);
                string s2=a.substr(i,n-i);
                a=s2+s1;
                break;
            }
        }
        int comp=1;
        for(int i=1;i<n-1;i++)
        {
            for(int j=comp;j<n;j++)
            {
                if(a[j]==b[i] and j!=i)
                {
                    ans+=2;
                    v.push_back({{comp,j-comp},n-j});
                    v.push_back({{n-comp,0},comp});
                    string s1=a.substr(0,comp);
                    string s2=a.substr(comp,j-comp);
                    string s3=a.substr(j,n-j);
                    a=s1+s3+s2;
                    break;
                }
            }
            comp++;
        }
        cout<<ans<<endl;
        for(auto i:v)
            cout<<i.first.first<<" "<<i.first.second<<" "<<i.second<<endl;
    }
    return 0;
}