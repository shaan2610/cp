#pragma GCC optimize("Ofast")
#include "iostream"
#include "algorithm"
using namespace std;
#define boostIO                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define rep(i, a, b) for int i = a; i < b; i++)
#define repn(i, n) for (int i = 1; i <= n; i++)
#define rrep(i, b, a) for (int i = b; i >= a; i--)
#define sz(v) (int)(v.size())
#define all(v) v.begin(), v.end()
#define mem0(a) memset(a, 0, sizeof(a))
#define mem1(a) memset(a, -1, sizeof(a))
#define trav(a, x) for (auto &a : x)
#define popcount(x) __builtin_popcountll(x)
#define pb push_back
#define fi first
#define se second
#define mod 1000000007
#define maxn 100005
#define int long long
typedef pair<int, int> pii;
int power(int x, int a) 
{
    if (!a) return 1;
    int half = power(x, a / 2);
    half = half * half;
    if (a & 1) half = half * x;
    return half;
}
int stringequal(string &a, string &b) 
{
    int k = max(a.size(), b.size());
    if(a.size()<b.size())
    {
        while(b.size()-a.size())
            a='0'+a;
    }
    else if(b.size()<a.size())
    {
        while(a.size()-b.size())
            b='0'+b;
    }
    return k;
}
string add(string a, string b) 
{
    string res;
    int k = stringequal(a, b), carry = 0;
    for (int i = k - 1; i >= 0; i--) {
        int fb = a[i] - '0', sb = b[i] - '0';
        int z=fb+sb+carry;
        carry=z/2;
        res.pb(z%2+'0');
    }
    if (carry) res.push_back('0'+carry);
    reverse(res.begin(),res.end());
    return res;
}
// X * Y == (2 ^ n) * (Xl * Yl) + (2 ^ (n / 2) * ((Xl + Xr) * (Yl + Yr) - XlYl - XrYr)) + XrYr
long long multiply(string a, string b) 
{
    int n = stringequal(a, b);
    if (n == 0) 
        return 0;
    if (n == 1) 
        return ((a[0] - '0') * (b[0] - '0'));
    int lft = n/2;
    int rht = n-lft;
    
    string alft = a.substr(0, lft), arht = a.substr(lft, rht);
    string blft = b.substr(0, lft), brht = b.substr(lft, rht);

    int sum1 = multiply(alft, blft);
    int sum2 = multiply(add(alft, arht), add(blft, brht));
    int sum3 = multiply(arht, brht);
    sum2 -= (sum1 + sum3);
    sum1 *= power(2, 2 * rht);
    sum2 *= power(2, rht);
    return (sum1 + sum2 + sum3);
}
signed main() 
{
    boostIO;
    string a, b;
    getline(cin, a);
    getline(cin, b);
    cout << multiply(a, b) << endl;
    return 0;
}
