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

long long modmult(long long a,long long b,long long mod)
{
    if (a == 0 || b < mod / a)
        return (a*b)%mod;
    long long sum;
    sum = 0;
    while(b>0)
    {
        if(b&1)
            sum = (sum + a) % mod;
        a = (2*a) % mod;
        b>>=1;
    }
    return sum;
}

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




int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    pair<ll,ll> p[n];

    ll x,y;
    for(int i=0;i<n;i++) {
        cin>>x>>y;
        p[i].first = x;
        p[i].second = y;
    }

    sort(p,p+n);

    vector<ll> v;

     y = p[0].first;

     // int prim=1;
    for(ll i=2;i*i<=y;i++) {
        if(y%i==0) {
            // prim=0;
            v.pb(i);
           while(y%i==0) {
            y = y/i;
           }
        }
    }
    if(y>1) v.pb(y);

    y = p[0].second;

    // prim=1;
    for(int i=2;i*i<=y;i++) {
        if(y%i==0) {
            // prim=0;
            v.pb(i);
           while(y%i==0) {
            y = y/i;
           }
        }
    }

    if(y>1) v.pb(y);

    sort(v.begin(),v.end());

    vector<ll>::iterator it;
  it = unique (v.begin(), v.end());  
  v.resize(distance(v.begin(),it) );

    // for(int i=0;i<v.size();i++) {
    //     cout<<v[i]<<" ";
    // }
    // cout<<endl;
    int i=0;
    int check;
/*
    for(;i<v.size();i++) {
        if(v[i]!=1) break;
    }*/

    for(;i<v.size();i++) {
        check=0;
        for(int j=0;j<n;j++) {
            if(p[j].first%v[i]!=0 && p[j].second%v[i]!=0) {
                // cout<<"dhanraj"<<endl;
                check=1;
                break;
               }  
        }
        // cout<<"i = "<<i<<endl;
        if(check==0) {
            break;
        }
    }
    // cout<<"i2 = "<<i<<endl;
    if(i<v.size())
    cout<<v[i]<<endl;
    else cout<<-1<<endl;
    
}