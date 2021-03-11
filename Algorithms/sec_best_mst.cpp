#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;
#define boost  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define F first
#define S second
#define fk 1000000007
#define int long long
#define vii vector<pair<int,int>>
const long long INF = 1e18;
const int N = 2e5 + 5;

int mom[N], sz[N];
void make(int v) 
{
    mom[v] = v;
    sz[v] = 1;
}
int jnt(int v) 
{
    if (v == mom[v]) 
        return v;
    return mom[v] = jnt(mom[v]);
}
void jnt(int a, int b) 
{
    a = jnt(a), b = jnt(b);
    if (a != b) 
    {
        if (sz[b] < sz[a]) 
            swap(a, b);
        mom[b] = a;
        sz[a] += sz[b];
    }
}

struct edge 
{
    int u, v, wt;
    bool operator<(const edge &other) const 
    {
        return wt < other.wt;
    }
};
// 1 -> 2 -> 3 -> 4 -> 5
// dp[1][1]=3
// dp[1][2]=dp[dp[1][1]][1]
// dp[i][j]=min(dp[dp[i][j-1]][j],dp[i][j-1])
int n, m, dep[N];
vii adj[N];
vector<edge> v, unused, used, smst;
int dp[N][18], mx[N][18];

void dfs(int x, int xd, int wt = 0) 
{
    dp[x][0] = xd;
    mx[x][0] = wt;
    for (auto i : adj[x]) 
    {
        if (i.F == xd) 
            continue;
        dep[i.F] = dep[x] + 1;
        dfs(i.F, x, i.S);
    }
}
int lca(int x, int y) 
{
    if (dep[x] < dep[y]) 
        swap(x, y);
    for(int i=16;i>=0;i--) 
    {
        if (dep[dp[x][i]] >= dep[y]) 
            x = dp[x][i];
    }
    if (x == y) 
        return x;
    for(int i=16;i>=0;i--) 
    {
        if (dp[x][i] != dp[y][i])
            x = dp[x][i], y = dp[y][i];
    }
    return dp[x][0];
} // n -> 1e5
// 1 2 3 4 5 6 7 8 9
int solve(int x, int y) 
{
    int z = lca(x, y), res = 0;
    if (x != z) 
    {
        for (int i = 17; i >= 0; i--) 
        {
            if (dep[dp[x][i]] >= dep[z]) 
            {
                res=max(res, mx[x][i]);
                x = dp[x][i];
            }
        }
    }
    if (y != z) 
    {
        for (int i = 17; i >= 0; i--) 
        {
            if (dep[dp[y][i]] >= dep[z]) 
            {
                res=max(res, mx[y][i]);
                y = dp[y][i];
            }
        }
    }
    return res;
}
signed main() 
{
    boost
    cin >> n >> m;
    v.resize(m);
    for (int i = 0; i < m; i++)
        cin >> v[i].u >> v[i].v >> v[i].wt;
    sort(v.begin(), v.end());
    for(int i=1;i<=n;i++)
        make(i);
    
    int mst = 0;
    for (int i = 0; i < m; i++) 
    {
        if (jnt(v[i].u) != jnt(v[i].v)) 
        {
            jnt(v[i].u, v[i].v);
            adj[v[i].u].emplace_back(v[i].v, v[i].wt);
            adj[v[i].v].emplace_back(v[i].u, v[i].wt);
            mst += v[i].wt;
            used.push_back(v[i]);
        } 
        else
            unused.push_back(v[i]);
    }
    
    dfs(1, 0, 0);

    for(int i=1;i<=17;i++)
    {
        for(int j=1;j<=n;j++) 
            dp[i][j] = dp[dp[i][j - 1]][j - 1]; 
    }

    for(int i=1;i<=17;i++)
    {
        for(int j=1;j<=n;j++)
            mx[i][j] = max(mx[i][j - 1], mx[dp[i][j - 1]][j - 1]);
    }
    
    int wt_dif = INF, f = -1;
    for (int i = 0; i < unused.size(); i++) 
    {
        int tmp = unused[i].wt - solve(unused[i].u, unused[i].v);
        if (tmp < wt_dif) 
            f = i;
        wt_dif = min(wt_dif, tmp);
    }
    if (wt_dif == INF) 
    {
        cout << "NO SECOND BEST MST\n";
        return 0;
    }
    cout << (mst + wt_dif) << endl;
    smst.push_back(unused[f]);
    int x = unused[f].u, y = unused[f].v;
    int z = lca(x, y);
    int mxv = unused[f].wt - wt_dif;    //2
    int pu = 0, pv = 0;
    // pu = node,  pv = parent node
    while (x != z and pu == 0) 
    {
        if (mx[x][0] == mxv) 
        {
            pu = dp[x][0];
            pv = x;
        }
        x = dp[x][0];
    }
    while (y != z and pu == 0) 
    {
        if (mx[y][0] == mxv) 
        {
            pu = dp[y][0];
            pv = y;
        }
        y = dp[y][0];
    }
    if (pu > pv) 
        swap(pu, pv);
    for (int i = 0; i < used.size(); i++) 
    {
        if (used[i].u > used[i].v) 
            swap(used[i].u, used[i].v);
        if (pu != used[i].u or pv != used[i].v) 
            smst.push_back(used[i]);
    }
    
    for (auto it : smst) 
        cout << it.u << " " << it.v << " " << it.wt << endl;
    return 0;
}