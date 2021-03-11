#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;
#define F first
#define S second
#define int long long
#define vii vector<pair<int,int>>
const long long inf = 1e18;
const int MAXN = 100005;
int mom[MAXN],sz[MAXN];
int find(int x) //To find the head of the family to whome which x belongs
{
	if(mom[x]==x)
		return x;
	return mom[x]=find(mom[x]);
}
void mk(int x)	//To create a node
{
	mom[x]=x;
	sz[x]=1;
}
void jnt(int x,int y)//To joint two independent nodes x and y 
{
	int a=find(x),b=find(y);
	if(a!=b)
	{
		if(sz[a]>sz[b])
			swap(a,b);
		mom[b]=a;
		sz[a]+=sz[b];
	}
}

struct edge 
{
    int u,v,wt;
    bool operator<(const edge &other) const 
    {
        return wt<other.wt;
    }
};

int n,m,dep[MAXN];
vii adj[MAXN];
vector<edge> v,unvis,MST,SMST;
int dp[MAXN][18], mx[MAXN][18];

void sparse()
{
    for(int i=1;i<=17;i++)
    {
        for(int j=1;j<=n;j++) 
            dp[i][j]=dp[dp[i][j-1]][j-1]; 
    }
    for(int i=1;i<=17;i++)
    {
        for(int j=1;j<=n;j++)
            mx[i][j]=max(mx[i][j-1],mx[dp[i][j-1]][j-1]);
    }
}

void dfs(int x,int xd,int wt) 
{
    dp[x][0]=xd;
    mx[x][0]=wt;
    for (auto i:adj[x]) 
    {
        if(i.F!=xd)
        {
            dep[i.F]=dep[x]+1;
            dfs(i.F,x,i.S);
        }
    }
}

int lca(int x,int y)    // Using binary lifting (Logn)
{
    if(dep[x]<dep[y]) 
        swap(x,y);
    for(int i=16;i>=0;i--) 
    {
        if(dep[dp[x][i]]>=dep[y]) 
            x=dp[x][i];
    }
    if(x==y) 
        return x;
    for(int i=16;i>=0;i--) 
    {
        if(dp[x][i]!=dp[y][i])
        {
            x=dp[x][i];
            y=dp[y][i];
        }
    }
    return dp[x][0];
} 
int solve(int x,int y) 
{
    int z=lca(x,y),res=0;
    if(x!=z) 
    {
        for(int i=17;i>=0;i--) 
        {
            if(dep[dp[x][i]]>=dep[z]) 
            {
                res=max(res,mx[x][i]);
                x=dp[x][i];
            }
        }
    }
    if(y!=z) 
    {
        for(int i=17;i>=0;i--) 
        {
            if(dep[dp[y][i]]>=dep[z]) 
            {
                res=max(res,mx[y][i]);
                y=dp[y][i];
            }
        }
    }
    return res;
}

signed main() 
{
    cin>>n>> m;
    v.resize(m);
    for(int i=0;i<m;i++) 
        cin>>v[i].u>>v[i].v>>v[i].wt;
    sort(v.begin(),v.end());
    for(int i=1;i<=n;i++)
        mk(i);
    int mst=0;
    for(int i=0;i<m;i++) 
    {
        if(find(v[i].u)!=find(v[i].v)) 
        {
            jnt(v[i].u,v[i].v);
            adj[v[i].u].push_back({v[i].v, v[i].wt});
            adj[v[i].v].push_back({v[i].u, v[i].wt});
            mst+=v[i].wt;
            MST.push_back(v[i]);    // Finding MST using DSU
        }
        else
            unvis.push_back(v[i]);  // unvis consists of node not in MST
    }
    dfs(1, 0, 0);
    sparse();   // For precomputation of dp and mx
    int mn=inf,chk=-1;
    if(unvis.empty())
    {
        cout<<"NO SECOND BEST MST FOUND\n";
        return 0;
    }
    for(int i=0;i<unvis.size();i++) 
    {
        int diff=unvis[i].wt-solve(unvis[i].u,unvis[i].v);
        if (diff<mn) 
            chk=i;
        mn=min(mn,diff);
    }
    if(mn==inf) 
    {
        cout<<"NO SECOND BEST MST FOUND\n";
        return 0;
    }
    cout<<(mst+mn)<<'\n';
    SMST.push_back(unvis[chk]);
    int x=unvis[chk].u,y=unvis[chk].v;
    int z=lca(x,y);
    int mxv=unvis[chk].wt-mn;
    int n1=0,n2=0;
    // n1 = node,  n2 = parent node
    while(x!=z and n1==0) 
    {
        if(mx[x][0]==mxv) 
        {
            n1=dp[x][0];
            n2=x;
        }
        x=dp[x][0];
    }
    while(y!=z and n1==0) 
    {
        if(mx[y][0]==mxv) 
        {
            n1=dp[y][0];
            n2=y;
        }
        y=dp[y][0];
    }
    if(n1>n2) 
        swap(n1,n2);
    for(int i=0;i<MST.size();i++) 
    {
        if(MST[i].u>MST[i].v) 
            swap(MST[i].u,MST[i].v);
        if(n1!=MST[i].u or n2!=MST[i].v) 
            SMST.push_back(MST[i]);
    }
    for(auto i:SMST) 
        cout<<i.u<<" "<<i.v<<" "<<i.wt<<'\n';
    return 0;
}