#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
	int data;
	struct TreeNode *left;
	struct TreeNode *right;
};

TreeNode* insert(TreeNode *r,int val)
{
	if(r==NULL)
	{
		TreeNode *n=(TreeNode*)malloc(sizeof(TreeNode));
		n->data=val;
		n->left=NULL;
		n->right=NULL;
		r=n;
	}
	else if(val<r->data)
		r->left=insert(r->left,val);
	else if(val>r->data)
		r->right=insert(r->right,val);
	return r;
}

int lowest_common_ancestor(TreeNode *r,int n1,int n2)
{
	if(r==NULL)
		return -1;
	else if(n1<r->data&&n2<r->data)
		return lowest_common_ancestor(r->left,n1,n2);
	else if(n1>r->data&&n2>r->data)
		return lowest_common_ancestor(r->right,n1,n2);
	return r->data;
}

int main()
{
	TreeNode *root=NULL;
	vector<int> v{15,10,20,5,13,18,25,3,7,11,14,16,17,21,27};
	int n=v.size();
	for(int i=0;i<n;i++)
	{
		root=insert(root,v[i]);
	}
	int n1,n2;
	cout<<"Enter the value:";
	cin>>n1>>n2;
	cout<<lowest_common_ancestor(root,n1,n2)<<endl;
	return 0;
}
