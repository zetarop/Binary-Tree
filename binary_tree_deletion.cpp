#include<bits/stdc++.h>
#define ve vector
#define pb push_back
#define ll long long
using namespace std;

class node
{
public:
	int val;
	node* l;
	node* r;
};

node* newNode(int n)
{
	node* temp = new node;
	temp->val=n;
	temp->l=NULL;
	temp->r=NULL;
	return temp;
}

node* insert(node* root, int n)
{
	if(root == NULL)
		return newNode(n);
	if(n <= root->val)
		root->l = insert(root->l, n);
	else
		root->r = insert(root->r, n);
}

void inOrder(node* root)
{
	if(root->l != NULL)
		inOrder(root->l);

	cout<<root->val<<" ";

	if(root->r != NULL)
		inOrder(root->r);
}

int preSuccesor(node* root)
{
	node* temp = root->l;
	while(temp->r != NULL)
		temp = temp->r;
	return temp->val;
}


node* Delete(node* root, int k)
{
	if(root == NULL)
		return NULL;
	if(k < root->val)
		root->l = Delete(root->l, k);
	else if(k > root->val)
		root->r = Delete(root->r, k);
	else
	{
		if(root->l == NULL && root->r == NULL)
			root = NULL;
		else if(root->l == NULL && root->r != NULL)
			root = root->r;
		else if(root->l != NULL&& root->r == NULL)
			root = root->l;
		else
		{
			int t=preSuccesor(root);
			root->val = t;
			root->l = Delete(root->l, t);
		}
	}
}


int main()
{
	node* root=NULL;
	ve<int> v{50,40,60,30,45,55,70,20,35,48,65,80,10,25,33,38,75,90,71,85,100,78};
	for(auto a:v)
		root = insert(root,a);
	cout<<"inOrder: "; inOrder(root); cout<<endl;

	root=Delete(root, 10);
	cout<<"\nafter deleting 10"<<endl;
	cout<<"inOrder: "; inOrder(root); cout<<endl;
	root=Delete(root, 30);
	cout<<"\nafter deleting 30"<<endl;;
	cout<<"inOrder: "; inOrder(root); cout<<endl;
	root=Delete(root, 50);
	cout<<"\nafter deleting 50 "<<endl;
	cout<<"inOrder: "; inOrder(root); cout<<endl;
	root=Delete(root,80);
	cout<<"\nafter deleting 80"<<endl;
	cout<<"inOrder: "; inOrder(root); cout<<endl;
}
