#include "bits/stdc++.h"

using namespace std;

#define int long long

const int fk=1000000007;
const int fk1=998244353;
const int inf=1e18;
const int N=1000005;
const int N1=1005;

vector<int> manacher_odd(string &s)
{
    int n=s.size();
    s='$'+s+'^';
    int l=0,r=-1;
    vector<int> d(n+2);
    for(int i=1;i<=n;i++)
    {
        if(i<=r)
            d[i]=max(0ll,min(r-i,d[l+(r-i)]));
        while(s[i+d[i]]==s[i-d[i]])
            d[i]++;
        if(i+d[i]>r)
        {
            l=i-d[i];
            r=i+d[i];
        }
    }
    return vector<int>(d.begin()+1,d.end()-1);
}

vector<int> manacher(string &s)
{
    int n=s.size();
    string s1="#";
    for(int i=0;i<n;i++)
    {
        s1.push_back(s[i]);
        s1.push_back('#');
    }
    return manacher_odd(s1);
}

void solve()
{
    string s;
    cin>>s;
    int n=s.size();
    vector<int> d,d1(n),d2(n);
    d=manacher(s);
    for(int i=0;i<n;i++)
    {
        d1[i]=d[2*i+1]/2;       //      Odd length palindrome with length 2*d[i]-1 centered at ith position
        d2[i]=(d[2*i]-1)/2;     //      Even length palindrome with length 2*d[i] centered at (i-1)th and ith position
    }
    for(auto i:d1)
        cout<<i<<" ";
    cout<<endl;
    for(auto i:d2)
        cout<<i<<" ";
}

signed main()
{
    int t=1;
    cin>>t;
    while(t--)
    {
        solve();
        cout<<endl;
    }
    return 0;
}
