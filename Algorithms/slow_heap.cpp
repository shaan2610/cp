#include "iostream"
#include "vector"

using namespace std;

#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define vi vector<int>

struct node 
{
    int val;
    node* left;
    node* right;
};

node* slowheap(vi &a, int first, int last) 
{
    node* curr = new node();
    if (first > last) 
        return curr;
    if (first == last) 
    {
        curr->val = a[first];
        return curr;
    }
    int mn = a[first], l = first;
    for (int i = first; i <= last; i++) 
    {
        if (a[i] <= mn) 
        {
            mn = a[i];
            l = i;
        }
    }
    swap(a[l], a[last]);
    curr->val = a[last];
    int mid = (last - first + 1) / 2; // number of elements in the left part
    if (mid)
        curr->left = slowheap(a, first, first + mid - 1);
    if (first + mid <= last - 1)
        curr->right = slowheap(a, first + mid, last - 1);
    return curr;
}
void print(node* root, int num) 
{
    if (root == NULL) 
        return;
    cout << num << " " << (root->val) << endl;
    print(root->left, 2 * num);
    print(root->right, 2 * num + 1);
}
signed main() 
{
    boost
    int n;
    cin >> n;
    vi a(n);
    for(auto &i:a)
        cin>>i;
    node* root = slowheap(a, 0, n - 1); 
    print(root, 1);
    return 0;
}