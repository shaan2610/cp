#include <bits/stdc++.h>
using namespace std;

vector<int> manacher_odd(string &s) {
	int n=s.size();
	s='$'+s;
	s.push_back('^');
	vector<int> d(n+2);
	int l=0,r=1;
	for(int i=1;i<=n;i++) {
		d[i]=max(0,min(r-i,d[l+(r-i)]));
		while(s[i+d[i]]==s[i-d[i]]) {
			d[i]++;
		}
		if(i+d[i]>r) {
			r=i+d[i];
			l=i-d[i];
		}
	}
	return vector<int> (d.begin()+1,d.end()-1);
}

vector<int> manacher(string &s) {
	string s1;
	s1.push_back('#');
	for(auto i:s) {
		s1.push_back(i);
		s1.push_back('#');
	}
	return manacher_odd(s1);
}

vector<int> prefix_fxn(string &s) {
	int n=s.size();
	vector<int> pi(n);
	for(int i=1;i<n;i++) {
		int j=pi[i-1];
		while(j>0 and s[i]!=s[j]) {
			j=pi[j-1];
		}
		if(s[i]==s[j]) {
			j++;
		}
		pi[i]=j;
	}
	return pi;
}

vector<int> z_fxn(string &s) {
	int n=s.size();
	vector<int> z(n);
	for(int i=1,l=0,r=0;i<n;i++) {
		if(i<=r) {
			z[i]=min(r-i+1,z[i-l]);
		}
		while(i+z[i]<n and s[z[i]]==s[i+z[i]]) {
			z[i]++;
		}
		if(i+z[i]-1>r) {
			r=i+z[i]-1;
			l=i;
		}
	}
	return z;
}

void print_prefix_fxn(string &s) {
	int n=s.size();
	vector<int> pi=prefix_fxn(s);
	for(auto i:pi) {
		cout<<i<<" ";
	}
	cout<<'\n';
}

void print_z_fxn(string &s) {
	int n=s.size();
	vector<int> z=z_fxn(s);
	for(auto i:z) {
		cout<<i<<" ";
	}
	cout<<'\n';
}

void print_manacher(string s) {
	int n=s.size();
	vector<int> d=manacher(s);
	vector<int> d1(n),d2(n);
	for(int i=0;i<n;i++) {
		d1[i]=d[2*i+1]/2;
		d2[i]=(d[2*i]-1)/2;
	}
	for(auto i:d1) {
		cout<<i<<" ";
	}
	cout<<'\n';
	for(auto i:d2) {
		cout<<i<<" ";
	}
	cout<<'\n';
}

signed main() {
	string s;
	cin>>s;
	print_prefix_fxn(s);
	print_z_fxn(s);
	print_manacher(s);
	return 0;
}