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

void lvlByLvlOrder(node* root)
{
	queue<node*> Q;

	node* X = new node;
	X->val = -1;
	X->l=NULL;
	X->r=NULL;

	Q.push(root);
	Q.push(X);

	while(!Q.empty())
	{
		if(Q.size() == 1)
			break;
		node* temp = Q.front();
		Q.pop();

		if(temp->val == -1)
		{
			cout<<endl;
			Q.push(X);
			continue;
		}

		cout<<temp->val<<" ";
		if(temp->l != NULL)
			Q.push(temp->l);
		if(temp->r != NULL)
			Q.push(temp->r);
	}
}

int main()
{
	node* root = NULL;
	ve<int> v{50,40,60,30,45,55,70,20,35,48,65,80,10,25,33,38,75,90,71,85,100,78};
	for(auto a:v)
		root = insert(root,a);
	cout<<"lvl by Order \n"; lvlByLvlOrder(root); cout<<endl;
}
