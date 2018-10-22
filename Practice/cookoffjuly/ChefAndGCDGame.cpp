#include <bits/stdc++.h>
using namespace std;

#define setv(x,a) memset(x,a,sizeof x);
#define pb push_back

const int maxl = (int)1e6 + 10;

int lp[maxl];
int cnt[maxl];
vector<int> d[maxl];

bool can(int n, int md, const vector<int> &d) {
	int need = md*(n- (int)d.size());
	for(int i =0;i<d.size();i++) {
		if(d[i]<md) need+= (md-d[i]);
		else need-=(d[i]-md)/2;
	}
	return need<=0;
}

int main() {
	lp[1]=1;
	for(int i=2;i<maxl;i++) {
		if(lp[i]>0) continue;
		for(int j=i;j<maxl;j+=i) {
			if(lp[j]==0) lp[j]=i;
		}
	}

	int t;
	cin>>t;

	while(t--) {
		int n;
		cin>>n;

		setv(cnt,0);
		for(int i=1;i<maxl;i++) {
			d[i].clear();
		}
		int p,k;
		for(int i=0;i<n;i++) {
			int x;
			cin>>x;
			while(x>1) {
				p = lp[x];
				k=0;
				while(x%p==0 && x>1) {
					x/=p;
					k++;
				}
				d[p].pb(k);
				cnt[p]+=k;
			}
		}
		int gcd=1,lf,rg, md;
		for(int p=2;p<maxl;++p) {
			if(cnt[p]<n) continue;

			lf = 0, rg = 20;
			while(rg-lf>1) {
				md = (lf+rg)/2;
				if(can(n,md,d[p])) {
					lf = md;
				} else rg = md;
			}

			while(lf--) gcd*=p;
		}

		cout<<gcd<<endl;
	}
}