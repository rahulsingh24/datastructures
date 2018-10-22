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

int main() {
	ll n,h,a,b,k;
	cin>>n>>h>>a>>b>>k;

	ll ta,ha,tb,hb,ans;
	while(k--) {
		cin>>ta>>ha>>tb>>hb;
		ans=abs(ta-tb);
		if(ans==0) {
			ans = abs(ha-hb);
			cout<<ans<<endl;
			continue;
		} else {
			if(ha>b && hb>b) {
				ans+= abs(ha-b)+abs(hb-b);
			} else if(ha<a && hb<a) {
				ans+= abs(ha-a)+abs(hb-a);
			} else {
				ans+= abs(ha-hb);
			}
			cout<<ans<<endl;
		}
	}
}