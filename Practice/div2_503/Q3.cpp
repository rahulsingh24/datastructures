#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define INF 1000000007
#define INFLL 1000000000000000011LL
#define pb(x) push_back(x)
#define mp make_pair
#define fi first
#define se second
#define vi vector
#define gtl(x) getline(cin, (x))
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)((a).size())
#define setv(x,a) memset(x,a,sizeof(x))
#define ull unsigned long long int 

ull PowMod(ull n, ll m)
{
    ull ret = 1;
    ull a = m;
    while (n > 0) {
        if (n & 1) ret = ((ret%INF) * (a%INF)) % INF;
        a = ((a%INF) * (a%INF)) % INF;
        n >>= 1;
    }
    return ret;
}

int gcd(int a, int b) {
            if (a == 0) return b;
            if (b == 0) return a;
            if (a < 0) return gcd(-1 * a, b);
            if (b < 0) return gcd(a, -1 * b);
            if (a > b) return gcd(b, a);
            return gcd(b%a, a);
}


ll binarySearch(ll left, ll right) {
	ll mid;
	while(left<=right) {
		mid = (ll)(left+right)/2;
		// if(can(mid)) {
		// 	left = mid+1;
		// } else right = mid-1;

		// cout<<"left = "<<left<<" right = "<<right<<endl;
	}

	return left-1;
}


int main(){
	int n,m;
	cin>>n>>m;

	int c[n],p[n];
	ll sum=0;
	for(int i=0;i<n;i++) {
		cin>>p[i]>>c[i];
		if(p[i]!=1) {
			sum+=c[i];
		}
	}


	int cnt[m+1];
	ll ans=1e18,now,use;
	for(int i=0;i<n;i++) {
		ll need = i+1;
		priority_queue<pair<ll,ll> > q;

		setv(cnt,0);

		for(int j=0;j<n;j++) {
			if(p[j]!=1)
			q.push(mp(c[j],p[j]));
		}

		now = n,use=sum;
		while(now>need && !q.empty()) {
			ll cost = q.top().first, party=q.top().second;
			q.pop();
			if(cnt[party]==i) continue;
			cnt[party]++;
			use-=cost;
			now--;
		}

		ans = min(ans,use);
	}

	cout<<ans<<endl;
}