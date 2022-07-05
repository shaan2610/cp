 #include "bits/stdc++.h"
// #include "iostream"
// #include "vector"
// #include "map"
// #include "set"

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
const int N=100005;
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

class trieNode {
public:
    trieNode* links[26];
    bool flag;
    bool containsKey(char c) {
        return (links[c-'a']!=NULL);
    }

    void put(char c) {
        links[c-'a']=new trieNode();
    }
};

class Trie {
public:

    trieNode* root;

    Trie() {
        root=new trieNode();
    }

    void insert(string s) {
        trieNode* curr=root;
        for(auto c:s) {
            if(curr->containsKey(c)) {
                curr=curr->links[c-'a'];
            }
            else {
                curr->put(c);
                curr=curr->links[c-'a'];
            }
        }
        curr->flag=true;
    }

    bool search(string s) {
        trieNode* curr=root;
        for(auto c:s) {
            if(curr->containsKey(c)) {
                curr=curr->links[c-'a'];
            }
            else {
                return false;
            }
        }
        return curr->flag;
    }

    bool chkPrefix(string s) {
        trieNode* curr=root;
        for(auto c:s) {
            if(curr->containsKey(c)) {
                curr=curr->links[c-'a'];
            }
            else {
                return false;
            }
        }
        return true;
    }
};

void solve() {
    int q;
    cin>>q;
    Trie tree;
    while(q--) {
        int type;
        string s;
        cin>>type>>s;
        if(type==1) {
            tree.insert(s);
        }
        else if(type==2) {
            if(tree.search(s)) {
                cout<<"true";
            }
            else {
                cout<<"false";
            }
        }
        else {
            if(tree.chkPrefix(s)) {
                cout<<"true";
            }
            else {
                cout<<"false";
            }
        }
        cout<<'\n';
    }
}

signed main()
{
    boost
    int t=1;
    // cin>>t;
    calc();
    while(t--)
    {
        solve();
        cout<<endl;
    }
    return 0;
}
