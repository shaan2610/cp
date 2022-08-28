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
const int N=200005;
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

vector<int> dx = {-1,0,0,1};
vector<int> dy = {0,1,-1,0};

int getCoins(int num,int dir,vector<pair<char,int>> &opr) {
    char optr=opr[dir].first;
    int sec=opr[dir].second;
    if(optr=='+') {
        return (num+sec);
    }
    if(optr=='-') {
        return (num-sec);
    }
    if(optr=='*') {
        return (num*sec);
    }
    if(optr=='/') {
        return (num/sec);
    }
}

// map<int,map<int,map<int,map<int,int>>>> dp;

// int maxCoin(int curr,int x,int y,int n,int m,vector<pair<char,int>> &opr) {

//     if(dp.count(x) and dp[x].count(y) and dp[x][y].count(curr) and dp[x][y][curr].count(m)) {
//         return dp[x][y][curr][m];
//     }
//     auto chkBound = [&] (int px,int py) {
//         if(px>=0 and px<n and py>=0 and py<n) {
//             return true;
//         }
//         return false;
//     };

//     if(m==0) {
//         return dp[x][y][curr][m]=curr;
//     }
//     int ans=0;
//     ans=max(ans,maxCoin(curr,x,y,n,m-1,opr));
//     for(int dir=0;dir<4;dir++) {
//         int nx=x+dx[dir];
//         int ny=y+dy[dir];
//         if(chkBound(nx,ny)) {
//             ans=max(ans,maxCoin(getCoins(curr,dir,opr),nx,ny,n,m-1,opr));
//         }
//     }
//     return dp[x][y][curr][m]=ans;
// }

void solve() {
    int n,p,m,x,y;
    cin>>n>>p>>m>>x>>y;
    vector<pair<char,int>> opr(4);
    for(auto &i:opr) {
        cin>>i.first>>i.second;
    }
    vector<int> sx(p),sy(p),c(p);
    for(int i=0;i<p;i++) {
        cin>>sx[i]>>sy[i]>>c[i];
    }
    // dp.clear();
    printtc();
    if(n==1) {
        cout<<0;
    }
    // cout<<maxCoin(0,x-1,y-1,n,m,opr);

    auto chkBound = [&] (int px,int py) {
        if(px>=0 and px<n and py>=0 and py<n) {
            return true;
        }
        return false;
    };

    auto getCoins = [&] (int num,int dir) {
        char optr=opr[dir].first;
        int sec=opr[dir].second;
        if(optr=='+') {
            return (num+sec);
        }
        if(optr=='-') {
            return (num-sec);
        }
        if(optr=='*') {
            return (num*sec);
        }
        if(optr=='/') {
            return (num/sec);
        }
    };

    set<pair<pair<int,int>,pair<int,int>>,greater<pair<pair<int,int>,pair<int,int>>>> q;
    q.insert({{0,0},{x-1,y-1}});
    vector<vector<set<pair<int,int>>>> coins(n,vector<set<pair<int,int>>>(n));
    coins[x-1][y-1].insert({0,0});
    int ans=0;

    auto getMax = [&] (int cx,int cy) {
        int mx=0;
        for(auto i:coins[cx][cy]) {
            mx=max(mx,i.first);
        }
        return mx;
    };

    while(not q.empty()) {
        auto p=*q.begin();
        q.erase(q.begin());
        int time=p.first.second;
        int nodex=p.second.first,nodey=p.second.second;
        ans=max(ans,getMax(nodex,nodey));
        if(time==m) {
            continue;
        }
        for(int dir=0;dir<4;dir++) {
            int nx=nodex+dx[dir],ny=nodey+dy[dir];
            int newCoins=getCoins(p.first.first,dir);
            if(chkBound(nx,ny)) {
                if(coins[nx][ny].empty()) {
                    q.insert({{newCoins,time+1},{nx,ny}});
                    coins[nx][ny].insert({newCoins,time+1});
                }
                else {
                    int chk=0;
                    vector<pair<int,int>> v;
                    for(auto i:coins[nx][ny]) {
                        if(i.first<=newCoins and i.second>=time) {
                            v.push_back({i.first,i.second});
                        }
                        else if(i.first>=newCoins and i.second<=time) {
                            chk++;
                        }
                    }
                    for(auto i:v) {
                        q.erase({{i.first,i.second},{nx,ny}});
                        coins[nx][ny].erase({i.first,i.second});
                    }
                    if(chk==0) {
                        q.insert({{newCoins,time+1},{nx,ny}});
                        coins[nx][ny].insert({newCoins,time+1});
                    }
                }
            }
        }
    }
    cout<<ans;
}

signed main()
{
    boost
    int t=1;
    cin>>t;
    // calc();
    while(t--)
    {
        solve();
        cout<<endl;
    }
    return 0;
}