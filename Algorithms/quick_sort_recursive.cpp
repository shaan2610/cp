#include "iostream"
#include "vector"
using namespace std;
#define int             long long int
void quicksort(vector<int> &v,int l,int r)
{
    if(l<r)
    {    int piv=v[r],idx=l;
        for(int i=l;i<r;i++)
        {
            if(v[i]<piv)
                swap(v[i],v[idx++]);
        }
        swap(v[r],v[idx]);
            quicksort(v,l,idx-1);
            quicksort(v,idx+1,r);
    }
}
signed main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(auto &i:v)
        cin>>i;
    quicksort(v,0,n-1); //In this case we are taking pivot element as the last element
    for(auto i:v)
        cout<<i<<" ";
    return 0;
}