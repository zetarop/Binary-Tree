#include<bits/stdc++.h>
#define ve vector
#define pb push_back
#define ll long long
using namespace std;

struct node
{
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

node* cbt(ve<int> v, int L, int H)
{
	if(L > H)
		return NULL;

	int m = (L+H)/2;

	node* root = newNode(v[m]);
	root->l = cbt(v,L,m-1);
	root->r = cbt(v,m+1,H);

	return root;
}

int main()
{
	ve<int> v{1,2,3,4,5,6,7,8,9,10,12,23,45,56,78,89};
	int n=v.size();
	int L=0;
	int H=n-1;

	node* root=cbt(v,L,H);
	return 0;
}
