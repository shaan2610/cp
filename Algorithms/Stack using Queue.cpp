#include "bits/stdc++.h"

using namespace std;

#define int long long
#define vi vector<int>
#define sz(v) (int)(v.size())
#define pb push_back
#define all(v) v.begin(),v.end()
#define S second
#define F first
#define pii pair<int,int>
#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int fk=1000000007;
const int fk1=998244353;
const int inf=1e18;
const int N=300005;
const int N1=1005;

int power(int x,int n,int mod)
{
    if(not x)
        return 0;
    if(not n)
        return 1;
    if(n%2)
        return ((x%mod)*(power(x,n-1,mod))%mod)%mod;
    return power((x*x)%mod,n/2,mod)%mod;
}

int power(int x,int n)
{
    if(not x)
        return 0;
    if(not n)
        return 1;
    if(n%2)
        return (x*power(x,n-1));
    return power(x*x,n/2);
}

int top(int x,int y)
{
    if(x%y)
        return x/y + 1;
    else
        return x/y;
}

int tc=1;

void printtc() {
    cout<<"Case #"<<tc++<<": ";
}

class StackUsingQueue {
public:
    queue<int> q;
    StackUsingQueue() {
    }
  
    // Push takes O(N) time
    void push(int x) {
        int sz=q.size();
        q.push(x);
        while(sz--) {
            q.push(q.front());
            q.pop();
        }
    }
    bool isEmpty() {
        return (q.size()==0);
    }
    int top() {
        if(isEmpty()) {
            return -1;
        }
        return q.front();
    }
    int pop() {
        if(isEmpty()) {
            return -1;
        }
        int ans=q.front();
        q.pop();
        return ans;
    }
};

void solve() {
    StackUsingQueue st;
    st.push(10);
    st.push(15);
    cout<<st.top()<<"\n";
    cout<<st.pop()<<"\n";
    st.push(65);
    cout<<st.top()<<"\n";
    st.push(11);
    while(not st.isEmpty()) {
        cout<<st.top()<<" ";
        st.pop();
    }
}

signed main()
{
    boost
    int t=1;
    // cin>>t;
    // calc();
    while(t--)
    {
        solve();
        cout<<endl;
    }
    return 0;
}
