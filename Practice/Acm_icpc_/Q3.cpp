#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;

	while(t--) {
		int n;
		cin>>n;

		int a[n];
		// unordered_set<int> s;
		for(int i=0;i<n;i++) {
			cin>>a[i];
		}

		if(n==1) {
			cout<<"yes"<<endl;
			continue;
		}

		sort(a,a+n);

		if(n==2) {
			if(a[0]*a[1]==a[0] || a[0]*a[1]==a[1])
			{
				cout<<"yes"<<endl;
				continue;
			}
		}

		if(a[n-1]>1 && a[n-2]>1) {
			cout<<"no"<<endl;
			continue;
		}

		if(a[0]<-1 && a[1]<-1) {
			cout<<"no"<<endl;
			continue;
		}

		
		int pos2=0;
		int neg2=0;
		int neg1=0;
		int pos1=0;
		int zero=0;

		for(int i=0;i<n;i++) {
			if(a[i]==0) zero++;
			if(a[i]==1) pos1++;
			if(a[i]==-1) neg1++;
			if(a[i]<-1) neg2++;
			if(a[i]>1) pos2++;
		}

		if(pos2==0 && neg2==0 && neg1==0 && (zero>0||pos1>0)) {
			cout<<"yes"<<endl;
			continue;
		}

		if(pos2==0 && neg2==0 && (neg1>1 && pos1>0)) {
			cout<<"yes"<<endl;
			continue;
		}

		if(pos2==0 && neg2==0 && (neg1==1)) {
			cout<<"yes"<<endl;
			continue;
		}

		if(pos2==1 && neg2==0 && neg1==0) {
			cout<<"yes"<<endl;
			continue;
		}

		if(neg2==1 && neg1==0 && pos2==0) {
			cout<<"yes"<<endl;
			continue;
		}


		cout<<"no"<<endl;





		/*if(a[n-1]==1) {
			if(a[0]<-1 && a[1]==-1) {
				cout<<"no"<<endl;
				continue;
			} else {
				cout<<"yes"<<endl;
			}

		} else if(a[n-1]>1 && a[n-2]==1) {

		} else if(a[n-1]<0 && n>1) {
			cout<<"no"<<endl;
		} else if(a[n-1]==0) {
			if(a[0]<-1)
		}
*/
	}
}