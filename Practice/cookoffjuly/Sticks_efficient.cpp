#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>
#include <list>
#include <map>
#include <utility>
#include <vector>
#include <set>
#include <string>
#include <queue>
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


//see use of them
// #include <forward_list>
// #include <iomanip>

ll min(ll a, ll b){
    return a<b?a:b;
}

pair<int,int> arr[100100];
map<int,int>::iterator ii;
int sm[100100];

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,K;
        cin>>n>>K;

        int k = n-K;

        map<int,int> mp;
        int x;
        for(int i=0;i<n;i++) {
            cin>>x;
            mp[x]++;
        }

        int m =1;

        for(ii=mp.begin();ii!=mp.end();ii++) {
            if(ii->second>1) {
                arr[m++]=*ii;
            }
        }
        m--;
        int req=0;
        int mxx=0;
        for(int i=1;i<=m;i++) {
            sm[i] = sm[i-1]+arr[i].second;
            if(arr[i].second>1) {
                mxx = max(arr[i].second-1,mxx);
                req+=arr[i].second-1;
            }
        }

        if(req-min(mxx,2)<=k) {
            cout<<-1<<endl;
            continue;
        }

        ll ans = 1ll<<60;
        for(int i=m;i>=1;i--) {
            if(arr[i].second>3) {
                if(arr[i].second-3>k) {
                    ans = min(ans,arr[i].first*1ll*arr[i].first);
                    break;
                }
                k = k-(arr[i].second-3);
                arr[i].second=3;
            }
            if(arr[i].second==3) {
                /*int l=1,r=i;
                while(r-l>1) {
                    int mid = (r+l)/2;
                    if(sm[i-1]-sm[mid-1]-(i-mid)>k) {
                        l = mid;
                    } else {
                        r = mid;
                    }
                }*/
                int l=1,r=i-1;
                while(l<r) {
                    int mid = (r+l)/2;
                    if(sm[i-1]-sm[mid]-(i-mid-1)>k){
                        l = mid+1;
                    } else {
                        r = mid;
                    }
                }
                ans = min(ans,arr[i].first*1ll*arr[l].first);
            } 
            if(arr[i].second>1) {
                

                if(arr[i].second-1>k) {
                    for(int j=i-1;j>=1;j--) {
                        if(arr[j].second-1>k) {
                            ans = min(ans,arr[i].first*1ll*arr[j].first);
                            break;
                        }
                        k-=arr[j].second-1;
                    }
                    break;
                }

                k-= arr[i].second-1;
                arr[i].second=1;

            }
        }

        cout<<ans<<endl;
    }
}