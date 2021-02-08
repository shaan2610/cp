#include <bits/stdc++.h>
using namespace std;
struct node
{
	char key;
	node *left,*right;
};
struct node *newnode(char x)
{
	node *temp;
	temp=new node;
	temp->key=x;
	temp->left=temp->right=NULL;
	return temp;
};
struct node* insert(node *node1,char key)
{
	if(node1==NULL)
		return newnode(key);
	if(key<node1->key)
		node1->left=insert(node1->left,key);
	else
		node1->right=insert(node1->right,key);
	return node1;
};
void in_traversal(node *node)
{
	if(node!=NULL)
	{
		in_traversal(node->left);
		cout<<node->key<<" ";
		in_traversal(node->right);
	}
}
void pre_traversal(node *node)
{
	if(node!=NULL)
	{
		cout<<node->key<<" ";
		pre_traversal(node->left);
		pre_traversal(node->right);
	}
}
signed main()
{
    //7, 5, 1, 8, 3, 6, 0, 9, 4, 2
	node *root=NULL;
	root=insert(root,'a');
	root=insert(root,'+');
	root=insert(root,'b');
	root=insert(root,'*');
	root=insert(root,'c');
	root=insert(root,'-');
	root=insert(root,'d');
	root=insert(root,'^');
	root=insert(root,'e');
	root=insert(root,'%');
	root=insert(root,'f');
	root=insert(root,'*');
	root=insert(root,'g');
	root=insert(root,'-');
	root=insert(root,'f');
	in_traversal(root);
	cout<<endl;
	pre_traversal(root);

    return 0;
}