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

class QueueUsingStack {
public:
    stack<int> st1,st2;
    QueueUsingStack() {
    }
    void push(int x) {
        st1.push(x);
    }
    bool isEmpty() {
        return ((st1.size()+st2.size())==0);
    }
    int front() {
        if(isEmpty()) {
            return -1;
        }
        if(not st2.empty()) {
            return st2.top();
        }
        while(not st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
        return st2.top();
    }
    
    // pop() and front() takes amortized O(1) time    
    
    int pop() {
        if(isEmpty()) {
            return -1;
        }
        if(not st2.empty()) {
            int ans=st2.top();
            st2.pop();
            return ans;
        }
        while(not st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
        int ans=st2.top();
        st2.pop();
        return ans;
    }
};

void solve() {
    QueueUsingStack q;
    q.push(10);
    q.push(15);
    cout<<q.front()<<"\n";
    cout<<q.pop()<<"\n";
    q.push(65);
    cout<<q.front()<<"\n";
    q.push(11);
    while(not q.isEmpty()) {
        cout<<q.front()<<" ";
        q.pop();
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
