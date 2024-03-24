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

vector<int> vertical_order_traversal(TreeNode *r)
{
	queue<TreeNode*> node_q;
	queue<int> index_q;
	map<int,vector<int>> m;
	if(r==NULL)
		return {};
	node_q.push(r);
	index_q.push(0);
	while(!node_q.empty())
	{
		int size=node_q.size();
		for(int i=0;i<size;i++)
		{
			TreeNode* n=node_q.front();
			node_q.pop();
			int index=index_q.front();
			index_q.pop();
			m[index].push_back(n->data);
			if(n->left!=NULL)
			{
				node_q.push(n->left);
				index_q.push(index-1);
			}
			if(n->right!=NULL)
			{
				node_q.push(n->right);
				index_q.push(index+1);
			}
		}
	}
	vector<int> res;
	for(auto i:m)
	{
		for(auto j:i.second)
		{
			res.push_back(j);
		}
	}
	return res;
}

int main()
{
	TreeNode *root=NULL;
	vector<int> v{15,8,5,10,18,16,20};
	int n=v.size();
	for(int i=0;i<n;i++)
	{
		root=insert(root,v[i]);
	}
	vector<int> res=vertical_order_traversal(root);
	for(auto i:res)
	{
		cout<<i<<" ";
	}
	return 0;
}
