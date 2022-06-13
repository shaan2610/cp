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

vector<int> heap;
int Size=0;

int left(int i) {
    return (2*i+1);
}

int right(int i) {
    return (2*i+2);
}

int parent(int i) {
    return ((i-1)/2);
}

void insert(int num) {
    heap[Size]=num;
    int i=Size;
    if(Size) {
        while(heap[parent(i)]>heap[i]) {
            swap(heap[parent(i)],heap[i]);
            i=parent(i);
        }
    }
    Size++;
}

void heapify(int i,int n) {
    int largest=i,l=left(i),r=right(i);
    if(l<n and heap[l]<heap[largest]) {
        largest=l;
    }
    if(r<n and heap[r]<heap[largest]) {
        largest=r;
    }
    if(largest!=i) {
        swap(heap[largest],heap[i]);
        heapify(largest,n);
    }
}

int extractMin() {
    int ans=heap[0];
    swap(heap[0],heap[Size-1]);
    Size--;
    heapify(0,Size);
    return ans;
}

vector<int> minHeap(int n, vector<vector<int>>& q) {
    // Write your code here.
    heap.clear();
    heap.resize(n);
    Size=0;
    vector<int> ans;
    for(auto i:q) {
        if(i[0]) {
            ans.push_back(extractMin());
        }
        else {
            int num=i[1];
            insert(num);
        }
    }
    return ans;
}

void solve1() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &i:a) {
        cin>>i;
    }
    heap.clear();
    for(auto i:a) {
        heap.push_back(i);
    }
    Size=n;

    // It uses O(N) time complexity to convert array a to min heap
    for(int i=n/2;i>=0;i--) {
        heapify(i,n);
    }
    for(int i=0;i<n;i++) {
        cout<<heap[i]<<" ";
    }
}

void solve() {
    int q;
    cin>>q;
    vector<vector<int>> v(q);

    // Query of type 1 means print the min element and remove it
    // Query of type 0 means insert the given element
    for(int i=0,type,x;i<q;i++) {
        cin>>type;
        v[i].push_back(type);
        if(type==0) {
            cin>>x;
            v[i].push_back(x);
        }
    }
    vector<int> ans=minHeap(q,v);
    // If we push the element 1 by 1 to make the min/max Heap then t will cost us O(nlogn)
    // To convert the whole array into a min/max Heap in O(N) we use heapify function as stated in solve1()
}

signed main()
{
    boost
    int t=1;
    // cin>>t;
    // calc();
    while(t--)
    {
        solve1();
        cout<<endl;
    }
    return 0;
}
