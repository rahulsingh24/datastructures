#include <iostream>
using namespace std;

long long int A[1000000];

struct node{
	long long int sum;
	long long int lazy;

	/*node(sum=0,lazy=0)
	{
		this.sum = sum;
		this.lazy = lazy;
	}
*/	/*node()
	{
		sum=0;
		lazy=0;
	}*/
}tree[1000000];

void merge(node &ans,node &left,node &right)
{
	ans.sum = left.sum+right.sum;
	//ans.lazy=left.lazy=right.lazy=0;
}

void build(int i,int start,int end)
{
	if(start==end)
	{
		tree[i].sum = A[start];
	}
	else
	{
		int mid = (start+end)/2;
		build(2*i,start,mid);
		build(2*i+1,mid+1,end);

		merge(tree[i],tree[2*i],tree[2*i+1]);

	}
}

//partial overlapping ki wajah se wo 3rd condition ke andar nhi jata hai aur further update ke lie function call ho jate hai

void updateRange(long long int i,long long int start,long long int end,long long int l,long long int r,long long int val)
{
	// if(start>end || start>r || end <l)
	// 	return;

	if(tree[i].lazy!=0)
	{
		tree[i].sum += (end-start+1)*tree[i].lazy;
		if(start!=end)
		{
			tree[2*i].lazy+=tree[i].lazy;
			tree[2*i+1].lazy+=tree[i].lazy;
		}
		tree[i].lazy = 0;
	}

	if(start>end || start>r || end <l)
		return;

	if(start>=l && end<=r)
	{
		tree[i].sum = (end-start+1)*val+tree[i].sum;
		//tree[i].lazy = val;
		if(start!=end)
		{
			tree[2*i].lazy+=val;
			tree[2*i+1].lazy+=val;
		}
		return;
	}
	int mid = (start+end)/2;
	updateRange(2*i,start,mid,l,r,val);
	updateRange(2*i+1,mid+1,end,l,r,val);
	merge(tree[i],tree[2*i],tree[2*i+1]);

}


long long int query(long long int i,long long int start,long long int end,long long int l,long long int r)
{

	if(start>end || start>r || end <l)
		return 0;

	if(tree[i].lazy!=0)
	{
		tree[i].sum += (end-start+1)*tree[i].lazy;
		if(start!=end)
		{
			tree[2*i].lazy+=tree[i].lazy;
			tree[2*i+1].lazy+=tree[i].lazy;
		}
		tree[i].lazy = 0;
	}


	if(start>=l && end<=r)
	{
		return tree[i].sum;
	}

	int mid = (start+end)/2;
	long long int leftnode = query(2*i,start,mid,l,r);
	long long int rightnode = query(2*i+1,mid+1,end,l,r);
	return (leftnode+rightnode);


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
				A[i]=0;

			build(1,1,n);

			for(int i=1;i<=c;i++)
			{
				long long int p,q,v,x;
				cin>>x>>p>>q;
				if(x==0){
					cin>>v;
					updateRange(1,1,n,p,q,v);
				}
				if(x==1){
				long long int answer=query(1,1,n,p,q);
				cout<<endl;
				cout<<answer<<endl;

				}
			}
		}
}