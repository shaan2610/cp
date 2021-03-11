#include "bits/stdc++.h"
using namespace std;
#define int long long
#define vi vector<int>
#define sz(v) (int)(v.size()
const long long inf = 1e18;

set<int> s;
map<int,int> m;
int n;

int top(int x,int y)
{
    if(x%y)
        return x/y + 1;
    else
        return x/y;
}

int mex()
{
	return *s.begin();
}

void add(int x)
{
	m[x]++;
	if(x>=0 and x<=n+1 and s.count(x))
		s.erase(x);
}

void rem(int x)
{
	if(m[x]==1)
		s.insert(x);
	m[x]--;
}

void solve()
{
    cin>>n;
    vi a(n);
    for(auto &i:a)
    	cin>>i;
    for(int i=0;i<=n+1;i++)
    	s.insert(i);
    for(auto i:a)
    {
    	m[i]++;
    	if(s.count(i))
	    	s.erase(i);
    }
    cout<<mex();
    add(2);
    cout<<mex();
    rem(0);
    cout<<mex();

}
signed main()
{
    int t=1;
    //cin>>t;
    while(t--)
    {
        solve();
        cout<<endl;
    }
    return 0;
}