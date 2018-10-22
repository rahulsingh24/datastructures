#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;

	while(t--) {
		int d;
		cin>>d;

		int tim = d/9;

		if(tim==0) {
			cout<<d+1<<endl;
			// return 0;
		} else {
			cout<<(d%9)+1;
			// for(int i=0;i<tim;i++) cout<<0;
			// 	cout<<endl;
		}
	}
}