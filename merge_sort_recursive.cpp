#include <bits/stdc++.h>
using namespace std;
#define pb              push_back
#define vi              vector<int>
#define int             long long int
void merge(vi &v,int l,int r,int mid)
{
	int sz1=mid-l+1,sz2=r-mid;
	vi v1(sz1),v2(sz2);
	for(int i=l;i<=r;i++)
	{
		if(i<=mid)
			v1[i-l]=v[i];
		else
			v2[i-mid-1]=v[i];
	}
	int i=0,j=0,k=l;
	while (i<sz1 and j<sz2)
	{
		if(v1[i]<=v2[j])
			v[k++]=v1[i++];
		else
			v[k++]=v2[j++];
	}
	while(i<sz1)
		v[k++]=v1[i++];
	while(j<sz2)
		v[k++]=v2[j++];
}
void mergesort(vi &v,int l,int r)
{
	if(l<r)
	{
		int mid=(l+r)/2;
		mergesort(v,l,mid);
		mergesort(v,mid+1,r);
		merge(v,l,r,mid);
	}
}
signed main()
{
    int n;
	cin>>n;
	vi v(n);
	for(auto &i:v)
		cin>>i;
	mergesort(v,0,n-1);
	for(auto i:v)
		cout<<i<<" ";
	
    return 0;
}