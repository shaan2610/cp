#include <bits/stdc++.h> 
using namespace std; 
void hanoi(int n,char ini,char fin,char btw) 
{ 
	if (n == 1) 
	{ 
		cout<<"Move disk 1 from rod "<<ini<<" to rod "<<fin<<endl; 
		return; 
	} 
	hanoi(n-1,ini,btw,fin); 
	cout<<"Move disk "<<n<<" from rod "<<ini<<" to rod "<<fin<<endl; 
	hanoi(n-1,btw,fin,ini); 
} 
int main() 
{ 
	int n;
	cin>>n; 
	hanoi(n,'A','C','B');
	return 0; 
}