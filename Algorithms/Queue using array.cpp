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

class queueUsingArray {
public:
    int maxSize,frnt,rear,currSize;
    int *arr;
    queueUsingArray() {
        // Implement the Constructor
        maxSize=1e6+5;
        frnt=0;
        rear=-1;
        currSize=0;
        arr = new int[maxSize];
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        if(currSize) {
            return false;
        }
        else {
            return true;
        }
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if(currSize==maxSize) {
            cout<<"Queue is full";
            return;
        }
        else {
            arr[(rear+1)%maxSize]=data;
            rear++;
            currSize++;
        }
    }

    int dequeue() {
        // Implement the dequeue() function
        if(isEmpty()) {
            return -1;
        }
        int ans=arr[frnt%maxSize];
        frnt++;
        currSize--;
        return ans;
    }

    int front() {
        // Implement the front() function
        if(isEmpty()) {
            return -1;
        }
        return arr[frnt%maxSize];
    }
};

void solve() {
    queueUsingArray q;
    q.enqueue(10);
    q.enqueue(15);
    cout<<q.front()<<"\n";
    cout<<q.dequeue()<<"\n";
    q.enqueue(65);
    cout<<q.front()<<"\n";
    q.enqueue(11);
    while(not q.isEmpty()) {
        cout<<q.front()<<" ";
        q.dequeue();
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
