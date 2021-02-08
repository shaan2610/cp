#include "iostream"
#include "vector"
#include "stack"
using namespace std;
#define int             long long int
signed main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(auto &i:v)
        cin>>i;
    stack<pair<int,int>> s; //Taking first element as pivot element
    s.push({0,n-1});
    int cnt=0;
    while(not s.empty())
    {
        cnt++;
        int l=s.top().first,r=s.top().second;
        s.pop();
        if(l>=r)
            continue;
        int idx=r,piv=v[l];
        for(int i=r;i>l;i--)
        {
            if(v[i]>piv)
                swap(v[i],v[idx--]);
        }
        swap(v[l],v[idx]);
        s.push({l,idx-1});
        s.push({idx+1,r});
        
    }    
    for(auto i:v)
        cout<<i<<" ";
    return 0;
}