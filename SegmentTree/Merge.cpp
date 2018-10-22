#include <bits/stdc++.h>
#include <iostream>
using namespace std;


void merge(int b[],int l,int mid,int r)
{
	int n1=mid-l+1;
	int n2= r-mid;

	int L[n1+1],R[n2+1];

	for(int i=1;i<=n1;i++)
		L[i]=b[l+i-1];


	for(int j=1;j<=n2;j++)
		R[j]=b[mid+j];


	int i=1,j=1,k=l;

	while(i<=n1 && j<=n2 && k<=r)
	{
		if(L[i]<=R[j])
		{
			b[k]=L[i];
			i++;
			k++;
		}else{
			b[k]=R[j];
			j++;
			k++;
		}
	}

	while(i<=n1 && k<=r)
	{
		b[k]=L[i];
		i++;
		k++;
	}

	while(j<=n2 && k<=r)
	{
		b[k]=R[j];
		j++;
		k++;
	}


}


void mergeSort(int a[],int l,int r)
{
	if(l==r)
	return;
	else
	{
		int mid = (l+r)/2;
		mergeSort(a,l,mid);
		mergeSort(a,mid+1,r);
		merge(a,l,mid,r);
	}
	
}

int main()
{

	int n=10;
	int a[]={0,1,5,4,2,9,3,7,5,6,10};

	mergeSort(a,1,10);

	for(int i=1;i<=10;i++)
		cout<<a[i]<<" ";

}