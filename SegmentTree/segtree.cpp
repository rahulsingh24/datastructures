#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long int a[1000000];

struct node{
	int sum;
	int lazy;
	/*node(int x,int y)
	{
		sum =x;
		lazy = y;
	}*/
}tree[1000000];


void merge(node &ans,node &left,node &right)
{
	ans.sum = left.sum + right.sum;
}

void build(int i,int left,int right)
{
	if(left==right)
	{
		tree[i].sum=a[left];
	//	tree[i].lazy=0;
	}
	else
	{
		int mid = (right+left)/2;
		build(2*i,left,mid);
		build(2*i+1,mid+1,right);
		merge(tree[i],tree[2*i],tree[2*i+1]);
	}
}


void update(int i,int left,int right, int val,int start,int end)
{

	if(tree[i].lazy!=0)
		{
			tree[i].sum+= (right-left+1)*tree[i].lazy;
			if(left!=right)
			{
				tree[2*i].lazy+=tree[i].lazy;
				tree[2*i+1].lazy+=tree[i].lazy;
			}
			tree[i].lazy = 0;
		}

	if(left>right|| left>end || start>right)
		return;

	if(start<=left && right<=end)
	{
		tree[i].sum = tree[i].sum + (right-left+1)*val;
		if(left!=right)
			{
				tree[2*i].lazy+=val;
				tree[2*i+1].lazy+=val;
			}

			return;
	}

	int mid = (right+left)/2;
		update(2*i,left,mid,val,start,end);
		update(2*i+1,mid+1,right,val,start,end);
		merge(tree[i],tree[2*i],tree[2*i+1]);
}

int query(int i,int left,int right,int start,int end)
{
	if(tree[i].lazy!=0)
		{
			tree[i].sum+= (right-left+1)*tree[i].lazy;
			if(left!=right)
			{
				tree[2*i].lazy+=tree[i].lazy;
				tree[2*i+1].lazy+=tree[i].lazy;
			}
			tree[i].lazy = 0;
		}

	if(left>right|| left>end || start>right)
		return 0;

	if(start<=left && right<=end)
	{
		
			return tree[i].sum;
	}

	int mid = (right+left)/2;
	int leftanswer=	query(2*i,left,mid,start,end);
	int rightanswer=	query(2*i+1,mid+1,right,start,end);
	//	merge(tree[i],tree[2*i],tree[2*i+1]);

	return leftanswer+rightanswer;
}

int main()
{
	long long int t;
	cin>>t;
	while(t--)
		{
			long long int n,c;
			cin>>n>>c;


				for(int i=0;i<1000000;i++)
				{
					tree[i].sum=0;
					tree[i].lazy=0;
				}
			
			for(int i=0;i<=n;i++)
				a[i]=0;

			build(1,1,n);

			for(int i=1;i<=c;i++)
			{
				long long int p,q,v,x;
				cin>>x>>p>>q;
				if(x==0){
					cin>>v;
					update(1,1,n,v,p,q);
				}
				if(x==1){
				long long int answer=query(1,1,n,p,q);
				cout<<endl;
				cout<<answer<<endl;

				}
			}
		}
}