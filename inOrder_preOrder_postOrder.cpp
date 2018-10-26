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
void preOrder(node* root)
{
	cout<<root->val<<" ";

	if(root->l != NULL)
		inOrder(root->l);

	if(root->r != NULL)
		inOrder(root->r);
}

void postOrder(node* root)
{
	if(root->l != NULL)
		inOrder(root->l);

	if(root->r != NULL)
		inOrder(root->r);

	cout<<root->val<<" ";
}


int main()
{
	node* root=NULL;
	ve<int> v{50,40,60,30,45,55,70,20,35,48,65,80,10,25,33,38,75,90,71,85,100,78};
	for(auto a:v)
		root = insert(root,a);
	cout<<"inOrder: "; inOrder(root); cout<<endl;
	cout<<"preOrder: "; preOrder(root); cout<<endl;
	cout<<"postOrder: "; postOrder(root); cout<<endl;
}
