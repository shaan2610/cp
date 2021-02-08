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

void downheapify(node* curr) 
{
    node *lft = curr->left, *rht = curr->right;
    if (lft != NULL and rht != NULL) 
    {
        int mn = min(lft->val, rht->val);
        if (curr->val > mn) 
        {
            if (lft->val > rht->val) 
            {
                swap(curr->val, rht->val);
                downheapify(rht);
            } 
            else 
            {
                swap(curr->val, lft->val);
                downheapify(lft);
            }
        } 
    } 
    else if (lft != NULL) 
    {
        if (curr->val > lft->val) 
        {
            swap(curr->val, lft->val);
            downheapify(lft);
        }
    } 
    else if (rht != NULL) 
    {
        if (curr->val > rht->val) 
        {
            swap(curr->val, rht->val);
            downheapify(rht);
        }
    }
}
node* fastheap(vi &a, int first, int last) 
{
    node* curr = new node();
    if (first > last)       //Base condition
        return curr;
        
    if (first == last)      //Base condition
    {
        curr->val = a[first];
        return curr;
    }
    
    curr->val = a[last];
    int mid = (last - first + 1) / 2; // number of elements in the left part
    
    if (mid)
        curr->left = fastheap(a, first, first + mid - 1);
    
    if (first + mid <= last - 1)
        curr->right = fastheap(a, first + mid, last - 1);
    
    downheapify(curr);
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
    node* root = fastheap(a, 0, n - 1);
    print(root, 1); 
    return 0;
}